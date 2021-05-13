//
// Created by Hp on 5/6/2021.
//

#include <iostream>
#include "../Applications/Dict/Dict.cpp"

int main()
{
    Dict<int, int> d;
    d.insert(1,5);
    d.insert(2, 25);
    //d[2] = 51;
    //d.clear(); // clear the dict.

    std::cout << "first: " << d.pop(1, 12) << std::endl;
    std::cout << "first: " << d.get(1, 12) << std::endl;

    std::cout << "Hello, Dict \n";
    return 0;
}
