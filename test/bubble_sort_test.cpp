//
// Created by Umer on 6/7/2021.
//

#include "../Algorithm/Sorting/BubbleSort.cpp"
#include <vector>
#include <gtest/gtest.h>

TEST(AlgoTest, BubbleSort) {
    std::vector<int> list;
    list.push_back(3);
    list.push_back(1);
    list.push_back(2);

    std::vector<int> excepted;
    excepted.push_back(1);
    excepted.push_back(2);
    excepted.push_back(3);

    ASSERT_EQ(excepted, bubble_sort(list));
}
