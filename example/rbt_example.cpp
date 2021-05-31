#include <iostream>
#include "../trees/RBT/RBT.cpp"

int main()
{
    RBT<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);

    std::cout << "Minimum: " << tree.minimum()->data << std::endl; // 1
    std::cout << "Maximum: " << tree.maximum()->data << std::endl; // 8
    // Successor of 7 is 8
    std::cout << "Successor of " << 7 << " is " << tree.successor(7) << std::endl;
    // Successor of 7 is 6
    std::cout << "Predecessor of " << 7 << " is " << tree.predecessor(7) << std::endl;

    std::cout << "Searching: " << std::endl;
    std::cout << "found 4: " << tree.search(4);
    std::cout << "\tNot Found: " << tree.search(41) << std::endl;

    tree.remove(5); // remove element.

    std::cout << "Inorder" << std::endl;
    tree.inorder();
    std::cout << "Preorder" << std::endl;
    tree.preorder();
    std::cout << "PostOrder" << std::endl;
    tree.postorder();
    std::cout << "LevelOrder" << std::endl;
    tree.levelOrder();

    std::cout << "Hello RBT\n";
    return 0;
}
