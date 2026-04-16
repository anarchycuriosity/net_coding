src文件夹来存放源文件
inc文件夹来写三个文件，socket，server_socket,client_socket来实现socket的继承和封装
build文件夹来构建
CMakeLists.txt

ep1的内容包括

## 1.2 一个简单的时间获取客户程序

1创建tcp套接字
2指定服务器的ip地址和端口bind
3connect函数建立和服务器的连接,参数1是fd2是套接字地址结构(addr)3是地址结构的长度
4终止

## 1.3 协议无关性的改编

## 1.4 错误处理:包裹函数

err_sys函数输出报错信息
定义包裹函数,检查返回值,约定wrapper function是实际函数名的大写比如Socket()

## 1.5 时间获取服务器程序

1创建tcp套接字
2绑定服务器的端口到套接字
3把套接字转化为监听套接字
4接受用户连接,发送应答
5终止
listen(listenfd,LISTENQ)函数把该套接字转化为一个监听套接字,而不是仅仅创建一个普通的socket,LISTENQ是再unp.h中定义的最大客户连接数.准备过程包括这三个函数的调用socket biind listen准备监听描述符listen descriptor也就是listenfd

snprintf()的第二个参数要求指定目的缓冲区的大小来确保缓冲区不会溢出,替换sprint

同理类似的还应该有fgets替换gets
strncat替换strcat
strncpy替换strcpy
更好的替代是strlcpy和strlcat因为还确保结果是正确终止的字符串

关于argc和argv
前者告诉你一共输入了几个单词包括程序本身
后者是一个字符串数组储存了具体的单词
比如time_client运行后
argc是1，argv[0]是./time_client
如果为了获取特定服务器的时间
输入./time_client 126.0.0.1
argc是2，argv[1]是127.0.0.1

socket(AF类型，服务质量：比如流式套接字sock_stream对应tcp协议，protocol让系统自己选择协议)

tcp协议是在ip协议(IPprotocol)之上的，因为仅仅是ip协议是不可靠的，需要再套一层协议

inet_pton：internet presentation to numeric
把人可读的文本(presentation)转机器处理的数字二进制

后面会介绍用名字代替数字给出ip地址

IP协议解决网络层送不送的到的问题，TCP协议解决送的对不对的问题

## 1.8 OSI模型opening systems interconnection

其实就是七层模型,如果把应用层额外拆开的话
TCP和UDP协议就对应传输层,更往下的IPv4和IPv对应网络层
更往下的数据链路层和物理层我们认为是设备驱动程序和硬件,通常不必关心

如果不讨论各种早期标准的各自特性,我们简单称呼由austin公共标准修订组主持修订的unix标准为posix规范

1.10 Unix标准
ISO internet standardization organization互联网标准化组织(大概)
POSIX,可移植操作系统接口portable operating system interface
这是一系列标准而非单个

// 假设我们要为一个整数数组申请空间

```c++
// 假设我们要为一个整数数组申请空间
int *ptr;
ptr = (int *) std::malloc(5 * sizeof(int));
//因为malloc在堆上分配内存返回的是空指针,所以需要强制转换类型否则无法直接解引用
//我们常常用new
type_T是占位符
```

mv {a,b,c} d并不需要-r
因为只需要改动映射表即可，与rm和cp不一样

src文件夹来存放源文件
inc文件夹来写三个文件，socket，server_socket,client_socket来实现socket的继承和封装
build文件夹来构建
CMakeLists.txt

ep1的内容包括

## 1.2 一个简单的时间获取客户程序

1创建tcp套接字
2指定服务器的ip地址和端口bind
3connect函数建立和服务器的连接,参数1是fd2是套接字地址结构(addr)3是地址结构的长度
4终止

## 1.3 协议无关性的改编

## 1.4 错误处理:包裹函数

err_sys函数输出报错信息
定义包裹函数,检查返回值,约定wrapper function是实际函数名的大写比如Socket()

## 1.5 时间获取服务器程序

1创建tcp套接字
2绑定服务器的端口到套接字
3把套接字转化为监听套接字
4接受用户连接,发送应答
5终止
listen(listenfd,LISTENQ)函数把该套接字转化为一个监听套接字,而不是仅仅创建一个普通的socket,LISTENQ是再unp.h中定义的最大客户连接数.准备过程包括这三个函数的调用socket bind listen准备监听描述符listen descriptor也就是listenfd

snprintf()的第二个参数要求指定目的缓冲区的大小来确保缓冲区不会溢出,替换sprint

同理类似的还应该有fgets替换gets
strncat替换strcat
strncpy替换strcpy
更好的替代是strlcpy和strlcat因为还确保结果是正确终止的字符串

关于argc和argv
前者告诉你一共输入了几个单词包括程序本身
后者是一个字符串数组储存了具体的单词
比如time_client运行后
argc是1，argv[0]是./time_client
如果为了获取特定服务器的时间
输入./time_client 126.0.0.1
argc是2，argv[1]是127.0.0.1

socket(AF类型，服务质量：比如流式套接字sock_stream对应tcp协议，protocol让系统自己选择协议)

tcp协议是在ip协议(IPprotocol)之上的，因为仅仅是ip协议是不可靠的，需要再套一层协议

inet_pton：internet presentation to numeric
把人可读的文本(presentation)转机器处理的数字二进制

后面会介绍用名字代替数字给出ip地址

IP协议解决网络层送不送的到的问题，TCP协议解决送的对不对的问题

## 1.8 OSI模型opening systems interconnection

其实就是七层模型,如果把应用层额外拆开的话
TCP和UDP协议就对应传输层,更往下的IPv4和IPv对应网络层
更往下的数据链路层和物理层我们认为是设备驱动程序和硬件,通常不必关心

如果不讨论各种早期标准的各自特性,我们简单称呼由austin公共标准修订组主持修订的unix标准为posix规范

1.10 Unix标准
ISO internet standardization organization互联网标准化组织(大概)
POSIX,可移植操作系统接口portable operating system interface
这是一系列标准而非单个

// 假设我们要为一个整数数组申请空间

```c++
// 假设我们要为一个整数数组申请空间
int *ptr;
ptr = (int *) std::malloc(5 * sizeof(int));
//因为malloc在堆上分配内存返回的是空指针,所以需要强制转换类型否则无法直接解引用
//我们常常用new
type_T是占位符
```

如果子文件夹的插件不生效
ctrl + shift + p输入cmake config让插件配置即可f5一键编译
你甚至可以不需要.vscode文件夹,因为cmake tools的插件驱动优于手动配置

第一题
unp仓库如何测试？
对于13端口只有root用户才能调用，所以我们要写sudo
先sudo运行服务器，然后新建终端运行客户端
报错信息：usage: a.out <IPaddress>
客户端必须指定地址才能调用服务

如何获得网络拓扑的信息
netstat -r
或者
netstat -rn

1.2尝试修改cli程序的ip地址
比如改为128.1.1.1
cli运行成功但是什么都不会返回，因为对应接口根本没有套接
其实srv写了addr_any

1.3尝试改cli程序的AF参数为9999会输出
socket error: Address family not supported by protocol

err_sys封装的strerror只是得到了简明信息，从errno中
如果我想查err_sys的实现文件而不是只能看到.h呢
grep -rn "err_sys" .
n参数可以让我们拿到行号，然后利用vsc编辑器的ctrl + g实现快速跳转
