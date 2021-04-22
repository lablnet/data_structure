#include "Queue.h"

template<typename T>
void Queue<T>::enqueue(T item, int priority = 0)
{
    auto *temp = new QueueItem<T>();
    temp->data = item;
    temp->priority = priority;
    this->list.add(*temp);
}

template<typename T>
T Queue<T>::dequeue()
{
    QueueItem<T> item;
    int size = this->list.size;
    int index = 0;
    int priority = -1;
    T data;
    for (int i = 0; i < size; i++) {
        item = this->list.get(i);
        if (priority < item.priority) {
            index = i;
            data = item.data;
            priority = item.priority;
        }
    }

    this->list.remove(index);
    return data;
}

template<typename T>
int Queue<T>::size()
{
    return list.length();
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return list.length() == 0;
}
