//
// Created by Umer on 5/6/2021.
//

#ifndef DOUBLYLINKEDLIST_H_DICT_H
#define DOUBLYLINKEDLIST_H_DICT_H

#include "../../HashTable/HashTable.cpp"

template<typename K, typename V>
class Dict : public HashTable<K, V> {
public:
    //void operator[](K key, V value);

    /**
     * Return copy of Dict.
     *
     * @since 1.0.0
     * @return <TableItems<K, V>>
    */
    TableItems<K, V> *copy();

    /**
     * Return the item with the key.
     *
     * @param key the given key
     * @param def default value in case of key does not exist.
     *
     * @since 1.0.0
     * @return <V>
    */
    V get(int key, V def = V{});

    /**
     * Removes the item with the key and returns its value, return def otherwise.
     *
     * @param key the given key
     * @param def default value in case of key does not exist.
     *
     * @since 1.0.0
     * @return <V>
    */
    V pop(int key, V def = V{});

    // more operation
    // TODO

    /**
     * Removes all items from the dict.
     *
     * @since 1.0.0
     * @return void
    */
    void clear()
    {
        for (int i = 0; i < this->capacity; i++)
            this->table[i] = TableItems<K, V>();
    }
};


#endif //DOUBLYLINKEDLIST_H_DICT_H
