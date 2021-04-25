#include <iostream>
#include "trees/Heap/Heap.cpp"

int main()
{
    Heap<int> h(MaxHeap, 3, 1, 2, 3);
    std::cout << "MaxHeap : \n";
    h.print();
    Heap<int> h2;
    h2.insert(2, MinHeap);
    h2.insert(3, MinHeap);
    h2.insert(1, MinHeap);
    std::cout << "MinHeap : \n";
    h2.print();

    std::cout << "sorting... \n";
    h2.sort();
    h2.print();

}
