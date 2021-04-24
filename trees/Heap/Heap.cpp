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

    if (l <= this->data.size() && this->data[l] > this->data[i]) {
        largest = l;
    }
    if (r <= this->data.size() && this->data[r] > this->data[i]) {
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

    if (l < this->data.size() && this->data[l] < this->data[i]) {
        smallest = l;
    }
    if (r < this->data.size() && this->data[r] < this->data[i]) {
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

        return;
    }
    this->data.push_back(data);
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
}
