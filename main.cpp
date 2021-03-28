#include <iostream>
#include <string>
#include "List/SinglyLinkedList.cpp"

int main() {
    //SinglyLinkedList<int> list(1, 2, 3, 4, 5);
    SinglyLinkedList<int> list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.add(9);
    // list contains
    // [1, 2, 3, 4, 5, 6, 7, 8, 9]
    list.prepend(10);
    list.prepend(11);
    list.prepend(13);
    // list contains
    // [13, 11, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    list.replace(6, 12);
    list.replaceByValue(12, 13);
    // list contains
    // [12, 11, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    std::cout << "index: 1 " << list.get(1) << std::endl;

    std::cout << "first: " << list.getFirst() << std::endl;
    std::cout << "Last: " << list.getLast() << std::endl;
    std::cout << "indexOf(6) " << list.indexOf(6) << std::endl;
    std::cout << "lastIndexOf(6) " << list.lastIndexOf(6) << std::endl;
    std::cout << "Size " << list.length() << std::endl;
    std::cout << "remove first: " << list.removeFIrst() << std::endl;
    std::cout << "remove last: " << list.removeLast() << std::endl;
    list.remove(1);
    list.display();
    return 0;
}
