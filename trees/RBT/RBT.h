//
// Created by Umer on 5/30/2021.
//

#ifndef DOUBLYLINKEDLIST_H_RBT_H
#define DOUBLYLINKEDLIST_H_RBT_H

enum RBColors {RED, BLACK};

template <typename T>
class RBTNode {
public:
    T data;
    RBColors color;
    RBTNode *left, *right;
};

template <typename T>
class RBT {
private:
    RBTNode<T> root;
public:
    RBT () {

    }

};

#endif //DOUBLYLINKEDLIST_H_RBT_H
