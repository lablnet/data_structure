//
// Created by Umer on 4/25/2021.
//
#include <iostream>
#include <vector>

template<typename T>
int linear_search(std::vector<T> arr, T item)
{
    for (int i = 0; i <= arr.size() - 1; i++) {
        if (arr[i] == item) {
            return i;
        }
    }

    return -1;
}

template<typename T>
int linear_search_r(std::vector<T> arr, T item, int i = 0)
{
    if (i >= arr.size()) {
        return -1;
    }
    if (arr[i] == item) {
        return i;
    }
    return linear_search_r(arr, item, i + 1);
}

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
