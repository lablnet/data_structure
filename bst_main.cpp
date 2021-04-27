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
    tree.insert(10);
    tree.insert(9);
    tree.insert(8);

    std::cout << "Minimum: " << tree.minimum() << std::endl;
    std::cout << "Maximum: " << tree.maximum() << std::endl;

    tree.inorder();
    std::cout << std::endl;
    std::cout << "found " << tree.search(4) << std::endl;
    std::cout << "not found: " << tree.search(10);

    return 0;
}