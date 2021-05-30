//
// Created by Umer on 5/30/2021.
//

#ifndef DOUBLYLINKEDLIST_H_RBT_H
#define DOUBLYLINKEDLIST_H_RBT_H

#include <string>
#include <iostream>

// RBT Trees Colors.
enum RBColors {RED, BLACK};

template <typename T>
class RBTNode {
public:
    T data;
    RBColors color;
    RBTNode *parent, *left, *right = nullptr;
};

template <typename T>
class RBT {
private:
    RBTNode<T> *NIL; // TNIL

    /**
     * Search an item in RBT.
     *
     * @param rootNode the given node.
     * @param item item to be searched.
     *
     * @since 1.0.0
     * @return RBTNode<T>
     */
    RBTNode<T> *search(RBTNode<T> *rootNode, T item);

    /**
     * Transverse the tree to print element in sorted/inorder order.
     * NOTE:The binary-search-tree property allows us to print out all the keys in a binary
search tree in sorted order by a simple recursive algorithm, called an inorder tree walk.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void inorder(RBTNode<T> *rootNode);

    /**
     * Transverse the tree to print element in preorder.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void preorder(RBTNode<T> *rootNode);

    /**
     * Transverse the tree to print element in postorder.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void postorder(RBTNode<T> *rootNode);

    /**
     * Get the minimum element node from RBT.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return RBTNode<T>
     */
    RBTNode<T> *minimum(RBTNode<T> *rootNode);

    /**
     * Get the maximum element node from RBT.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return RBTNode<T>
     */
    RBTNode<T> *maximum(RBTNode<T> *rootNode);

    /**
     * Get the next larger element / successor node.
     *
     * @param rootNode The given node.
     *
     * @since 1.0.0
     * @return RBTNode<T>
     */
    RBTNode<T> *successor(RBTNode<T> *rootNode);

    /**
     * Get the prev smaller element / predecessor node.
     *
     * @param rootNode The given node.
     *
     * @since 1.0.0
     * @return RBTNode<T>
     */
    RBTNode<T> *predecessor(RBTNode<T> *rootNode);

    /**
     * Method to rotate left subtree rooted with node.
     *
     * @param node the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void leftRotation(RBTNode<T> *node);

    /**
     * Method to rotate left subtree rooted with node.
     *
     * @param node the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void rightRotation(RBTNode<T> *node);

    /**
     * Rebalance the tree if RBT property violate.
     *
     * @param node the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void insertFixup(RBTNode<T> *node);

    // @TODO
    void deleteFixup(RBTNode<T> *node);
    void rbTransplant(RBTNode<T> *u, RBTNode<T> *v);
public:
    RBTNode<T> *root;

    /**
     * Init the properties.
     *
     * @since 1.0.0
     */
    RBT () {
        // Arbitrary node.
        this->NIL = new RBTNode<T>();
        this->NIL->color = BLACK;
        this->root = this->NIL;
    }

    /**
     * Insert an item into the RBT.
     *
     * @param item item to be inserted.
     *
     * @since 1.0.0
     * @return void
     */
    void insert(T data);

    /**
     * Transverse the tree to print element in sorted order.
     * NOTE:The binary-search-tree property allows us to print out all the keys in a binary
    search tree in sorted order by a simple recursive algorithm, called an inorder tree walk.
     *
     * @since 1.0.0
     * @return void
     */
    void inorder();

    /**
     * Transverse the tree to print element in preorder.
     *
     * @since 1.0.0
     * @return void
     */
    void preorder();

    /**
     * Transverse the tree to print element in postorder.
     *
     * @since 1.0.0
     * @return void
     */
    void postorder();

    /**
     * Get the minimum element node from RBT.
     *
     * @since 1.0.0
     * @return RBTNode<T>
     */
    RBTNode<T> *minimum();

    /**
     * Get the maximum element node from RBT.
     *
     * @since 1.0.0
     * @return RBTNode<T>
     */
    RBTNode<T> *maximum();

    /**
     * Get the next larger element / successor.
     *
     * @param item item to find successor.
     *
     * @since 1.0.0
     * @return <T>
     */
    T successor(T item);

    /**
     * Get the prev smaller element / predecessor.
     *
     * @param item item to find predecessor.
     *
     * @since 1.0.0
     * @return <T>
     */
    T predecessor(T item);

    /**
     * Search an item in RBT.
     *
     * @param item item to be searched.
     *
     * @since 1.0.0
     * @return <T>
     */
    T search(T item);

    // @TODO
    void remove(T data);
};


#endif //DOUBLYLINKEDLIST_H_RBT_H
