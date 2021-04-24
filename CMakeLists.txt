cmake_minimum_required(VERSION 3.17)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 20)

add_executable(Data_Structure main.cpp List/List.h List/SinglyLinkedList.h List/SinglyLinkedList.cpp Stack/Stack.h Stack/Stack.cpp Queue/Queue.h Queue/Queue.cpp List/DoublyLinkedList.h List/DoublyLinkedList.cpp trees/Heap/Heap.h trees/Heap/Heap.cpp)
add_executable(Heap heap_main.cpp trees/Heap/Heap.h trees/Heap/Heap.cpp)
add_executable(Queue queue_main.cpp Queue/Queue.h Queue/Queue.cpp List/List.h List/SinglyLinkedList.h List/SinglyLinkedList.cpp)
add_executable(Stack stack_main.cpp Stack/Stack.h Stack/Stack.cpp List/List.h List/SinglyLinkedList.h List/SinglyLinkedList.cpp)