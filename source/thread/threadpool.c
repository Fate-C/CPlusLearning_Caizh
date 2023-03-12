#include <stdio.h>
#include <pthread.h>

#include "thread/threadpool.h"

// 这个线程池是通过C语言来实现的， 后续可以自行修改为C++

// 任务结构体
typedef struct Task
{
    void (*function)(void* arg);
    void* arg;
}Task;

// 线程池结构体
struct ThreadPool
{
    //任务队列
    Task* taskQ;            //任务队列数组
    int queueCapacity;      //容量
    int queueSize;          //当前任务个数
    int queueFront;         //队头 -> 用于取数据
    int queueRear;          //队尾 -> 放数据

    pthread_t managerID;        //管理者线程ID
    pthread_t *threadIDs;       //工作线程ID
    int minNum;                 //最小线程数量
    int maxNum;                 //最大线程数量
    int busyNum;                //在忙线程数量
    int liveNum;                //活着的线程数量
    int exitNum;                //要销毁的线程数量
    pthread_mutex_t mutexPool;  //锁整个线程池
    pthread_mutex_t mutexBusy;  //锁住busyNum这个变量
    pthread_cond_t notFull;     //任务队列是否满了
    pthread_cond_t notEmpty;    //任务队列是否空了

    int shutdown;               //是否要销毁线程池，为1销毁，为0不销毁
};


ThreadPool* threadPoolCreate (int min, int max, int queueSize)
{
    ThreadPool* pool = (ThreadPool*)malloc(sizeof(ThreadPool));

    do
    {
        if (pool == NULL)
        {
            printf("Create the pool fail...\n");
            break;
        }
        
        pool->threadIDs = (pthread_t*)malloc(sizeof(pthread_t) * max);
        if (pool->threadIDs == NULL)
        {
            printf("Malloc threadIDs fail...\n");
            break;;
        }

        memset(pool->threadIDs, 0, sizeof(pthread_t) * max);

        pool->minNum = min;
        pool->maxNum = max;
        pool->busyNum = 0;
        pool->liveNum = min;

        if (pthread_mutex_init(&pool->mutexPool, NULL) != 0 ||
            pthread_mutex_init(&pool->mutexBusy, NULL) != 0 ||
            pthread_cond_init(&pool->notEmpty, NULL) != 0 ||
            pthread_cond_init(&pool->notFull, NULL) != 0)
        {
            printf("mutex or cond initialize fail.../n");
            break;;
        }

        //任务队列
        pool->taskQ = (Task*)malloc(sizeof(Task) * queueSize);
        pool->queueCapacity = queueSize;
        pool->queueSize = 0;
        pool->queueFront = 0;
        pool->queueRear = 0;
        
        pool->shutdown = 0;

        //创建管理者线程
        pthread_create(&pool->managerID, NULL, manager, pool);
        for (int i = 0; i < min; i++)
        {
            pthread_create(&pool->threadIDs[i], NULL, worker, pool);
        }

        return pool;
    } while (0);
    
    //释放内存
    if (pool && pool->taskQ)
    {
        free(pool->taskQ);
    }
    if (pool && pool->threadIDs)
    {
        free(pool->threadIDs);
    }
    if (pool)
    {
        free(pool);
    }

    return NULL;
}

int threadPoolDestroy(ThreadPool *pool)
{
    //判断pool是否为空
    if (pool == NULL)
    {
        return -1;
    }

    //关闭线程池
    pool->shutdown = 1;
    //阻塞管理者线程并回收
    pthread_join(pool->managerID, NULL);
    //唤醒阻塞的消费者线程
    for (int i = 0; i < pool->liveNum; i++)
    {
        pthread_cond_signal(&pool->notEmpty);
    }

    //释放堆内存
    if (pool->taskQ)
    {
        free(pool->taskQ);
    }
    if (pool->threadIDs)
    {
        free(pool->threadIDs);
    }
    //释放 mutex 和 cond
    pthread_mutex_destroy(&pool->mutexPool);
    pthread_mutex_destroy(&pool->mutexBusy);
    pthread_cond_destroy(&pool->notEmpty);
    pthread_cond_destroy(&pool->notFull);

    free(pool);
    pool = NULL;

    return 0;
}

void threadPoolAdd (ThreadPool* pool, void(*func)(void*), void* arg)
{
    pthread_mutex_lock(&pool->mutexPool);
    while (pool->queueSize == pool->queueCapacity && !pool->shutdown)
    {
        //如果任务队列满了，则阻塞，等待唤醒
        pthread_cond_wait(&pool->notFull, &pool->mutexPool);
    }

    if (pool->shutdown)
    {
        pthread_mutex_unlock(&pool->mutexPool);
        return;
    }

    //添加任务
    pool->taskQ[pool->queueRear].function = func;
    pool->taskQ[pool->queueRear].arg = arg;
    pool->queueRear = (pool->queueRear + 1) % pool->queueCapacity;
    pool->queueSize++;

    //生产者生产了一个任务，则唤醒消费者处理任务
    pthread_cond_signal(&pool->notEmpty);
    
    pthread_mutex_unlock(&pool->mutexPool);
}

int threadPoolBusyNum (ThreadPool* pool)
{
    //在读取的时候加上互斥锁是为了防止其他线程对该内存进行读写，导致读出来的数据错误
    pthread_mutex_lock(&pool->mutexBusy);
    int busyNum = pool->busyNum;
    pthread_mutex_unlock(&pool->mutexBusy);
    return busyNum;
}

int threadPoolAliveNum (ThreadPool* pool)
{
    pthread_mutex_lock(&pool->mutexPool);
    int liveNum = pool->liveNum;
    pthread_mutex_unlock(&pool->mutexPool);
    return liveNum;
}

void* worker(void* arg)
{
    ThreadPool* pool = (ThreadPool*)arg;

    while(1)
    {
        pthread_mutex_lock(&pool->mutexPool);
        //当前任务队列为空
        while (pool->queueSize == 0 && pool->shutdown != 1)
        {
            //阻塞工作线程
            pthread_cond_wait(&pool->notEmpty, &pool->mutexPool);

            //被唤醒后判断是否需要退出线程
            if (pool->exitNum > 0)
            {
                pool->exitNum--;
                //单次manager退出数量由 EXIT_NUM_ONCE 决定，故可能在循环中导致线程数量少于 minNum
                if (pool->liveNum > pool->minNum)
                {
                    pool->liveNum--;
                    //在退出线程前需要解开之前上的锁
                    pthread_mutex_unlock(&pool->mutexPool);
                    threadExit(pool);                    
                }
            }
        }

        //判断线程池是否关闭，关闭则退出线程
        if (pool->shutdown)
        {
            pthread_mutex_unlock(&pool->mutexPool);
            threadExit(pool);
        }

        //从任务队列中取出一个任务
        Task* task;
        task->function = pool->taskQ[pool->queueFront].function;
        task->arg = pool->taskQ[pool->queueFront].arg;
        //移动头节点，维持环形队列，用数组完成循环队列
        pool->queueFront = (pool->queueFront + 1) % pool->queueCapacity;

        //取出任务，则队列不为满，则唤醒生产者
        pthread_cond_signal(&pool->notFull);
        //解锁
        pthread_mutex_unlock(&pool->mutexPool);

        //忙的线程+1，需要互斥锁
        printf("thread %ld start working...\n");
        pthread_mutex_lock(&pool->mutexBusy);
        pool->busyNum++;
        pthread_mutex_lock(&pool->mutexBusy);

        //调用任务函数
        task->function(task->arg);
        //假设task->arg是分配的一块堆内存，需要释放掉
        free(task->arg);
        task->arg = NULL;

        //忙的线程-1，需要互斥锁
        printf("thread %ld end working...\n");
        pthread_mutex_lock(&pool->mutexBusy);
        pool->busyNum--;
        pthread_mutex_lock(&pool->mutexBusy);
    }
}


void* manager (void* arg)
{
    //转换arg
    ThreadPool* pool = (ThreadPool*)arg;
    while (!pool->shutdown)
    {
        //每隔3s检测一次
        sleep(3);

        //取出线程池里面的任务数量和存活的线程个数
        pthread_mutex_lock(&pool->mutexPool);
        int queueSize = pool->queueSize;
        int liveNum = pool->liveNum;
        pthread_mutex_unlock(&pool->mutexPool);

        //取得线程池内忙的线程个数
        pthread_mutex_lock(&pool->mutexBusy);
        int busyNum = pool->busyNum;
        pthread_mutex_unlock(&pool->mutexBusy);

        //添加线程
        //添加的规则：任务数量 > 线程存活数量 && 线程存活数量 < 最大线程数量
        if (queueSize > liveNum && liveNum < pool->maxNum)
        {
            //记录有多少线程被创建，单次最大创建数量为 NUMBER 
            int counter = 0;
            pthread_mutex_lock(&pool->mutexPool);
            for (int i = 0; i < pool->maxNum && counter < CREATE_NUM_ONECE && liveNum < pool->maxNum; i++)
            {
                //如果该空余线程可用，则创建线程
                if (pool->threadIDs[i] == 0)
                {
                    pthread_create(&pool->threadIDs[i], NULL, worker, pool);
                    counter++;
                    pool->liveNum++;
                }
            }
            pthread_mutex_unlock(&pool->mutexPool);
        }

        //销毁线程
        //销毁的规则：忙的线程*2 < 存活的线程 && 存活线程 > 最小线程数
        //此处直接使用在添加线程前读出的数据，可能具有一定延迟，但并不碍事
        if (busyNum * 2 < liveNum && liveNum > pool->minNum)
        {
            pthread_mutex_lock(&pool->mutexPool);
            pool->exitNum = EXIT_NUM_ONECE;
            pthread_mutex_unlock(&pool->mutexPool);

            //唤醒活着的且阻塞的线程，令该线程退出
            for (int i = 0; i < EXIT_NUM_ONECE; i++)
            {
                pthread_cond_signal(&pool->notEmpty);
            }
        }
    }
}


void threadExit(ThreadPool* pool)
{
    pthread_t tid = pthread_self();
    for (int i = 0; i < pool->maxNum; i++)
    {
        if (pool->threadIDs[i] == tid)
        {
            pool->threadIDs[i] = 0;
            printf("threadExit() called, %ld exiting...", tid);
            break;
        }
    }
    pthread_exit(NULL);
}
