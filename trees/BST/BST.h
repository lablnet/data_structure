//
// Created by Umer on 4/26/2021.
//

#ifndef DOUBLYLINKEDLIST_H_BST_H
#define DOUBLYLINKEDLIST_H_BST_H

template <typename T>
class BstNode {
public:
    T data;
    BstNode<T> *left, *right, *parent = nullptr;
};

template <typename T>
class BST {
private:

    /**
     * Insert an item into the BST.
     *
     * @param rootNode The give node
     * @param item item to be inserted.
     *
     * @since 1.0.0
     * @return BstNode<T>
     */
    BstNode<T> *insert(BstNode<T> *rootNode, T item);

    /**
     * Search an item in BST.
     *
     * @param rootNode the given node.
     * @param item item to be searched.
     *
     * @since 1.0.0
     * @return BstNode<T>
     */
    BstNode<T> *search(BstNode<T> *rootNode, T item);

    /**
     * Transverse the tree to print element in sorted order.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void inorder(BstNode<T> *rootNode);

    /**
     * Get the minimum element node from BST.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return BstNode<T>
     */
    BstNode<T> *minimum(BstNode<T> *rootNode);

    /**
     * Get the maximum element node from BST.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return BstNode<T>
     */
    BstNode<T> *maximum(BstNode<T> *rootNode);


    /**
     * Get the next larger element / successor node.
     *
     * @param rootNode The given node.
     *
     * @since 1.0.0
     * @return BstNode<T>
     */
    BstNode<T> *successor(BstNode<T> *rootNode);

    /**
     * Get the prev smaller element / predecessor node.
     *
     * @param rootNode The given node.
     *
     * @since 1.0.0
     * @return BstNode<T>
     */
    BstNode<T> *predecessor(BstNode<T> *rootNode);

public:
    BstNode<T> *root = nullptr;

    /**
     * Insert an item into the BST.
     *
     * @param item item to be inserted.
     *
     * @since 1.0.0
     * @return void
     */
    void insert(T item);

    /**
     * Transverse the tree to print element in sorted order.
     *
     * @since 1.0.0
     * @return void
     */
    void inorder();

    /**
     * Search an item in BST.
     *
     * @param item item to be searched.
     *
     * @since 1.0.0
     * @return <T>
     */
    T search(T item);

    /**
     * Get the minimum element node from BST.
     *
     * @since 1.0.0
     * @return BstNode<T>
     */
    BstNode<T> *minimum();

    /**
     * Get the maximum element node from BST.
     *
     * @since 1.0.0
     * @return BstNode<T>
     */
    BstNode<T> *maximum();

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
     * Delete the node from BST by item.
     *
     * @param item item to delete node.
     *
     * @since 1.0.0
     * @return void
     */
    void delNode(T item);

};

#endif //DOUBLYLINKEDLIST_H_BST_H
