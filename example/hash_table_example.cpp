#include <iostream>
#include "../HashTable/HashTable.cpp"

template <typename K, typename V>
void test(K key, V value)
{

}
int main()
{
    HashTable<int> h;
    test(1, 1.5);
    h.insert(1, 5);
    h.insert(3, 6);

    std::cout << "getting values \n";
    std::cout << "1: " << h[1] << std::endl;
    std::cout << "3: " << h[3] << std::endl;

    std::cout << "Hello Hash Tables " << std::endl;
    return 0;
}
