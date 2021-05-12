//
// Created by Umer on 5/5/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HASHTABLE_H
#define DOUBLYLINKEDLIST_H_HASHTABLE_H

#include "HashFunctions.h"
#include "../vendor/VariadicTable.h"

enum HashType {MOD, MUL};

#define MIN_HASH_BUCKET 4

template <typename K, typename V>
class TableItems {
public:
    K key;
    V value;
    int hash = -1;
};

template <typename K, typename V>
class HashTable {
public:
    TableItems<K, V> *table;
    TableItems<K, V> *temp;
    long long capacity = MIN_HASH_BUCKET;
    long long size = 1;
    HashTable() {
        this->table = (TableItems<K, V>*)malloc(this->capacity * sizeof(TableItems<K, V>));
        for (int i = 0; i< this->capacity; i++) {
            this->table[i] = TableItems<K, V>();
        }
    }
    int hash(int key);
    int rehash(int oldHash);
    void add(K key, V value);
    void insert(K key, V value);
    void rebuild();
    V get(int key);
    V operator[] (int key);
    void erase(int key);
    void debug();
};

#endif //DOUBLYLINKEDLIST_H_HASHTABLE_H
