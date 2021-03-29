#include "Queue.h"

template<typename T>
void Queue<T>::enqueue(T item) {
    list.add(item);
}

template<typename T>
T Queue<T>::dequeue() {
    return list.removeFIrst();
}

template<typename T>
int Queue<T>::size() {
    return list.length();
}

template<typename T>
bool Queue<T>::isEmpty()  {
    return list.length() == 0;
}

template<typename T>
void Queue<T>::display()  {
    return list.display();
}
