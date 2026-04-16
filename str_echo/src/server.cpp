
#include "server.h"

// 使用通配地址

// 绑定端口，监听，然后accept
// 比如 char * 是一个指向字符的指针，在c风格中他代表一个字符串
// char ** 则是指向字符指针的指针，它指向一个字符串数组
// argv[i]得到的是一个完整的字符串比如hello而不是h

// fork后子进程和父进程会分享文件描述符的引用计数
// 也就是说，socket不会增加，但引用增加，如果要让listen完全停止工作，所有的listen副本都要关闭
// 因为子进程不需要监听，但是父进程需要

// 在遇到if-fork块的时候，fork返回的pid肯定大于0，它会跳入if但父进程不会
// 父进程继续走下去然后返回accept阻塞
// listen只负责启动和激活，不需要进入while循环
int main(int argc, char **argv) // 两个*代表指向指针的指针
{
    // 创建套接字
    int listen_fd, conn_fd;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    // 创建套接字地址结构体并绑定对应参数
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    pid_t childpid;

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERV_PORT);

    // bind把套接字和地址结构体绑定
    bind(listen_fd, (SA *)&serv_addr, sizeof(serv_addr));
    // 监听
    // 第二个参数是最大队列长度
    // listen_fd = listen(listen_fd, listen_backlog);
    if (listen(listen_fd, listen_backlog) == 0)
    {
        printf("listening...\n");
    }

    // 给connfd赋值为accept函数从对应地址拿到的
    while (true)
    {
        conn_fd = accept(listen_fd, (SA *)&cli_addr, &cli_len);
        if ((childpid = fork()) == 0)
        {
            close(listen_fd);
            str_echo(conn_fd);
            exit(0);
        }
        close(conn_fd);
    }
}

void str_echo(fd sockfd)
{
    ssize_t n; // 用来规定写入多少的值
    // read了多少就写入多少

    char buf[MAXLINE];
again:
    while ((n = read(sockfd, buf, MAXLINE)) > 0)
    {
        // write(sockfd, buf, n);我们考虑不读n而是用strlen拿到长度
        write(sockfd, buf, strlen(buf));
    }
    if (n < 0 && errno == EINTR) // EINTR代表执行期间被外部信号中断
    // 这通常不是什么很要紧的错误
    {
        goto again;
    }
    else if (n < 0)
    {
        printf("str_echo: read error\n");
        exit(1);
    }
}