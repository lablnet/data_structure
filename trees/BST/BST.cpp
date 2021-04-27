//
// Created by Umer on 4/26/2021.
//
#include <iostream>
#include "BST.h"
template<typename T>
void BST<T>::insert(T item) {
    this->insert(this->root, item);
}
template<typename T>
BstNode<T> *BST<T>::insert(BstNode<T> *rootNode, T item) {
    if (!rootNode) {
        this->root = new BstNode<T>();
        this->root->data = item;
        this->root->left = nullptr;
        this->root->right = nullptr;
        return this->root;
    }
    if (item < rootNode->data) {
        rootNode->left = this->insert(rootNode->left, item);
    } else {
        rootNode->right = this->insert(rootNode->right, item);
    }
    this->root = rootNode;
    return rootNode;
}

template<typename T>
void BST<T>::inorder() {
    this->inorder(this->root);
}

template<typename T>
void BST<T>::inorder(BstNode<T> *rootNode) {
    if (rootNode == nullptr) {
        return;
    }
    this->inorder(rootNode->left);
    std::cout << rootNode->data << std::endl;
    this->inorder(rootNode->right);
}

template<typename T>
T BST<T>::search(T item) {
    BstNode<T> * s = this->search(this->root, item);
   if (s->data == item) {
       return s->data;
   } else {
       return 1;
   }
}

template<typename T>
BstNode<T> *BST<T>::search(BstNode<T> *rootNode, T item) {
    if (item == rootNode->data) {
        return rootNode;
    } else if (item < rootNode->data) {
        return this->search(rootNode->left, item);
    } else if (item > rootNode->data) {
        return this->search(rootNode->right, item);
    } else {
        return nullptr;
    }
}
