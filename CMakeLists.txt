cmake_minimum_required(VERSION 3.10)

project(CPlusLearning)

find_package(Threads REQUIRED) 

include_directories(include)

add_executable(demo 
    source/main.cpp 
    source/LeetCodeSolution.cpp
    source/mathFcn.cpp
    source/testFcns.cpp
    source/nQueen.cpp
    source/KMP.cpp
)


add_executable(Server
    source/socket/ServerMultiThread.cpp
)
add_executable(Client
    source/socket/Client.cpp
)

add_executable(testThreadPool
    source/testThreadPool.c
    source/thread/threadpool.c
)

target_link_libraries(demo
    Threads::Threads
)

target_link_libraries(Server
    pthread
)

target_link_libraries(testThreadPool
    pthread
)


set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)