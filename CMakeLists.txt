cmake_minimum_required(VERSION 3.17)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 20)

add_executable(Data_Structure main.cpp List/List.h List/SinglyLinkedList.h List/SinglyLinkedList.cpp Stack/Stack.h Stack/Stack.cpp)