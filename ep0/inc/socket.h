#include <sys/socket.h> //socket的创建，connet和bind listen等函数都和这有关
#include <netinet/in.h> //sockaddr_in结构体存放addr
#include <arpa/inet.h>  //地址的转化
#include <unistd.h>     //uinx标准头文件，这里用来管理FD
// 比如close函数
#include <iostream>
#include <cstring> //cpp输入流和strerror
