#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <arpa/inet.h>

int main()
{
    //creat a socket for communication
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1)
    {
        perror("socket");
        return -1;
    }

    //connect the server
    sockaddr_in saddr;
    saddr.sin_family = AF_INET;         //指定协议族为 ipv4
    saddr.sin_port = htons(9999);       //绑定端口，需要把端口9999从主机字节序转换为网络字节序，且为unsigned short，所以使用htons函数
    inet_pton(AF_INET, "172.18.49.108", &saddr.sin_addr.s_addr);

    int ret = connect(fd, (sockaddr*)&saddr, sizeof(saddr));
    if(ret == -1)
    {
        perror("connect");
        return -1;
    }

    //communication
    int number = 0;
    while(1)
    {
        //send the data
        char buff[1024];
        sprintf(buff, "hello, world! , %d\n", number++);
        send(fd, buff, strlen(buff) + 1, 0);
        //receive the data
        
        memset(buff, 0, sizeof(buff));
        int len = recv(fd, buff, sizeof(buff), 0);
        if(len > 0)
        {
            printf("Server:%s\n", buff);
        }
        else if(len == 0)
        {
            printf("服务器端断开连接......\n");
            break;
        }
        else
        {
            perror("recv");
            return -1;
        }
        sleep(1);
    }

    //close the socket
    close(fd);
    
    return 0;
}