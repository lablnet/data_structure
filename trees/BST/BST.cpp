//
// Created by Umer on 4/26/2021.
//
#include <iostream>
#include "BST.h"

template<typename T>
void BST<T>::insert(T item) {
    this->root  = this->insert(this->root, item);
}

template<typename T>
BstNode<T> *BST<T>::insert(BstNode<T> *rootNode, T item) {
    if (!rootNode) {
        auto *temp = new BstNode<T>();
        temp->data = item;
        this->n++;
        return temp;
    }
    BstNode<T> *temp;
    if (item < rootNode->data) {
        temp = this->insert(rootNode->left, item);
        rootNode->left = temp;
        temp->parent = rootNode;
    } else {
        temp = this->insert(rootNode->right, item);
        rootNode->right = temp;
        temp->parent = rootNode;
    }

    return rootNode;
}

template<typename T>
int BST<T>::find_height_of_tree(BstNode<T> *rootNode) {
    if (rootNode == nullptr) return 0;
    int left = this->find_height_of_tree(rootNode->left);
    int right = this->find_height_of_tree(rootNode->right);
    return 1 + max(left, right);
}

template <typename T>
void BST<T>::transverse_tree_level_order()
{
    int height = this->find_height_of_tree(this->root);
    for (int i = 0; i < height; i++) this->levelOrder(this->root, i);
}

template<typename T>
void BST<T>::levelOrder(BstNode<T> *rootNode, int i) {
    if (rootNode == nullptr) return;
    if (i == 0) std::cout << rootNode->data << "\n";
    else {
        levelOrder(rootNode->left, i - 1);
        levelOrder(rootNode->right, i - 1);
    }
}

template<typename T>
void BST<T>::levelOrder() {
    this->transverse_tree_level_order();
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
void BST<T>::preorder() {
    this->preorder(this->root);
}

template<typename T>
void BST<T>::preorder(BstNode<T> *rootNode) {
    if (rootNode == nullptr) {
        return;
    }
    std::cout << rootNode->data << std::endl;
    this->preorder(rootNode->left);
    this->preorder(rootNode->right);
}

template<typename T>
void BST<T>::postorder() {
    this->postorder(this->root);
}

template<typename T>
void BST<T>::postorder(BstNode<T> *rootNode) {
    if (rootNode == nullptr) {
        return;
    }
    this->postorder(rootNode->left);
    this->postorder(rootNode->right);
    std::cout << rootNode->data << std::endl;
}


template<typename T>
T BST<T>::search(T item) {
    BstNode<T> * s = this->search(this->root, item);
    if (s != nullptr) return s->data;
    return T{};
}

template<typename T>
BstNode<T> *BST<T>::search(BstNode<T> *rootNode, T item) {
    if (rootNode == nullptr) return nullptr;
    if (item == rootNode->data) {
        return rootNode;
    } else if (item < rootNode->data) {
        return this->search(rootNode->left, item);
    } else if (item > rootNode->data) {
        return this->search(rootNode->right, item);
    }
}

template<typename T>
BstNode<T> *BST<T>::minimum(BstNode<T> *rootNode) {
    auto temp = rootNode;
    while (temp->left != nullptr) temp = temp->left;
    return temp;
}

template<typename T>
BstNode<T> *BST<T>::minimum() {
    return this->minimum(this->root);
}

template<typename T>
BstNode<T> *BST<T>::maximum(BstNode<T> *rootNode) {
    auto temp = rootNode;
    while (temp->right != nullptr) temp = temp->right;
    return temp;
}
template<typename T>
BstNode<T> *BST<T>::maximum() {
    return this->maximum(this->root);
}

template<typename T>
BstNode<T> *BST<T>::successor(BstNode<T> *rootNode) {
    if (rootNode->right != nullptr) return minimum(rootNode->right);
    auto *temp = rootNode->parent;
    while (temp != nullptr && rootNode == temp->right) {
        rootNode = temp;
        temp = temp->parent;
    }
    return temp;
}

template<typename T>
T BST<T>::successor(T item) {
    BstNode<T> *s = this->search(this->root, item);
    if (s != nullptr) return this->successor(s)->data;
    return T{};
}

template<typename T>
BstNode<T> *BST<T>::predecessor(BstNode<T> *rootNode) {
    if (rootNode->left != nullptr) return maximum(rootNode->left);
    auto *temp = rootNode->parent;
    while (temp != nullptr && rootNode == temp->left) {
        rootNode = temp;
        temp = temp->parent;
    }
    return temp;
}

template<typename T>
T BST<T>::predecessor(T item) {
    BstNode<T> *s = this->search(this->root, item);
    if (s != nullptr) return this->predecessor(s)->data;
    return T{};
}

template<typename T>
BstNode<T> *BST<T>::remove(BstNode<T> *rootNode, T item) {
    BstNode<T> *s = this->search(rootNode, item);
    if (s == nullptr) return nullptr;

    // if node with no or only one child
    if (s->left == nullptr) {
        auto *temp = rootNode->right;
        delete [] rootNode;
        this->n--;
        return temp;
    } else if (s->right == nullptr) {
        auto *temp = rootNode->left;
        delete [] rootNode;
        this->n--;
        return temp;
    } else {
        // if node have two children.
        auto *temp = this->minimum(rootNode->right);
        rootNode->data = temp->data;
        rootNode->right = this->remove(rootNode->right, temp->data);
    }

    return rootNode;
}

template <typename T>
void BST<T>::remove(T item)
{
    this->root = this->remove(this->root, item);
}
