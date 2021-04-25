//
// Created by Umer on 4/25/2021.
//
#include <iostream>
#include <vector>

template<typename T>
std::vector<T> bubble_sort(std::vector<T> arr)
{
    for (int i = 0; i <= arr.size() - 1; i++) {
        for (int j = 0; j <= arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::iter_swap(&arr[j + 1], &arr[j]);
            }
        }
    }

    return arr;
}

int main()
{
    std::vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);

    std::vector<int> sorted = bubble_sort(arr);
    for (int i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i] << std::endl;
    }
    return 0;
}
