#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <pthread.h>
#include <arpa/inet.h>

//定义结构体用于将sockaddr_in和fd进行绑定
struct sockInfo
{
    sockaddr_in addr;
    socklen_t fd;
};
sockInfo infos[64];                    //预定义客户端信息数组

void* working(void* arg);

int main()
{
    //creat a socket for listen
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1)
    {
        perror("socket");
        return -1;
    }

    //bind local ip and port
    sockaddr_in saddr;
    saddr.sin_family = AF_INET;         //指定协议族为 ipv4
    saddr.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY 的实际值表示0，0.0.0.0，代表会自动读取系统的ip地址
    saddr.sin_port = htons(9999);       //绑定端口，需要把端口9999从主机字节序转换为网络字节序，且为unsigned short，所以使用htons函数
    int ret = bind(fd, (sockaddr*)&saddr, sizeof(saddr));
    if(ret == -1)
    {
        perror("bind");
        return -1;
    }

    //listen the requires from clients
    ret = listen(fd, 128);
    if(ret == -1)
    {
        perror("listen");
        return -1;
    }
    //initialize the sockInfo vector
    int lenInfo = sizeof(infos) / sizeof(sockInfo);
    for(int i = 0; i < lenInfo; i++)
    {
        memset(&infos[i], 0, sizeof(sockInfo));
        infos[i].fd = -1;
    }

    //wait for client connection
    socklen_t addrlen = sizeof(sockaddr_in);
    while(1)
    {
        sockInfo* sockPtr;
        //寻找可用的 sockInfo 结构体
        for(int i = 0; i < lenInfo; i++)
        {
            if(infos[i].fd == -1)
            {
                sockPtr = &infos[i];
                break;
            }
        }
        //接收新客户端请求
        int cfd = accept(fd, (sockaddr*)&sockPtr->addr, &addrlen);
        if(cfd == -1)
        {
            perror("accept");
            return -1;
        }
        sockPtr->fd = cfd;
        //创建新线程，用来处理新客户端，采用的是C语言的 pthread.h 库
        pthread_t threadId;
        pthread_create(&threadId, NULL, working, sockPtr);
        pthread_detach(threadId);
    }

    return 0;
}

void* working(void* arg)
{
    sockInfo* sockPtr = (sockInfo*)arg;
    //accept successfully, print the ip address and port information of client
    char ip[32];
    printf("客户端的IP:%s, 端口:%d\n", inet_ntop(AF_INET, &sockPtr->addr.sin_addr.s_addr, ip, sizeof(ip)), ntohs(sockPtr->addr.sin_port));

    //communication
    while(1)
    {
        //receive the data
        char buff[1024];
        int len = recv(sockPtr->fd, buff, sizeof(buff), 0);
        if(len > 0)
        {
            printf("Client:%s\n", buff);
            send(sockPtr->fd, buff, len, 0);
        }
        else if(len == 0)
        {
            printf("客户端断开连接......\n");
            break;
        }
        else
        {
            perror("recv");
            break;
        }
    }

    //close the socket
    close(sockPtr->fd);
    sockPtr->fd = -1;

    return 0;
}