//
// Created by Umer on 5/7/2021.
//

#ifndef DOUBLYLINKEDLIST_H_LIST_H
#define DOUBLYLINKEDLIST_H_LIST_H

#include <cmath> // for pow function
#include <stdexcept> // for throw exception
#include <vector> // for transversing array to vector
#include "../../Algorithm/Sorting/merge_sort.cpp" // for sorting
#include "../../Env.h" // for system word size

#define LIST_MIN_SIZE 12

template <typename T>
class List {
    T *items;
    T *temp; // for resizing.
    int s = 0;
    int memory = LIST_MIN_SIZE;

    /**
     * Add an item to the list.
     *
     * @param item item to be added.
     *
     * @since 1.0.0
     * @return void
    */
    void add(T item) {
        this->items[this->s] = item;
        this->s++;
    }

    /**
     * Get an item from the list of specified index.
     *
     * @param index index to get item.
     *
     * @since 1.0.0
     * @return <T>
    */
    T get(int index);
public:

    /**
     * Constructor.
     *
     * @since 1.0.0
    */
    List() {
        this->items = (T*)malloc(this->memory * sizeof(T));
    }

    /**
     * Return the total capacity of list.
     *
     * @since 1.0.0
     * @return long long
    */
    long long capacity();

    /**
     * Return the size of list.
     *
     * @since 1.0.0
     * @return int
    */
    int size() {return this->s;}

    /**
     * Add an element to the end of the list.
     *
     * @param item item to be inserted.
     *
     * @since 1.0.0
     * @return void
    */
    void append(T item);

    /**
     *  Insert an item at the defined index.
     *
     * @param index index where the item should goes.
     * @param item item to be inserted.
     *
     * @since 1.0.0
     * @return void
    */
    void insert(int index, T value);

    /**
     * Add an element to the beginning of the list.
     *
     * @param item item to be inserted.
     *
     * @since 1.0.0
     * @return void
    */
    void prepend(T item);

    /**
     * Operator overloading.
     *
     * @param index given index.
     *
     * @since 1.0.0
     * @return <T>
    */
    T operator[] (int index);

    /**
     *  Returns the index of the first matched item.
     *
     * @param item item to matched.
     *
     * @since 1.0.0
     * @return int
    */
    int index(T item);

    /**
     * Removes an item from the list.
     *
     * @param item item to remove.
     *
     * @since 1.0.0
     * @return void
    */
    void remove(T item);

    /**
     * Removes and returns an element at the given index.
     *
     * @param index given index.
     *
     * @since 1.0.0
     * @return <T>
    */
    T pop(int index = -1);

    /**
     *  Returns the count of the number of items passed as an argument.
     *
     * @param item item to searched.
     *
     * @since 1.0.0
     * @return item
    */
    int count(T item);

    /**
     * Sort items in a list in ascending order using merge sort.
     *
     * @since 1.0.0
     * @return void
    */
    void sort();

    /**
     * Return copy of items.
     *
     * @since 1.0.0
     * @return <*T>
    */
    T *copy();

    /**
     * Reverse the order of items in the list.
     *
     * @since 1.0.0
     * @return void
    */
    void reverse();

    /**
     *  Add all elements of a list to the another list.
     *
     * @param list items to be inserted.
     * @param size size of newly array.
     *
     * @since 1.0.0
     * @return void
    */
    void extend(T *list, int size);

    /**
     *  Clear the list.
     *
     * @since 1.0.0
     * @return void
    */
    void clear()
    {
        free(this->items);
        free(this->temp);
    }
};

#endif //DOUBLYLINKEDLIST_H_LIST_H
