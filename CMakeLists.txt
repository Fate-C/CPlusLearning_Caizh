cmake_minimum_required(VERSION 3.10)

project(CPlusLearning)

find_package(Threads REQUIRED) 

include_directories(Include)

add_executable(demo 
    Source/main.cpp 
    Source/LeetCodeSolution.cpp
    Source/mathFcn.cpp
    Source/testFcns.cpp
    Source/nQueen.cpp
    Source/KMP.cpp
)

add_executable(test
    Source/tempTest.cpp
)

target_link_libraries(demo
    Threads::Threads
)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)
