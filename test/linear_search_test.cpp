//
// Created by Umer on 6/1/2021.
//

#include "../Algorithm/Searching/LinearSearch.cpp"
#include <vector>
#include <gtest/gtest.h>

TEST(AlgoTest_l, L_Search) {
std::vector<int> list;
for (int i = 0; i <= 10; i++) {
list.push_back(i);
}
ASSERT_EQ(3, linear_search(list, 3));
}
