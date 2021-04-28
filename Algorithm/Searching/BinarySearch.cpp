//
// Created by Umer on 4/25/2021.
//
#include <vector>

template<typename T>
int binary_search(std::vector<T> arr, T item)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] < item) {
            left = mid + 1;
        } else if (arr[mid] > item) {
            right = mid - 1;
        } else if (arr[mid] == item) {
            return mid;
        }
    }

    return -1;
}

template<typename T>
int binary_search_r(std::vector<T> arr, T item, int left, int right)
{
    if (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] < item) {
            return binary_search_r(arr, item, mid + 1, right);
        } else if (arr[mid] > item) {
            return binary_search_r(arr, item, left, mid - 1);
        } else if (arr[mid] == item) {
            return mid;
        }
    }
    return -1;
}

