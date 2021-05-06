//
// Created by Umer on 5/5/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HASHTABLE_H
#define DOUBLYLINKEDLIST_H_HASHTABLE_H

#include "HashFunctions.h"

enum HashType {MOD, MUL};

#define MIN_HASH_BUCKET 8

template <typename T>
class TableItems {
public:
    T key;
    T value;
    bool valid = false;
};

template <typename T>
class HashTable {
public:
    TableItems<T> *table;
    TableItems<T> *temp;
    long long capacity = MIN_HASH_BUCKET;
    long long size = 1;
    HashTable() {
        this->table = (TableItems<T>*)malloc(this->capacity * sizeof(TableItems<T>));
        for (int i = 0; i< this->capacity; i++) {
            this->table[i] = TableItems<T>();
        }
    }
    int hash(int key);
    void add(int h, T key, T value);
    void insert(T key, T value);
    void rehash();
    T operator[] (int key);
    void erase(int key);
};

#endif //DOUBLYLINKEDLIST_H_HASHTABLE_H
