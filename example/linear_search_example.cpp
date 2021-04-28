#include <iostream>
#include <vector>
#include "../Algorithm/Searching/LinearSearch.cpp"

int main()
{
    std::vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);

    std::cout << "search " << linear_search(arr, 3) << std::endl;
    std::cout << "search not found " << linear_search(arr, 13) << std::endl;
    std::cout << "R search " << linear_search_r(arr, 3) << std::endl;
    std::cout << "R search " << linear_search_r(arr, 13) << std::endl;

    return 0;
}
