#include <iostream>
#include "../HashTable/HashTable.cpp"


int main()
{
    HashTable<int, int> h;
    h.insert(1, 5);
    h.insert(3, 6);
    h.insert(5, 16);
    h.insert(12, 52);
    h.insert(33, 61);
    h.insert(54, 161);

    //h.debug();
    //h.erase(5);

    std::cout << "1 = 5: " << h[1] << std::endl;
    std::cout << "3 = 6: " << h[3] << std::endl;
    std::cout << "5 = 16: " << h[5] << std::endl;
    std::cout << "12 = 52: " << h[12] << std::endl;
    std::cout << "33 = 61:  " << h[33] << std::endl;
    std::cout << "54 = 161: " << h[54] << std::endl;

    std::cout << "Hello Hash Tables " << std::endl;
    return 0;
}
