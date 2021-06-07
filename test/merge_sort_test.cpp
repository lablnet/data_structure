//
// Created by Umer on 6/7/2021.
//

#include "../Algorithm/Sorting/merge_sort.cpp"
#include <vector>
#include <gtest/gtest.h>

TEST(AlgoTest, MergeSort) {
    std::vector<int> list;
    list.push_back(3);
    list.push_back(1);
    list.push_back(2);

    std::vector<int> excepted;
    excepted.push_back(1);
    excepted.push_back(2);
    excepted.push_back(3);

    ASSERT_EQ(excepted, merge_sort(list));
}
