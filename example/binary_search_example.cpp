#include <iostream>
#include <vector>
#include "../Algorithm/Searching/BinarySearch.cpp"

int main()
{
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    // we considered our array are sorted.

    std::cout << "search " << binary_search(arr, 3) << std::endl;
    std::cout << "search not found " << binary_search(arr, 13) << std::endl;
    std::cout << "R search " << binary_search_r(arr, 3, 0, arr.size() - 1) << std::endl;
    std::cout << "R search " << binary_search_r(arr, 13, 0, arr.size() - 1) << std::endl;
    return 0;
}
