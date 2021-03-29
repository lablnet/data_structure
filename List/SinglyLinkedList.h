//
// Created by M Umer Farooq on 3/26/2021.
//
#include <cstdarg>
#include <iostream>
#include "List.h"
#ifndef DATA_STRUCTURE_SINGLYLINKEDLIST_H
#define DATA_STRUCTURE_SINGLYLINKEDLIST_H

template <typename T>
class SinglyLinkedList {
    private:
        // properties to store head and tail.
        List<T> *head;
        List<T> *tail;
    public:
        // property to store size.
        int size = 0;

        /**
         * Constructor to init properties.
         *
         * @since 1.0.0
         */

        explicit SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        /**
         * Explicit constructor to insert items.
         *
         * @param items list of item separated by commas to be inserted.
         * @since 1.0.0
         * @todo
         */
        explicit SinglyLinkedList(T items, ...) {
            // Init values.
            this->head = nullptr;
            this->tail = nullptr;

            // Hold information about variable argument.
            va_list arguments;

            // Init variable argument list.
            va_start(arguments, items);
            for (int i = 0; i < items; i++) {
                // need debugging:
                //std::cout << "inserting: " <<va_arg(arguments, T) << std::endl;
                //this->add(va_arg(arguments, T));
            }
            // Clean up argument list
            va_end(arguments);
        }

        /**
         * Add item at end of list.
         *
         * @param item item to be inserted.
         * @since 1.0.0
         * return void
         */
        void add(T item);

        /**
        * Add item at specific index of list.
        *
        * @param index index where item need to inserted.
        * @param item item to be inserted.
        * @since 1.0.0
        * @todo
        * return void
        */
        void add(int index, T item);

        /**
        * prepend item to the list.
        *
        * @param item item to be prepended.
        * @since 1.0.0
        * return void
        */
        void prepend(T item);

        /**
         * Get and element on specific index.
         *
         * @param index item to get.
         * @since 1.0.0
         * return <T>
         */
        T get(int index);

        /**
         * Remove item from specific index.
         *
         * @param index where the item should remove.
         * @since 1.0.0
         * return void
         */
        void remove(int index);

        /**
         * Remove first item/head form list.
         *
         * @since 1.0.0
         * return <T>
         */
        T removeFIrst();

        /**
         * Remove last/tail form the list.
         *
         * @since 1.0.0
         * return <T>
         */
        T removeLast();

        /**
         * Search an item in list.
         *
         * @param item item to be find.
         * @since 1.0.0
         * @todo
         * return <T>
         */
        T search (T item);

        /**
         * Get the first item from list.
         *
         * @since 1.0.0
         * return <T>
         */
        T getFirst();

        /**
         * Get the last item from list.
         *
         * @since 1.0.0
         * return <T>
         */
        T getLast();

        /**
         * Display all item from list.
         *
         * @since 1.0.0
         * @purpose DEBUG
         * return void
         */
        void display();

        /**
         * Get the size/length of list
         *
         * @since 1.0.0
         * return int
         */
        int length();

        /**
         * Get index of the first occurrence of item
         *
         * @param item item to search.
         * @since 1.0.0
         * return int
         */
        int indexOf(T item);

        /**
         * Get index of the last occurrence of item
         *
         * @param item item to search.
         * @since 1.0.0
         * return int
         */
        int lastIndexOf(T item);

        /**
         * Replace item on specific index.
         *
         * @param index index where item to be inserted.
         * @param item item to inserted.
         * @since 1.0.0
         * return void
         */
        void replace(int index, T item);

        /**
         * Replace item on specific value.
         *
         * @param old item to replaced.
         * @param item item to search.
         * @since 1.0.0
         * return void
         */
        void replaceByValue(T old, T item);

        /**
         * Flush/Clear the list.
         *
         * @since 1.0.0
         * return void
         */
        void flush();

        /**
         * Destructor to flush list.
         */
        ~SinglyLinkedList()
        {
            this->flush();
        }
};

#endif //DATA_STRUCTURE_SINGLYLINKEDLIST_H
