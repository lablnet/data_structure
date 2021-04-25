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
    int size = 0;

    /**
     * Constructor.
     *
     * @since 1.0.0
     */
    explicit Heap ()
    {

    }

    /**
     * Explicit constructor to insert items.
     *
     * @param type heap type.
     * @param items list of item separated by commas to be inserted.
     *
     * @since 1.0.0
     */
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

    /**
     * Get the parent node of tree.
     *
     * @param i ith value of current position in tree.
     * @since 1.0.0
     *
     * @return int
     */
    int parent(int i);

    /**
     * Get the left node of tree.
     *
     * @param i ith value of current position in tree.
     * @since 1.0.0
     *
     * @return int
     */
    int left(int i);

    /**
     * Get the right node of tree.
     *
     * @param i ith value of current position in tree.
     * @since 1.0.0
     *
     * @return int
     */
    int right(int i);

    /**
     * Heapify the heap to build subtree.
     *
     * @param i ith value of current position in tree.
     * @since 1.0.0
     *
     * @return void
     */
    void maxHeapify(int i);

    /**
     * Heapify the tree.
     *
     * @param i ith value of current position in tree.
     * @since 1.0.0
     *
     * @return void
     */
    void minHeapify(int i);

    /**
     * Insert an item into the heap.
     *
     * @param data item to be inserted.
     * @param type heap type MinHeap|MaxHeap
     * @since 1.0.0
     *
     * @return void
     */
    void insert(T data, HeapType type = MaxHeap);

    /**
     * Print heap tree.
     *
     * @since 1.0.0
     *
     * @return void
     */
    void print();

    /**
     * Convert heap tree into sorted array|list.
     *
     * @param type Heap type.
     * @since 1.0.0
     *
     * @return void
     */
    void sort(HeapType type = MaxHeap);

    /**
     * Extract item from the heap base on type min or max.
     *
     * @param type Heap type.
     * @since 1.0.0
     *
     * @return <T>
     */
    T extract(HeapType type = MaxHeap);

    /**
     * Increase value of key at index 'i' to new value.
     *
     * @param i ith value of current position in tree.
     * @param item item to be updated.
     *
     * @since 1.0.0
     *
     * @return int
     */
    void increaseKey(int i, T item);
};

#endif //DOUBLYLINKEDLIST_H_HEAP_H
