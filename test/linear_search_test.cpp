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
ASSERT_EQ(3, LinearSearch(list, 3));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
