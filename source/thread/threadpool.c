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
