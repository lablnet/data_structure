//
// Created by Umer on 4/28/2021.
//

#ifndef DOUBLYLINKEDLIST_H_AVL_H
#define DOUBLYLINKEDLIST_H_AVL_H

#include "../BST/BST.cpp"

template <typename T>
class AVL : public BST<T> {

    /**
     * Get the max value.
     *
     * @param a first number.
     * @param b second number.
     *
     * @since 1.0.0
     * @return int
     */
    int max(int a, int b);

    /**
     * Get the height of node.
     *
     * @param node the given node.
     *
     * @since 1.0.0
     * @return int
     */
    int height(BstNode<T> *node);

    /**
     * Update the height of given node.
     *
     * @param node the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void update_height(BstNode<T> *node);
public:

    AVL (){}

    /**
     * Explicit constructor to insert items.
     *
     * @param items list of item separated by commas to be inserted.
     *
     * @since 1.0.0
     */
    explicit AVL(T items, ...)
    {
        va_list arguments;

        // Init variable argument list.
        va_start(arguments, items);
        for (int i = 0; i < items; i++) {
            this->insert(va_arg(arguments, T));
        }
        // Clean up argument list
        va_end(arguments);
    }

    /**
     * Insert an item into AVL tree.
     *
     * @param data item to be inserted.
     *
     * @override
     * @since 1.0.0
     * @return void
     */
    void insert(T data);

    /**
     * Rebalance the tree if, AVL property violated.
     *
     * @param node the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void rebalance(BstNode<T> *rootNode);

    /**
     * Method to rotate left subtree rooted with node.
     *
     * @param node the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void leftRotate(BstNode<T> *node);

    /**
     * Method to rotate right subtree rooted with node.
     *
     * @param node the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void rightRotate(BstNode<T> *node);

    /**
     * Delete the node from AVL by item.
     *
     * @param data item to delete node.
     *
     * @override
     * @since 1.0.0
     * @return void
     */
    void remove(T data);
};


#endif //DOUBLYLINKEDLIST_H_AVL_H
