//
// Created by Hp on 5/5/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HASHTABLE_H
#define DOUBLYLINKEDLIST_H_HASHTABLE_H

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
    long long capacity = 1;
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
};

#endif //DOUBLYLINKEDLIST_H_HASHTABLE_H
