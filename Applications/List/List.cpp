//
// Created by Hp on 5/7/2021.
//

#include "List.h"

template<typename T>
long long List<T>::capacity() {
    int base = 32;
    #ifdef ENV64BIT
        base = 64;
    #endif
    return std::pow(2, (base - sizeof(T)) - 1);
}

template<typename T>
void List<T>::append(T item) {
    if (this->s == this->memory) {
        this->memory = 2 * this->memory;
        this->temp = (T*)realloc(this->items, this->memory * sizeof(T));
        this->items = this->temp;
        add(item);
        return;
    }
    add(item);
}

template<typename T>
void List<T>::insert(int index, T value) {
    if (index >= this->memory || this->s == this->memory) {
        this->append(value);
        return;
    }
    // if index provided is negative, set it to 0.
    if (index < 0) index = 0;
    T val = this->items[index];
    auto *list = (T*)malloc(this->memory * sizeof(T));
    for (int i = index; i <= this->s; i++) {
        if (index == i) {
            list[i] = value;
        } else if (index == i - 1) {
            list[i] = val;
        } else {
            list[i] = this->items[i-1];
        }
    }

    this->items = list;
    this->s++;
}

template<typename T>
void List<T>::prepend(T item) {
    this->insert(0, item);
}

template<typename T>
T List<T>::get(int index) {
    if (index <this->s) return this->items[index];
    else throw std::invalid_argument("Key error");
}

template<typename T>
T List<T>::operator[](int index) {
    return this->get(index);
}

template<typename T>
int List<T>::index(T item) {
    for (int i = 0; i < this->s; i++) {
        if (this->items[i] == item) return i;
    }

    return -1;
}

template<typename T>
void List<T>::remove(T item) {
    int _index = this->index(item);
    if (_index == -1) return;
    this->s--;
    for (int i = _index; i < this->s; i++) {
        this->items[i] = this->items[i+1];
    }
}

template<typename T>
T List<T>::pop(int index) {
    int i = index;
    if (i < 0) i = this->s - 1;
    T item = this->get(i);
    this->remove(item);
    return item;
}

template<typename T>
int List<T>::count(T item) {
    int c = 0;
    for (int i = 0; i < this->s; i++) {
        if (item == this->items[i]) c++;
    }

    return c;
}

template<typename T>
void List<T>::sort() {
    std::vector<T> v;
    for (int i = 0; i < this->s; i++)
        v.push_back(this->items[i]);

    std::vector<T> sorted = merge_sort(v);
    int i = 0;

    for (T item : sorted) {
        this->items[i] = item;
        i++;
    }
}

template<typename T>
T *List<T>::copy() {
    return this->items;
}

template<typename T>
void List<T>::reverse() {
    auto *list = (T*)malloc(this->memory * sizeof(T));
    for (int i = this->s - 1, index = 0; i >= 0, index <= this->s; i--, index++) {
        list[index] = this->items[i];
    }
    this->items = list;
}

template<typename T>
void List<T>::extend(T *list, int size) {
    for (int i = 0; i < size; i++) {
        this->append(list[i]);
    }
}
