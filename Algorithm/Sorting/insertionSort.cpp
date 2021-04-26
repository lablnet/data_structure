//
// Created by Umer on 4/25/2021.
//
#include <iostream>
#include <vector>

// sub list (compare first elem with 2nd one)
template<typename T>
std::vector<T> insertion_sort(std::vector<T> arr)
{
    for (int i = 1; i <= arr.size(); i++) {
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

int main()
{
    std::vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);

    std::vector<int> sorted = insertion_sort(arr);
    for (int i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i] << std::endl;
    }
    return 0;
}
