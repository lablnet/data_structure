//
// Created by Hp on 5/5/2021.
//

#include <iostream>
#include "HashTable.h"

template<typename T>
void HashTable<T>::add(int h, T key, T value) {
    this->table[h].key = key;
    this->table[h].value = value;
    this->table[h].valid = true;
    this->size++;
}

template<typename T>
int HashTable<T>::hash(int key) {
    return key % this->capacity;
}

template<typename T>
void HashTable<T>::rehash()
{
    for (int i = 0; i < this->capacity; i++) {
        if (this->table[i].valid == true) {
            int key = this->table[i].key;
            this->table[this->hash(key)] = this->table[i];
        } else
            this->table[i] = TableItems<T>();
    }
}

template<typename T>
void HashTable<T>::insert(T key, T value)
{
    if (this->size == this->capacity) {
        this->capacity*= 2;
        this->temp = (TableItems<T>*)realloc(this->table, this->capacity * sizeof(TableItems<T>));
        this->table = this->temp;
        int h = this->hash(key);
        this->add(h, key, value);
        this->rehash();
        return;
    }
    int h = this->hash(key);
    this->add(h, key, value);
}

template<typename T>
T HashTable<T>::operator[](int key)
{
    int h = this->hash(key);
    auto item = this->table[h];
    if (item.valid == true) return item.value;
    else throw std::invalid_argument("Key error");
}
