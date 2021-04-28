//
// Created by Umer on 4/25/2021.
//
#include <vector>

// Compares adjacent element and swap if condition satisfied.
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
