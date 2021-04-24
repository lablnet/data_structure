//
// Created by Umer on 4/24/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HEAP_H
#define DOUBLYLINKEDLIST_H_HEAP_H
#include <vector>

enum HeapType {MaxHeap, MinHeap};

template <typename T>
class Heap {
public:

    std::vector<T> data;
    int capacity = 0;
    int size = 0;

    explicit Heap()
    {
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
