src文件夹来存放源文件
inc文件夹来写三个文件，socket，server_socket,client_socket来实现socket的继承和封装
build文件夹来构建
CMakeLists.txt

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
