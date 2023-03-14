#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


#include "thread/threadpool.h"

void taskFcn (void *arg)
{
    int num = *(int*)arg;
    printf("Thread %ld is working, number = %d\n", pthread_self(), num);
    sleep(1);
}


int main ()
{
    //创建线程池
    ThreadPool *pool = threadPoolCreate(3, 10, 50);
    printf("thread pool create successfully...\n");
    for (int i = 0; i < 100; i++)
    {
        printf("number = %d", i);
        int *num = (int*)malloc(sizeof(int));
        *num = i + 100;
        threadPoolAdd(pool, taskFcn, num);
    }

    sleep(30);
    threadPoolDestroy(pool);

    return 0;
}

