#include "Stack.h"

template<typename T>
void Stack<T>::push(T item) {
    list.add(item);
}

template<typename T>
T Stack<T>::pop() {
    return list.removeLast();
}
template<typename T>
bool Stack<T>::isEmpty() {
    return list.length() == 0;
}

template<typename T>
void Stack<T>::display() {
    return list.display();
}

template<typename T>
T Stack<T>::size() {
    return list.length();
}

template<typename T>
T Stack<T>::peak() {
    return list.getLast();
}
