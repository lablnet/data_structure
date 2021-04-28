#include <iostream>
#include <vector>
#include "../Algorithm/Sorting/merge_sort.cpp"

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
