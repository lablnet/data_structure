#include <iostream>
#include "../Applications/List/List.cpp"

int main()
{
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    std::cout << "0: " << list[0] << std::endl;
    std::cout << "1: " << list[1] << std::endl;
    std::cout << "2: " << list[2] << std::endl;

    list.insert(0, 12);
    list.prepend(124);
    list.remove(12);
    list.sort();
    int *arr = new int[2];
    arr[0] = 14;
    arr[1] = 16;
    list.extend(arr, 2);
    list.reverse();
    std::cout << "adding into index: " << std::endl;
    std::cout << "0: " << list[0] << std::endl;
    std::cout << "1: " << list[1] << std::endl;
    std::cout << "2: " << list[2] << std::endl;
    std::cout << "3: " << list.pop() << std::endl;

    std::cout << "index of 2: " << list.index(2) << std::endl;
    std::cout << "count " << list.count(1) << std::endl;
    std::cout << "Size " << list.size() << std::endl;
    std::cout << "Capacity " << list.capacity() << std::endl;
    return 0;
}