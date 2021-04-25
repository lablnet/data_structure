//
// Created by Umer on 4/24/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HEAP_H
#define DOUBLYLINKEDLIST_H_HEAP_H
#include <vector>
#include <cstdarg>

enum HeapType {MaxHeap, MinHeap};

template <typename T>
class Heap {
public:

    std::vector<T> data;
    int capacity = 0;
    int size = 0;

    explicit Heap ()
    {

    }
    explicit Heap(HeapType type, T items, ...)
    {
        va_list arguments;

        // Init variable argument list.
        va_start(arguments, items);
        for (int i = 0; i < items; i++) {
            this->insert(va_arg(arguments, T), type);
        }
        // Clean up argument list
        va_end(arguments);

    }

    int parent(int i);
    int left(int i);
    int right(int i);
    void maxHeapify(int i);
    void minHeapify(int i);
    void insert(T data, HeapType type = MaxHeap);
    void print();
    void sort(HeapType type = MaxHeap);
};

#endif //DOUBLYLINKEDLIST_H_HEAP_H
