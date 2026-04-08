cmake_minimum_required(VERSION 3.28.3)
project(start)
set(INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/inc)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# link_directories(${PROJECT_NAME}/ep1)

#如果要递归找文件不需要这个子目录设置
# add_subdirectory(${PROJECT_SOURCE_DIR}/ep1)

# set(SRC_PATH ${PROJECT_SOURCE_DIR}/src)
# file(GLOB src ${SRC_PATH}/*.cpp)

# 递归找到所有递归的源文件
file(GLOB_RECURSE src_files "*/src/*.cpp" "src/*.cpp")

file(GLOB_RECURSE include_dirs "*/inc" "inc")
foreach(dir ${include_dirs})
    if(IS_DIRECTORY ${dir})
        include_directories(${dir})
    endif()
endforeach()


add_executable(${PROJECT_NAME} ${src_files})