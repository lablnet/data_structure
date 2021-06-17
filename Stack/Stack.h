//
// Created by M Umer Farooq on 3/28/2021.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
#include "../List/SinglyLinkedList.cpp"

template<typename T>
class Stack {
    private:
        // list.
        SinglyLinkedList<T> list;

    public:
        /**
         * Push an item to stack.
         *
         * @param item item to be pushed.
         * @since 1.0.0
         * @return void
         */
        void push(T item);

        /**
         * Pop last item from stack and return it.
         *
         * @since 1.0.0
         * @return <T>
         */
        T pop();

        /**
         * Get the last item from stack, without removing it.
         *
         * @since 1.0.0
         * @return <T>
         */
        T peak();

        /**
         * Determine if list is empty.
         * @return bool
         */
        bool isEmpty();

        /**
         * Get the size of Stack
         * @return <int>
         */
        int size();

        /**
         * Display the stack items.
         * @return void
         */
        void display();

        /**
         * Destructor to flush the stack.
         */
        ~Stack() {
            list.flush();
        }
};


#endif //DATA_STRUCTURE_STACK_H
