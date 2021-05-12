//
// Created by Umer on 5/5/2021.
//

#include <iostream>
#include "HashTable.h"

template <typename K, typename V>
void HashTable<K, V>::add(K key, V value) {
    int h = this->hash(key);
    if (this->table[h].hash == -1) {
        this->table[h].key = key;
        this->table[h].value = value;
        this->table[h].hash = h;
        this->size++;
    } else {
        if (this->table[h].key == key) {
            this->table[h].value = value;
        } else {
            int new_hash = this->rehash(h);
            while (this->table[new_hash].hash != -1 && this->table[new_hash].key != key) {
                new_hash = this->rehash(new_hash);
            }
            if (this->table[new_hash].hash == -1) {
                this->table[new_hash].key = key;
                this->table[new_hash].value = value;
                this->table[new_hash].hash = new_hash;
                this->size++;
            } else {
                this->table[new_hash].value = value;
            }
        }
    }
}

template <typename K, typename V>
int HashTable<K, V>::hash(int key) {
    return key % this->capacity;
}

template <typename K, typename V>
int HashTable<K, V>::rehash(int oldHash) {
    return this->hash(oldHash + 1);
}

template <typename K, typename V>
void HashTable<K, V>::insert(K key, V value)
{
    if (this->size == this->capacity) {
        // get the previous capacity.
        long long prev_capacity = this->capacity;
        this->capacity = 2 * this->capacity; // Table doubling.

        // init the temp node/array for storing previously stored item.
        auto *temp_table = (TableItems<K, V>*)malloc(prev_capacity * sizeof(TableItems<K, V>));

        // resize the array and initialize it to table.
        this->temp = (TableItems<K, V>*)realloc(this->table, this->capacity * sizeof(TableItems<K, V>));
        this->table = this->temp;

        // store the previously item to temp table.
        for (int i = 0; i < prev_capacity; i++) {
            temp_table[i] = this->table[i];
        }

        for (int i = 0; i< this->capacity; i++) {
            this->table[i] = TableItems<K, V>();
        }
        for (int i = 0; i < prev_capacity; i++) {
            if (temp_table[i].hash != -1) {
                this->add(temp_table[i].key, temp_table[i].value);
            }
        }
        this->add(key, value);
        return;
    }
    this->add(key, value);
}

template<typename K, typename V>
V HashTable<K, V>::get(int key) {
    int start_hash = this->hash(key);
    auto item = this->table[start_hash];
    if (item.hash == start_hash && item.key == key) return item.value;
    else {
        int new_hash = start_hash;
        while (this->table[new_hash].hash != -1) {
            if (this->table[new_hash].key == key) return this->table[new_hash].value;
            else {
                new_hash = this->rehash(new_hash);
                if (new_hash == start_hash) break;
            }
        }
        throw std::invalid_argument("Key error");
    }
}

template <typename K, typename V>
V HashTable<K, V>::operator[](int key)
{
    return this->get(key);
}

template <typename K, typename V>
void HashTable<K, V>::erase(int key)
{
    int h = this->hash(key);
    auto item = this->table[h];
    if (item.hash != -1) {
        this->table[h] = TableItems<K, V>();
    }
}

template <typename K, typename V>
void HashTable<K, V>::debug()
{
    VariadicTable<int, K, V, K> vt({"Index", "key", "Value", "Hash"});

    for (int i = 0; i < this->capacity; i++) {
        vt.addRow(i, this->table[i].key, this->table[i].value, this->table[i].hash);
    }
    vt.print(std::cout);
    std::cout << std::endl;
}