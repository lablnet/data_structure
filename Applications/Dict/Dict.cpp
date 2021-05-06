//
// Created by Umer on 5/6/2021.
//

#include "Dict.h"

//template<typename K, typename V>
//void Dict<K, V>::operator[](K key, V value) {
//    this->insert(key, value);
//}

template<typename K, typename V>
TableItems<K, V> *Dict<K, V>::copy() {
    return this->table;
}

template<typename K, typename V>
V Dict<K, V>::get(int key, V def) {
    try {
        return HashTable<K, V>::get(key);
    } catch (std::invalid_argument e) {
        return def;
    }
}

template<typename K, typename V>
V Dict<K, V>::pop(int key, V def) {
    V val = this->get(key, def);
    this->erase(key);
    return val;
}
