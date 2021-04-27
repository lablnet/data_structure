#include <iostream>
#include "trees/BST/BST.cpp"

int main(void)
{
    BST<int> tree;
    BstNode<int> *root;
    tree.insert(7);
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.insert(4);
    tree.inorder();
    std::cout << std::endl;
    std::cout << "found " << tree.search(4) << std::endl;
    std::cout << "not found: " << tree.search(10);
    return 0;
}