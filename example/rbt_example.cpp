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

    std::cout << "Searching: " << std::endl;
    std::cout << "found 4: " << tree.search(4);
    std::cout << "\tNot Found: " << tree.search(41) << std::endl;

    tree.remove(5);
    std::cout << "Inorder" << std::endl;
    tree.inorder();
    std::cout << "Preorder" << std::endl;
    tree.preorder();
    std::cout << "PostOrder" << std::endl;
    tree.postorder();
    std::cout << "Hello RBT\n";
    return 0;
}
