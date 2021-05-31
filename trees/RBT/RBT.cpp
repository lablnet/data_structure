//
// Created by Umer on 5/30/2021.
//
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
    RBTNode<T> *temp;
    while (node != this->root && node->parent->color == RED) {
        // Case 1: when there is violation in left tree/subtree
        if (node->parent == node->parent->parent->left) {
            temp = node->parent->parent->right;

            // Case 1.a: when both temp and temp parent are red, a violation of property 4 occurs.
            if (temp->color == RED) {
                node->parent->color = BLACK;
                temp->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                // Case 1.b: if node is equal to node.parent.right then transform node to node parent.
                if (node == node->parent->right) {
                    node = node->parent;
                    this->leftRotation(node);
                }
                // Case 1.c: Make the child red and parent black.
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                this->rightRotation(node->parent->parent);
            }
        } else {
            // Case 2: when there is violation in right tree/subtree
            temp = node->parent->parent->left;

            // Case 2.a: when both temp and temp parent are red, a violation of property 4 occurs.
            if (temp->color == RED) {
                node->parent->color = BLACK;
                temp->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                // Case 2.b: if node is equal to node.parent.left then transform node to node parent.
                if (node == node->parent->left) {
                    node = node->parent;
                    this->rightRotation(node);
                }
                // Case 2.c: Make the child red and parent black.
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                this->leftRotation(node->parent->parent);
            }
        }
    }

    // root should be black.
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
    this->size++;

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
void RBT<T>::levelOrder() {
    this->transverse_tree_level_order();
}

template <typename T>
void RBT<T>::transverse_tree_level_order()
{
    // height: 2 . log2(N)
    int height = 2 * std::log2(this->size + 1);
    for (int i = 0; i < height; i++) this->levelOrder(this->root, i);
}

template<typename T>
void RBT<T>::levelOrder(RBTNode<T> *rootNode, int i) {
    if (rootNode == this->NIL) return;
    if (i == 0) std::cout << rootNode->data << "\n";
    else {
        levelOrder(rootNode->left, i - 1);
        levelOrder(rootNode->right, i - 1);
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
    RBTNode<T> *w;
    while (node != this->root && node->color == BLACK) {
        // Case 1: when there is violation in left tree/subtree
        if (node == node->parent->left) {
            w = node->parent->right;

            // Case 1.a: if node w is red.
            if (w->color == RED) {
                w->color = BLACK;
                node->parent->color = RED;
                this->leftRotation(node->parent);
                w = node->parent->right;
            }

            // Same below cases applies to case 2.
            // Case 1.b: if node w is black and both of it's children.
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                node = node->parent;
            } else {
                // Case 1.c: if node w is black, it's left child is red, and right child is black
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    this->rightRotation(w);
                    w = node->parent->right;
                }
                // Case 1.d: if node w is black and it's right child is red.
                w->color = node->parent->color;
                node->parent->color = BLACK;
                w->right->color = BLACK;
                this->leftRotation(node->parent);
                node = this->root;
            }
        } else {
            // Case 1: when there is violation in right tree/subtree
            w = node->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                node->parent->color = RED;
                this->rightRotation(node->parent);
                w = node->parent->right;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                node = node->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    this->leftRotation(w);
                    w = node->parent->right;
                }
                w->color = node->parent->color;
                node->parent->color = BLACK;
                w->left->color = BLACK;
                this->rightRotation(node->parent);
                node = this->root;
            }
        }

        node->color = BLACK;
    }
}

template<typename T>
void RBT<T>::rbTransplant(RBTNode<T> *u, RBTNode<T> *v) {
    // if u, does not have parent, then v is root.
    if (u->parent == this->NIL)
        this->root = v;
    // if u is left subtree of it's parent, then it must replace by v
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        // If u is right subtree of it's parent, then it must replace by u.
        u->parent->right = v;

    // v and u must have same parents.
    v->parent = u->parent;
}

template<typename T>
void RBT<T>::remove(T data) {
    // Get the node we are looking for.
    RBTNode<T> *node = this->search(this->root, data);
    if (node == nullptr) return;
    auto *y = node;
    RBTNode<T> *x;
    RBColors original_color = y->color;

    // Case 1: Node has one child either left or right.
    if (node->left == this->NIL) {
        x = node->right;
        this->rbTransplant(node, node->right);
    } else if (node->right == this->NIL) {
        x = node->left;
        this->rbTransplant(node, node->left);
    } else {
        // Case 2: node has two children or no child.

        y = this->minimum(node->right);
        original_color = y->color;
        if (y->parent == node)
            x->parent = y;
        else {
            this->rbTransplant(y, y->right);
            y->right = node->right;
        }
        this->rbTransplant(node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }
    if (original_color == BLACK)
        this->deleteFixup(x);
}
