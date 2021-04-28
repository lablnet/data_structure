#include <iostream>
#include "../trees/BST/BST.cpp"

int main(void)
{
    BST<int> tree;
    tree.insert(7);
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.insert(4);
    tree.insert(10);
    tree.insert(9);
    tree.insert(8);

    std::cout << "Minimum: " << tree.minimum()->data << std::endl; // 3
    std::cout << "Maximum: " << tree.maximum()->data << std::endl; // 10
    // Successor of 9 is 7
    std::cout << "Successor of " << 9 << " is " << tree.successor(9) << std::endl;
    std::cout << "Predecessor of " << 9 << " is " << tree.predecessor(9) << std::endl;

    tree.remove(10);
    tree.inorder();
    // 3, 4, 5, 6, 7, 8, 9, 10
    std::cout << std::endl;
    std::cout << "found " << tree.search(4) << std::endl; // Found 10
    std::cout << "not found: " << tree.search(121); // not found 0

    return 0;
}