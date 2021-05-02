#include <iostream>
#include "../trees/AVL/AVL.cpp"

int main ()
{
    AVL<int> a;
    a.insert(20);
    a.insert(11);
    a.insert(15);
    a.insert(16);
    a.insert(25);
    a.insert(24);
    a.insert(26);

    // if, it print 11 then tree is balanced.
    std::cout << "check: " << a.root->left->left->data << std::endl;
    //a.remove(15);
    //std::cout << "check: " << a.root->left->data << std::endl;
    a.inorder();
    return 0;
}
