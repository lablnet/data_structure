//
// Created by Umer on 6/7/2021.
//

#include "../Stack/Stack.cpp"
#include <vector>
#include <gtest/gtest.h>

TEST(DataStructure, StackTest) {
    Stack<int> s;
    s.push(1);
    s.push(4);
    ASSERT_EQ(false, s.isEmpty());
    ASSERT_EQ(2, s.size());
    ASSERT_EQ(4, s.peak());
    ASSERT_EQ(4, s.pop());
    ASSERT_EQ(1, s.pop());
    ASSERT_EQ(true, s.isEmpty());
    ASSERT_EQ(0, s.size());
}

