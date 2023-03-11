#ifndef THREAD_POOL
#define THREAD_POLL

#define CREATE_NUM_ONECE 2
#define EXIT_NUM_ONECE 2
typedef struct ThreadPool ThreadPool;

//创建线程池并初始化
ThreadPool* threadPoolCreate (int min, int max, int queueSize);

//销毁线程池


//往线程池里面添加任务
void threadPoolAdd (ThreadPool* pool, void(*func)(void*), void* arg);

//获取线程池中工作线程的个数


//获取线程池中存活线程的个数


//任务处理函数
void* worker (void* arg);
void* manager (void* arg);
void threadExit (ThreadPool* pool);
#endif