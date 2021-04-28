#include <iostream>
#include "../Queue/Queue.cpp"

int main() {

    // Queue
    Queue<int> q;
    q.enqueue(10, 10);
    q.enqueue(4, 1);
    q.enqueue(6, 2);
    q.enqueue(3, 3);
    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "Dequeue: " << q.dequeue() << std::endl;
    return 0;
}
