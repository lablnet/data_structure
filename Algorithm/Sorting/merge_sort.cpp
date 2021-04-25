//
// Created by Umer on 4/25/2021.
//
#include <iostream>
#include <vector>

template<typename T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right)
{
    std::vector<T> result;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // put remaining element into list.
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T> arr)
{
    if (arr.size() <= 1) {
        return arr;
    } else {
        int mid = arr.size() / 2;
        std::vector<T> left_list;
        std::vector<T> right_list;

        // reserve capacity into vector.
        left_list.reserve(mid / 2);
        right_list.reserve(mid / 2);

        // build left and right list.
        for (int i = 0; i < mid; i++) {
            left_list.push_back(arr[i]);
        }
        for (int i = mid; i < arr.size(); i++) {
            right_list.push_back(arr[i]);
        }

        std::vector<T> left = merge_sort(left_list);
        std::vector<T> right = merge_sort(right_list);

        return merge(left, right);
    }
}

int main()
{
    std::vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);

    std::vector<int> sorted = merge_sort(arr);
    for (int i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i] << std::endl;
    }
    return 0;
}
