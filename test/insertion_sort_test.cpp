//
// Created by Umer on 6/7/2021.
//

#include "../Algorithm/Sorting/insertionSort.cpp"
#include <vector>
#include <gtest/gtest.h>

TEST(AlgoTest, InsertionSort) {
    std::vector<int> list;
    list.push_back(3);
    list.push_back(1);
    list.push_back(0);

    std::vector<int> excepted;
    excepted.push_back(0);
    excepted.push_back(1);
    excepted.push_back(3);

    ASSERT_EQ(excepted, insertion_sort(list));
}
