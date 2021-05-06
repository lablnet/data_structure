#include <iostream>
#include "../HashTable/HashTable.cpp"


int main()
{
    HashTable<int> h;
    h.insert(1, 5);
    h.insert(3, 6);

    std::cout << "getting values \n";
    std::cout << "1: " << h[1] << std::endl;
    std::cout << "3: " << h[3] << std::endl;

    std::cout << "Hello Hash Tables " << std::endl;
    return 0;
}
