#include <iostream>
#include "../trees/AVL/AVL.cpp"

int main ()
{
    AVL<int> a;
    a.insert(20);
    a.insert(11);
    a.insert(15);
    a.insert(12);

    // remove 12 from the tree.
    a.remove(15);

    // height is 2
    std::cout << "height " << a.root->height << std::endl;
    // As root is 12, left is 11 and right is 20, so hence tree is balanced.
    std::cout << "\t" << a.root->data << std::endl;
    std::cout << "      " << "/" << "    " << "\\" << std::endl;
    std::cout << "    " << a.root->left->data ;
    std::cout << "     " << a.root->right->data << std::endl;
    /*
     * Tree look like that.
            12
           /  \
         11    20
    */

    // transverse.
    a.inorder();
    return 0;
}
