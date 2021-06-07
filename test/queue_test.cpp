//
// Created by Umer on 6/7/2021.
//

#include "../Queue/Queue.cpp"
#include <vector>
#include <gtest/gtest.h>

TEST(DataStructure, QueueTest) {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(3);
    ASSERT_EQ(false, q.isEmpty());
    ASSERT_EQ(2, q.size());
    ASSERT_EQ(1, q.dequeue());
    ASSERT_EQ(3, q.dequeue());
    ASSERT_EQ(true, q.isEmpty());

    // Priority Queue
    Queue<int> q1;
    q1.enqueue(1, 1);
    q1.enqueue(0, 3);
    ASSERT_EQ(0, q1.dequeue());
}

