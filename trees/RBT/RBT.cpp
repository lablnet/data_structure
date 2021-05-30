#include "RBT.h"

template<typename T>
void RBT<T>::leftRotation(RBTNode<T> *node) {
    auto *y = node->right;

    // turn y subtree to node subtree.
    node->right = y->left;

    if (y->left == this->NIL) {
        y->left->parent = node;
    }

    // link node parent to y.
    y->parent = node->parent;

    if (node->parent == nullptr)
        this->root = y;
    else if (node == node->parent->left)
        node->parent->left = y;
    else
        node->parent->right = y;

    y->left = node;
    node->parent = y;
}

template<typename T>
void RBT<T>::rightRotation(RBTNode<T> *node) {
    auto *y = node->left;

    // turn y subtree to node subtree.
    node->left = y->right;
    if (y->right == this->NIL)
        y->right->parent = node;

    // link node parent to y
    y->parent = node->parent;

    if (node->parent == nullptr)
        this->root = y;
    else if (node == node->parent->right)
        node->parent->right = y;
    else
        node->parent->left = y;

    y->right = node;
    node->parent = y;
}

template<typename T>
void RBT<T>::insertFixup(RBTNode<T> *node) {
    // @TODO
    // Add comments for explanations.

    RBTNode<T> *temp;
    while (node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            temp = node->parent->parent->right;
            if (temp->color == RED) {
                node->parent->color = BLACK;
                temp->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    this->leftRotation(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                this->rightRotation(node->parent->parent);
            }
        } else {
            temp = node->parent->parent->left;
            if (temp->color == RED) {
                node->parent->color = BLACK;
                temp->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    this->rightRotation(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                this->leftRotation(node->parent->parent);
            }
        }
        if (node == this->root) break;
    }

    this->root->color = BLACK;
}

template<typename T>
void RBT<T>::insert(T data) {
    // creating node and inserting data.
    auto *temp = new RBTNode<T>();
    // Arbitrary children to maintain the balance.
    temp->left = this->NIL;
    temp->right = this->NIL;
    temp->data = data;
    temp->color = RED;

    RBTNode<T> *y = nullptr;
    RBTNode<T> *rootTemp = this->root;

    // transverse to find the insertion point.
    while (rootTemp != this->NIL) {
        // set y to rootTemp for parent node.
        y = rootTemp;

        // Go, either left or right.
        if (temp->data < rootTemp->data) {
            rootTemp = rootTemp->left;
        } else {
            rootTemp = rootTemp->right;
        }
    }
    // temp parent.
    temp->parent = y;

    // linked the tree.
    if (y == nullptr) {
        this->root = temp;
    } else if (temp->data < y->data) {
        y->left = temp;
    } else {
        y->right = temp;
    }

    // if temp has no parent then simply terminate the function.
    if (temp->parent == nullptr) {
        temp->color = BLACK;
        return;
    }

    // Fix, Red Black Tree violation.
    this->insertFixup(temp);
}

template<typename T>
T RBT<T>::search(T item) {
    RBTNode<T> * s = this->search(this->root, item);
    if (s != nullptr) return s->data;
    return T{};
}

template<typename T>
RBTNode<T> *RBT<T>::search(RBTNode<T> *rootNode, T item) {
    if (rootNode == this->NIL) return nullptr;
    if (item == rootNode->data) {
        return rootNode;
    } else if (item < rootNode->data) {
        return this->search(rootNode->left, item);
    } else if (item > rootNode->data) {
        return this->search(rootNode->right, item);
    }
}

template<typename T>
void RBT<T>::inorder() {
    this->inorder(this->root);
}

template<typename T>
void RBT<T>::inorder(RBTNode<T> *rootNode) {
    if (rootNode == this->NIL) {
        return;
    }
    this->inorder(rootNode->left);
    std::cout << rootNode->data << std::endl;
    this->inorder(rootNode->right);
}

template<typename T>
void RBT<T>::preorder() {
    this->preorder(this->root);
}

template<typename T>
void RBT<T>::preorder(RBTNode<T> *rootNode) {
    if (rootNode == this->NIL) {
        return;
    }
    std::cout << rootNode->data << std::endl;
    this->preorder(rootNode->left);
    this->preorder(rootNode->right);
}

template<typename T>
void RBT<T>::postorder() {
    this->postorder(this->root);
}

template<typename T>
void RBT<T>::postorder(RBTNode<T> *rootNode) {
    if (rootNode == this->NIL) {
        return;
    }
    this->postorder(rootNode->left);
    this->postorder(rootNode->right);
    std::cout << rootNode->data << std::endl;
}

template<typename T>
RBTNode<T> *RBT<T>::minimum(RBTNode<T> *rootNode) {
    auto temp = rootNode;
    while (temp->left != this->NIL) temp = temp->left;
    return temp;
}

template<typename T>
RBTNode<T> *RBT<T>::minimum() {
    return this->minimum(this->root);
}

template<typename T>
RBTNode<T> *RBT<T>::maximum(RBTNode<T> *rootNode) {
    auto temp = rootNode;
    while (temp->right != this->NIL) temp = temp->right;
    return temp;
}
template<typename T>
RBTNode<T> *RBT<T>::maximum() {
    return this->maximum(this->root);
}

template<typename T>
RBTNode<T> *RBT<T>::successor(RBTNode<T> *rootNode) {
    if (rootNode->right != this->NIL) return minimum(rootNode->right);
    auto *temp = rootNode->parent;
    while (temp != this->NIL && rootNode == temp->right) {
        rootNode = temp;
        temp = temp->parent;
    }
    return temp;
}

template<typename T>
T RBT<T>::successor(T item) {
    RBTNode<T> *s = this->search(this->root, item);
    if (s != nullptr) return this->successor(s)->data;
    return T{};
}

template<typename T>
RBTNode<T> *RBT<T>::predecessor(RBTNode<T> *rootNode) {
    if (rootNode->left != this->NIL) return maximum(rootNode->left);
    auto *temp = rootNode->parent;
    while (temp != this->NIL && rootNode == temp->left) {
        rootNode = temp;
        temp = temp->parent;
    }
    return temp;
}

template<typename T>
T RBT<T>::predecessor(T item) {
    RBTNode<T> *s = this->search(this->root, item);
    if (s != nullptr) return this->predecessor(s)->data;
    return T{};
}

template<typename T>
void RBT<T>::deleteFixup(RBTNode<T> *node) {

}

template<typename T>
void RBT<T>::rbTransplant(RBTNode<T> *u, RBTNode<T> *v) {

}

template<typename T>
void RBT<T>::remove(T data) {

}
