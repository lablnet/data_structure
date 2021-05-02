//
// Created by Umer on 4/28/2021.
//

#ifndef DOUBLYLINKEDLIST_H_AVL_H
#define DOUBLYLINKEDLIST_H_AVL_H

#include "../BST/BST.cpp"

template <typename T>
class AVL : public BST<T> {

    int max(int a, int b);
    int height(BstNode<T> *node);
    void update_height(BstNode<T> *node);
public:
    // @override
    void insert(T data);

    void rebalance(BstNode<T> *rootNode);
    void leftRotate(BstNode<T> *node);
    void rightRotate(BstNode<T> *node);
    void remove(T data);
};


#endif //DOUBLYLINKEDLIST_H_AVL_H
