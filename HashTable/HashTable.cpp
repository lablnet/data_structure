//
// Created by Hp on 5/5/2021.
//

#include <iostream>
#include "HashTable.h"

template<typename T>

void HashTable<T>::add(int h, T key, T value) {
    this->table[h].key = key;
    this->table[h].value = value;
    this->size++;
}

template<typename T>
int HashTable<T>::hash(int key) {
    return key % this->capacity;
}

template<typename T>
void HashTable<T>::insert(T key, T value)
{
    if (this->size == this->capacity) {
        this->capacity++;
        this->temp = (TableItems<T>*)realloc(this->table, this->capacity * sizeof(TableItems<T>));
        this->table = this->temp;
        int h = this->hash(key);
        this->add(h, key, value);
        return;
    }
    int h = this->hash(key);
    this->add(h, key, value);
}

template<typename T>
T HashTable<T>::operator[](int key)
{
    int h = this->hash(key);
    T item = this->table[h].value;

    return item;
}
