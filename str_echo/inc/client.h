#ifndef CLIENT_H
#define CLIENT_H
#include "socket.h"
void str_cli(FILE *fp, fd sock_fd); // 从标准流写入send_line数组，从网络读入recv_line数组

#endif