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


ThreadPool *threadPoolCreate(int min, int max, int queueSize)
{
    ThreadPool* pool = (ThreadPool*)malloc(sizeof(ThreadPool));

    do
    {
        if(pool == NULL)
        {
            printf("Create the pool fail...\n");
            break;
        }
        
        pool->threadIDs = (pthread_t*)malloc(sizeof(pthread_t) * max);
        if(pool->threadIDs == NULL)
        {
            printf("Malloc threadIDs fail...\n");
            break;;
        }

        memset(pool->threadIDs, 0, sizeof(pthread_t) * max);

        pool->minNum = min;
        pool->maxNum = max;
        pool->busyNum = 0;
        pool->liveNum = min;

        if( pthread_mutex_init(&pool->mutexPool, NULL) != 0 ||
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
        pthread_create(&pool->managerID, NULL, manager, NULL);
        for(int i = 0; i < min; i++)
        {
            pthread_create(&pool->threadIDs[i], NULL, worker, pool);
        }

        return pool;
    } while (0);
    
    //释放内存
    if(pool && pool->taskQ)
    {
        free(pool->taskQ);
    }
    if(pool && pool->threadIDs)
    {
        free(pool->threadIDs);
    }
    if(pool)
    {
        free(pool);
    }

    return NULL;
}


void* worker(void* arg)
{
    ThreadPool* pool = (ThreadPool*)arg;

    while(1)
    {
        pthread_mutex_lock(&pool->mutexPool);
        //当前任务队列为空
        while(pool->queueSize == 0 && pool->shutdown != 1)
        {
            //阻塞工作线程
            pthread_cond_wait(&pool->notEmpty, &pool->mutexPool);
        }

        //判断线程池是否关闭，关闭则退出线程
        if(pool->shutdown)
        {
            pthread_mutex_unlock(&pool->mutexPool);
            pthread_exit(NULL);
        }
        //从任务队列中取出一个任务
        Task* task;
        task->function = pool->taskQ[pool->queueFront].function;
        task->arg = pool->taskQ[pool->queueFront].arg;
        //移动头节点，维持环形队列，用数组完成循环队列
        pool->queueFront = (pool->queueFront + 1) % pool->queueCapacity;
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