#include <iostream>
#include "Stack/Stack.cpp"

int main() {
    // Stack
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "Size: " << s.size() << std::endl;
    std::cout << "Peak: " << s.peak() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;
    s.display();
    return 0;
}
