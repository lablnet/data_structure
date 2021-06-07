//
// Created by Umer on 4/25/2021.
//
#include <vector>

// sub list (compare first elem with 2nd one)
template<typename T>
std::vector<T> insertion_sort(std::vector<T> arr)
{
    for (int i = 1; i < arr.size(); i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0  && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return arr;
}
