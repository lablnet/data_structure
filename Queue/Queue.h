//
// Created by M Umer Farooq on 3/28/2021.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
#include "../List/SinglyLinkedList.h"

template<typename T>
class Queue {
    private:
        // list.
        SinglyLinkedList<T> list;
    public:
        /**
        * Push an item to Queue.
        *
        * @param item item to be pushed.
        * @since 1.0.0
        * @return void
        */
        void enqueue(T item);

        /**
         * Remove first item from Queue and return it.
         *
         * @since 1.0.0
         * @return <T>
         */
        T dequeue();

        /**
         * Determine if Queue is empty.
         *
         * @since 1.0.0
         * @return bool
         */
        bool isEmpty();

        /**
         * Get the size of Queue.
         *
         * @since 1.0.0
         * @return int
         */
        int size();

        /**
         * Display items of Queue.
         *
         * @since 1.0.0
         * @return <T>
         */
        void display();

        /**
         * Destructor to flush Queue.
         */
        ~Queue() {
            list.flush();
        }

};

#endif //DATA_STRUCTURE_QUEUE_H
