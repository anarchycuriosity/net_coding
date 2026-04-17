#include "client.h"
void str_cli(FILE *fp, fd sock_fd)
{
    // fp可以指定为stdin标准输入,也就是键盘
    char sendline[MAXLINE], resvline[MAXLINE];
    // 先写sendline
    while (fgets(sendline, MAXLINE, stdin))
    {
        write(sock_fd, sendline, strlen(sendline));
        ssize_t n;
        if ((n = read(sock_fd, resvline, MAXLINE)) == 0)
        {
            // 如果没有读到，说明服务端定位错误
            printf("str_cli: server terminated prematurely\n");
            exit(1);
        }
        // 如果不显式指定终止符的话会出现乱码和神秘换行，因为他会一直读直到边界，我们要手动指定边界
        resvline[n] = '\0';
        fputs(resvline, stdout);
    }

    // 读取resvline
}
int main(int argc, char **argv)
{
    // 创建套接字，拿到ip地址
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    // sin地址和端口
    if (argc != 2)
    {
        printf("usage: tcpcli <IPaddress>\n");
        exit(1);
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    // connect
    connect(sockfd, (SA *)&server_addr, sizeof(server_addr));
    str_cli(stdin, sockfd);
}