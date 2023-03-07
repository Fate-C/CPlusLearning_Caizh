#include <iostream>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
//包含arpa/inet.h，则不需要再include sys/socket.h了

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

    //block and wait for client connection
    sockaddr_in caddr;
    socklen_t addrlen = sizeof(caddr);
    int cfd = accept(fd, (sockaddr*)&caddr, &addrlen);
    if(cfd == -1)
    {
        perror("accept");
        return -1;
    }

    //accept successfully, print the ip address and port information of client
    char ip[32];
    printf("客户端的IP:%s, 端口:%d\n", inet_ntop(AF_INET, &caddr.sin_addr.s_addr, ip, sizeof(ip)), ntohs(caddr.sin_port));

    //communication
    while(1)
    {
        //receive the data
        char buff[1024];
        int len = recv(cfd, buff, sizeof(buff), 0);
        if(len > 0)
        {
            printf("Client:%s\n", buff);
            send(cfd, buff, len, 0);
        }
        else if(len == 0)
        {
            printf("客户端断开连接......\n");
            break;
        }
        else
        {
            perror("recv");
            return -1;
        }
    }

    //close the socket
    close(fd);
    close(cfd);

    return 0;
}