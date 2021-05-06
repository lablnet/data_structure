//
// Created by Umer on 5/5/2021.
//

#include <iostream>
#include "HashTable.h"

template <typename K, typename V>
void HashTable<K, V>::add(int h, K key, V value) {
    this->table[h].key = key;
    this->table[h].value = value;
    this->table[h].valid = true;
    this->size++;
}

template <typename K, typename V>
int HashTable<K, V>::hash(int key) {
    return key % this->capacity;
}

template <typename K, typename V>
void HashTable<K, V>::rehash()
{
    for (int i = 0; i < this->capacity; i++) {
        if (this->table[i].valid == true) {
            int key = this->table[i].key;
            this->table[this->hash(key)] = this->table[i];
        } else
            this->table[i] = TableItems<K, V>();
    }
}

template <typename K, typename V>
void HashTable<K, V>::insert(K key, V value)
{
    if (this->size == this->capacity) {
        this->capacity = 2 * MIN_HASH_BUCKET;
        this->temp = (TableItems<K, V>*)realloc(this->table, this->capacity * sizeof(TableItems<K, V>));
        this->table = this->temp;
        int h = this->hash(key);
        this->add(h, key, value);
        this->rehash();
        return;
    }
    int h = this->hash(key);
    this->add(h, key, value);
}

template <typename K, typename V>
V HashTable<K, V>::operator[](int key)
{
    int h = this->hash(key);
    auto item = this->table[h];
    if (item.valid == true) return item.value;
    else throw std::invalid_argument("Key error");
}

template <typename K, typename V>
void HashTable<K, V>::erase(int key)
{
    int h = this->hash(key);
    auto item = this->table[h];
    if (item.valid == true) {
        this->table[h] = TableItems<K, V>();
    }
}
