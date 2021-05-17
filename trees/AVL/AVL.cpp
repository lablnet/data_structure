//
// Created by Umer on 4/28/2021.
//
#include "AVL.h"

template<typename T>
int AVL<T>::height(BstNode<T> *node) {
    if (node != nullptr) return node->height;
    else return 0;
}

template<typename T>
void AVL<T>::update_height(BstNode<T> *node) {
    node->height = max(this->height(node->left), this->height(node->right)) + 1;
}

template<typename T>
void AVL<T>::rebalance(BstNode<T> *rootNode) {
    while (rootNode != nullptr) {
        update_height(rootNode);
        if (this->height(rootNode->left) >= 2 + this->height(rootNode->right)) {
            if (this->height(rootNode->left->left) >= this->height(rootNode->left->right)) {
                // if there is imbalance in left child of left subtree.
                this->rightRotate(rootNode);
            } else {
                // if there is imbalance in left child of right subtree.
                this->leftRotate(rootNode->left);
                this->rightRotate(rootNode);
            }
        } else if (this->height(rootNode->left) + 2 <= this->height(rootNode->right)) {
            if (this->height(rootNode->right->right) >= this->height(rootNode->right->left)) {
                // if there is imbalance in right child of right subtree.
                this->leftRotate(rootNode);
            } else {
                // if there is imbalance in right child of left subtree.
                this->rightRotate(rootNode->right);
                this->leftRotate(rootNode);
            }
        }

        rootNode = rootNode->parent;
    }
}

template<typename T>
void AVL<T>::leftRotate(BstNode<T> *node) {
    auto *y = node->right;
    y->parent = node->parent;
    if (y->parent == nullptr)
        this->root = y;
    else {
        if (y->parent->left == node)
            y->parent->left = y;
        else if (y->parent->right == node)
            y->parent->right = y;
    }
    node->right = y->left;

    if (node->right != nullptr)
        node->right->parent = node;

    y->left = node;
    node->parent = y;
    this->update_height(node);
    this->update_height(y);
}

template<typename T>
void AVL<T>::rightRotate(BstNode<T> *node) {
    auto *y = node->left;
    y->parent = node->parent;
    if (y->parent == nullptr)
        this->root = y;
    else {
        if (y->parent->left == node)
            y->parent->left = y;
        else if (y->parent->right == node)
            y->parent->right = y;
    }

    node->left = y->right;
    if (node->left != nullptr)
        node->left->parent = node;

    y->right = node;
    node->parent = y;
    this->update_height(node);
    this->update_height(y);
}

template<typename T>
void AVL<T>::insert(T data) {
    BST<T>::insert(data);
    auto *node = this->search(this->root, data);
    this->rebalance(node);
}

template<typename T>
void AVL<T>::remove(T data) {
    auto *node = BST<T>::remove(this->root, data);
    this->rebalance(node);
}
