cmake_minimum_required(VERSION 3.28.3)
project(str_echo)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
set(SRCPATH ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/inc)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)# 这仅仅是规定了一个变量，没有产生任何影响

include_directories(${INCLUDE_DIRECTORIES})

# add_executable(${PROJECT_NAME} ${SRC})  #如果这么写会被连接起来而且里面会有两个主函数
add_executable(server_app ${SRCPATH}/server.cpp)

add_executable(client_app ${SRCPATH}/client.cpp)

# target_include_directories(${PROJECT_NAME} public ${INCLUDE_DIRECTORIES})# 这句必须加在add_executable之后，此时target才存在
# target_include_directories(${PROJECT_NAME} private ${PROJECT_SOURCE_DIR}/bin)