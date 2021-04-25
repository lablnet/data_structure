//
// Created by Umer on 4/24/2021.
//

#include "Heap.h"
#include <iostream>

template<typename T>
int Heap<T>::parent(int i) {
    return (i - 1) / 2;
}

template<typename T>
int Heap<T>::left(int i) {
    return (2 * i) + 1;
}

template<typename T>
int Heap<T>::right(int i) {
    return (2 * i) + 2;
}

template<typename T>
void Heap<T>::maxHeapify(int i) {
    int largest = i;
    int l = this->left(i);
    int r = this->right(i);

    // if the left child greater then root.
    if (l < this->size && this->data[l] > this->data[i]) {
        largest = l;
    }

    // if the right child greater then root.
    if (r < this->size && this->data[r] > this->data[i]) {
        largest = r;
    }

    if (largest != i) {
        std::iter_swap(&this->data[i], &this->data[largest]);
        this->maxHeapify(largest);
    }
}

template<typename T>
void Heap<T>::minHeapify(int i) {
    int smallest = i;
    int l = this->left(i);
    int r = this->right(i);

    // if the left child smaller then root.
    if (l < this->size && this->data[l] < this->data[i]) {
        smallest = l;
    }
    // if the right child smaller then root.
    if (r < this->size && this->data[r] < this->data[i]) {
        smallest = r;
    }

    if (smallest != i) {
        std::iter_swap(&this->data[i], &this->data[smallest]);
        this->minHeapify(smallest);
    }
}
template<typename T>
void Heap<T>::insert(T data, HeapType type) {
    if (this->data.size() == 0) {
        this->data.push_back(data);
        this->size++;

        return;
    }
    this->data.push_back(data);
    this->size++;
    for (int i = this->parent(this->data.size()); i >= 0; i--) {
        if (type == MaxHeap)
            this->maxHeapify(i);
        else
            this->minHeapify(i);
    }
}

template<typename T>
void Heap<T>::print() {
    for (int i = 0; i < this->data.size(); i++) {
        std::cout << "i : " << i << " val: " << this->data[i] << std::endl;
    }
}

template<typename T>
void Heap<T>::sort(HeapType type) {
    // Step 1 build max|min heap, but we considered we have nearly completed binary tree called heap.
    for (int i = this->data.size() - 1; i > 0; i--) {

        // move current node to root.
        std::iter_swap(&this->data[0], &this->data[i]);
        this->size = i;

        // reduce the heap.
        if (type == MaxHeap)
            this->maxHeapify(0);
        else
            this->minHeapify(0);
    }
}

template<typename T>
T Heap<T>::extract(HeapType type) {
    T element = this->data[0];
    this->data.erase(this->data.begin());
    //this->data[0] = this->data[this->size - 1];
    this->size--;

    // rebuild the heap.
    if (type == MaxHeap)
        this->maxHeapify(0);
    else
        this->minHeapify(0);

    return element;
}

template<typename T>
void Heap<T>::increaseKey(int i, T item) {
    this->data[i] = item;
    while (i > 0 && this->data[this->parent(i)] < this->data[i]) {
        std::iter_swap(&this->data[i], &this->data[this->parent(i)]);
        i = this->parent(i);
    }
}
