//
// Created by Umer on 5/5/2021.
//

#include "HashTable.h"

template<typename K, typename V>
void HashTable<K, V>::rebuild(long long old_capacity, long long new_capacity) {
    // reset the size because we're rehashing/rebuilding table.
    this->size = 0;
    this->capacity = new_capacity;

    // get the least prime
    this->PRIME = lablnet::findLeastPrime(this->capacity);

    // init the temp node/array for storing previously stored item.
    auto *temp_table = (TableItems<K, V>*)malloc(old_capacity * sizeof(TableItems<K, V>));

    // store the previously item to temp table.
    for (int i = 0; i < old_capacity; i++) {
        temp_table[i] = this->table[i];
    }

    // resize the array and initialize it to table.
    this->temp = (TableItems<K, V>*)realloc(this->table, this->capacity * sizeof(TableItems<K, V>));
    this->table = this->temp;

    for (int i = 0; i< this->capacity; i++) {
        this->table[i] = TableItems<K, V>();
    }
    for (int i = 0; i < old_capacity; i++) {
        if (temp_table[i].hash != -1) {
            this->add(temp_table[i].key, temp_table[i].value);
        }
    }
}

template<typename K, typename V>
int HashTable<K, V>::get_key(K key) {
    if (lablnet::get_type(key) == "string") {
        return lablnet::hash_string(key, this->capacity);
    }

    return static_cast<int>(key);
}

template <typename K, typename V>
void HashTable<K, V>::add(K key, V value) {
    int k = this->get_key(key);

    int hash1 = this->hash(k);
    if (this->table[hash1].hash == -1) {
        this->table[hash1].key = key;
        this->table[hash1].value = value;
        this->table[hash1].hash = hash1;
        this->size++;
    } else {
        // If the slot is occupied.
        if (this->table[hash1].key == key) {
            this->table[hash1].value = value;
        } else {
            int hash2 = this->hash2(k);
            int i = 0;
            int hash3 = hash2;
            while (this->table[hash3].hash != -1 && this->table[hash3].key != key) {
                hash3 = (hash1 + i * hash2) % this->capacity;
                i++;
            }
            if (this->table[hash3].hash == -1) {
                this->table[hash3].key = key;
                this->table[hash3].value = value;
                this->table[hash3].hash = hash3;
                this->size++;
            } else {
                this->table[hash3].value = value;
            }
        }
    }
}

template <typename K, typename V>
int HashTable<K, V>::hash(int key) {
    return key % this->capacity;
}

template <typename K, typename V>
int HashTable<K, V>::hash2(int key) {
    return this->PRIME - (key % this->PRIME);
}

template <typename K, typename V>
void HashTable<K, V>::insert(K key, V value)
{
    if (this->size == this->capacity) {
        // 2 * capacity => table doubling.
        this->rebuild(this->capacity, 2 * this->capacity);
        this->add(key, value);
        return;
    }
    this->add(key, value);
}

template<typename K, typename V>
int HashTable<K, V>::getHash(K key) {
    int k = this->get_key(key);
    int hash1 = this->hash(k);
    auto item = this->table[hash1];
    if (item.hash == hash1 && item.key == key) return item.hash;
    else {
        int hash2 = this->hash2(k);
        int hash3 = hash2;
        int i = 0;
        while (this->table[hash3].hash != -1) {
            if (this->table[hash3].key == key) return this->table[hash3].hash;
            else {
                hash3 = (hash1 + i * hash2) % this->capacity;
                if (hash3 == hash1) break;
            }
            i++;
        }
        return -1;
    }
}

template<typename K, typename V>
V HashTable<K, V>::get(K key) {
    int hash = this->getHash(key);
    if (hash != -1){
        return this->table[hash].value;
    }
    throw std::invalid_argument("Key error");
}

template <typename K, typename V>
V HashTable<K, V>::operator[](K key)
{
    return this->get(key);
}

template <typename K, typename V>
void HashTable<K, V>::erase(K key)
{
    int hash = this->getHash(key);
    if (hash != -1) {
        this->table[hash] = TableItems<K, V>();
        this->size--;
    }

    // if the table size is quarter, then capacity, shrink it to half.
    if ((this->capacity / 4) == this->size) {
        this->rebuild(this->capacity, this->capacity / 2);
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
