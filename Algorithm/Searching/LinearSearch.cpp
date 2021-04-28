//
// Created by Umer on 4/25/2021.
//
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
