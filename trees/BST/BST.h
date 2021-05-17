//
// Created by Umer on 4/26/2021.
//

#ifndef DOUBLYLINKEDLIST_H_BST_H
#define DOUBLYLINKEDLIST_H_BST_H

#include <cstdarg>
#include "BstUtility.h"

template <typename T>
class BstNode {
public:
    T data;
    BstNode<T> *left, *right, *parent = nullptr;
    int height = 1; // for AVL tree.
};

template <typename T>
class BST {
protected:

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
     * Find the height BST.
     * The height of tree is
     *      H = 1 + floor(log2(N))
     * http://www.cs.gettysburg.edu/~ilinkin/courses/Fall-2020/cs216/notes/bintree.pdf
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return int
     */
    int find_height_of_tree(BstNode<T> *rootNode);

    /**
     * Utility function for levelOrder transverse.
     *
     * @since 1.0.0
     * @return void
     */
    void transverse_tree_level_order();

    /**
     * Transverse the tree to print element in level wise/order.
     * It start's printing with level 0, 1 and so on.
     * The height of BST is the number of nodes in the longest path from root to leaf.
     *
     * @param rootNode the given node.
     * @param i        index.
     *
     * @since 1.0.0
     * @return void
     */
    void levelOrder(BstNode<T> *rootNode, int i);

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
    void inorder(BstNode<T> *rootNode);

    /**
     * Transverse the tree to print element in preorder.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void preorder(BstNode<T> *rootNode);

    /**
     * Transverse the tree to print element in postorder.
     *
     * @param rootNode the given node.
     *
     * @since 1.0.0
     * @return void
     */
    void postorder(BstNode<T> *rootNode);

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

    /**
     * Delete the node from BST by item.
     *
     * @param item item to delete node.
     *
     * @since 1.0.0
     * @return void
     */
    BstNode<T> *remove(BstNode<T> * rootNode, T item);

public:
    BstNode<T> *root = nullptr;

    BST (){}

    /**
     * Explicit constructor to insert items.
     *
     * @param items list of item separated by commas to be inserted.
     *
     * @since 1.0.0
     */
    explicit BST(T items, ...)
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
     * Insert an item into the BST.
     *
     * @param item item to be inserted.
     *
     * @since 1.0.0
     * @return void
     */
    void insert(T item);

    /**
     * Transverse the tree to print element in level wise/order.
     * It start's printing with level 0, 1 and so on.
     * The height of BST is the number of nodes in the longest path from root to leaf.
     *
     * @since 1.0.0
     * @return void
     */
    void levelOrder();

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
    void remove(T item);

};

#endif //DOUBLYLINKEDLIST_H_BST_H
