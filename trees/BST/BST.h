//
// Created by Umer on 4/26/2021.
//

#ifndef DOUBLYLINKEDLIST_H_BST_H
#define DOUBLYLINKEDLIST_H_BST_H

template <typename T>
class BstNode {
public:
    T data;
    BstNode<T> *left, *right = nullptr;
};

template <typename T>
class BST {
private:
    BstNode<T> *search(BstNode<T> *rootNode, T item);
    BstNode<T> *insert(BstNode<T> *rootNode, T item);
    void inorder(BstNode<T> *rootNode);

public:
    BstNode<T> *root = nullptr;

    void insert(T item);
    void inorder();
    T search(T item);
    T minimum();
    T maximum();

};

#endif //DOUBLYLINKEDLIST_H_BST_H
