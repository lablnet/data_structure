cmake_minimum_required(VERSION 3.16.3)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 20)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# we cannot analyse results without gcov
find_program(GCOV_PATH gcov)
if(NOT GCOV_PATH)
    message(FATAL_ERROR "Code coverage analysis requires gcov!")
endif()

enable_testing()
add_subdirectory(test)

add_executable(List example/list_example.cpp List/List.h List/SinglyLinkedList.h List/SinglyLinkedList.cpp  List/DoublyLinkedList.h List/DoublyLinkedList.cpp)
add_executable(Heap example/heap_example.cpp trees/Heap/Heap.h trees/Heap/Heap.cpp)
add_executable(Queue example/queue_example.cpp Queue/Queue.h Queue/Queue.cpp List/List.h List/SinglyLinkedList.h List/SinglyLinkedList.cpp)
add_executable(Stack example/stack_example.cpp Stack/Stack.h Stack/Stack.cpp List/List.h List/SinglyLinkedList.h List/SinglyLinkedList.cpp)
add_executable(LinearSearch example/list_example.cpp Algorithm/Searching/LinearSearch.cpp)
add_executable(BinarySearch example/binary_search_example.cpp Algorithm/Searching/BinarySearch.cpp)
add_executable(BubbleSort example/bubble_sort_example.cpp Algorithm/Sorting/BubbleSort.cpp)
add_executable(InsertionSort example/insertion_sort_example.cpp Algorithm/Sorting/insertionSort.cpp)
add_executable(MergeSort example/merge_sort_example.cpp Algorithm/Sorting/merge_sort.cpp)
add_executable(BST trees/BST/BST.h trees/BST/BST.cpp example/bst_example.cpp)
add_executable(AVL trees/BST/BST.h trees/BST/BST.cpp trees/AVL/AVL.h trees/AVL/AVL.cpp example/avl_example.cpp)
add_executable(HashTable vendor/VariadicTable.h HashTable/HashUtility.h HashTable/HashTable.h HashTable/HashTable.cpp example/hash_table_example.cpp)
add_executable(Dict vendor/VariadicTable.h HashTable/HashTable.h HashTable/HashTable.cpp Applications/Dict/Dict.cpp Applications/Dict/Dict.h example/dict_example.cpp)
add_executable(PyList Env.h Applications/List/List.h Applications/List/List.cpp example/_list_example.cpp)
add_executable(RBT trees/RBT/RBT.h trees/RBT/RBT.cpp example/rbt_example.cpp)
add_executable(AdjacencyListGraph Graph/Graphs/AdjacencyListGraph/AdjacencyListGraph.h Graph/Graphs/AdjacencyListGraph/AdjacencyListVertex.h example/graph_example.cpp)
