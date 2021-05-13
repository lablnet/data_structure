//
// Created by Umer on 5/5/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HASHTABLE_H
#define DOUBLYLINKEDLIST_H_HASHTABLE_H

#include <iostream>
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

    /**
     * Rebuild the hash table.
     *
     * @param old_capacity previously capacity of the hash table.
     * @param new_capacity the new capacity of the table.
     *
     * @since 1.0.0
     * @return void
     */
    void rebuild(long long old_capacity, long long new_capacity);

    /**
     * Get the key.
     *
     * @param key given key.
     *
     * @bug Known issue
     * @since 1.0.0
     * @return int
     */
    int get_key(K key);

    /**
     * Add the item into hash table.
     *
     * @param key   the given key.
     * @param value the value to be inserted.
     *
     * @since 1.0.0
     * @return void
     */
    void add(K key, V value);
public:
    TableItems<K, V> *table;
    TableItems<K, V> *temp;
    long long capacity = MIN_HASH_BUCKET;
    long long size = 0;
    int PRIME = 7;

    /**
     * init the members.
     *
     * @since 1.0.0
     */
    HashTable() {
        this->table = (TableItems<K, V>*)malloc(this->capacity * sizeof(TableItems<K, V>));
        this->PRIME = lablnet::findLeastPrime(this->capacity);
        for (int i = 0; i< this->capacity; i++) {
            this->table[i] = TableItems<K, V>();
        }
    }

    /**
     * Hash function.
     *
     * @param key   the given key.
     *
     * @since 1.0.0
     * @return int
     */
    int hash(int key);

    /**
     * Hash function 2.
     *
     * @param key   the given key.
     *
     * @since 1.0.0
     * @return int
     */
    int hash2(int key);

    /**
     * Add the item into hash table.
     *
     * @param key   the given key.
     * @param value the value to be inserted.
     *
     * @since 1.0.0
     * @return void
     */
    void insert(K key, V value);

    /**
     * Get the hash of given key.
     *
     * @param key the given key.
     *
     * @since 1.0.0
     * @return int
     */
    int getHash(K key);

    /**
     * Get the item from the table.
     *
     * @param key the given key.
     *
     * @since 1.0.0
     * @return <V>
     */
    V get(K key);

    /**
     * Get the item from hash table.
     *
     * @param key the given key.
     *
     * @since 1.0.0
     * @return <V>
     */
    V operator[] (K key);

    /**
     * Delete an item from hash table.
     *
     * @param key the given key.
     *
     * @since 1.0.0
     * @return void
     */
    void erase(K key);

    /**
     * Print the hash table into table form for debugging.
     *
     * @purpose debug
     * @since 1.0.0
     * @return void
     */
    void debug();
};

#endif //DOUBLYLINKEDLIST_H_HASHTABLE_H
