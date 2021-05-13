//
// Created by Umer on 5/5/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HASHTABLE_H
#define DOUBLYLINKEDLIST_H_HASHTABLE_H

#include "HashUtility.h"
#include "../vendor/VariadicTable.h"

#define MIN_HASH_BUCKET 8

template <typename K, typename V>
class TableItems {
public:
    K key;
    V value;
    int hash = -1;
};

template <typename K, typename V>
class HashTable {
private:
    void rebuild(long long old_capacity, long long new_capacity);
    int get_key(K key);
    void add(K key, V value);
public:
    TableItems<K, V> *table;
    TableItems<K, V> *temp;
    long long capacity = MIN_HASH_BUCKET;
    long long size = 0;
    int PRIME = 7;
    HashTable() {
        this->table = (TableItems<K, V>*)malloc(this->capacity * sizeof(TableItems<K, V>));
        this->PRIME = lablnet::findLeastPrime(this->capacity);
        for (int i = 0; i< this->capacity; i++) {
            this->table[i] = TableItems<K, V>();
        }
    }
    int hash(int key);
    int hash2(int key);
    void insert(K key, V value);
    int getHash(K key);
    V get(K key);
    V operator[] (K key);
    void erase(K key);
    void debug();
};

#endif //DOUBLYLINKEDLIST_H_HASHTABLE_H
