#include <iostream>
#include "trees/Heap/Heap.cpp"

int main()
{
    Heap<int> h;
    h.insert(3);
    h.insert(1);
    h.insert(2);
    std::cout << "MaxHeap : \n";
    //h.sort();
    h.print();


    Heap<int> h2;
    h2.insert(12, MinHeap);
    h2.insert(11, MinHeap);
    h2.insert(13, MinHeap);
    h2.insert(5, MinHeap);
    h2.insert(6, MinHeap);
    h2.insert(7, MinHeap);

    //std::cout << "MinHeap : \n";
    //h2.print();

    std::cout << "sorting... \n";
    h2.sort(MinHeap);
    h2.print();

}
