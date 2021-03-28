#include "DoublyLinkedList.h"
#include <iostream>

template<typename T>
void DoublyLinkedList<T>::add(T item) {
    // Get new memory/ Create new list.
    auto *list = new List<T>(); //List<T> *list = new List<T>();

    // Set list property.
    list->data = item;
    list->next = nullptr;
    list->prev = this->tail;

    // if this is first item, set it to head.
    if (this->head == nullptr) {
        this->head = list;
        this->tail = nullptr;
        return;
    }

    // if not, make temp head and next the pointer
    List<T> *temp = this->head;
    while (temp->next != nullptr ) {
        temp = temp->next;
    }
    temp->next = list;

    // update the tail of list.
    this->tail = list;
}

template<typename T>
T DoublyLinkedList<T>::get(int index) {
    int i = 0;
    List<T> *list = this->head;
    while (list != nullptr) {

        if (i == index) {
            return list->data;
        }
        i++;
        list = list->next;
    }

    return 0;
}

template<typename T>
T DoublyLinkedList<T>::getFirst() {
    return this->head->data;
}

template<typename T>
T DoublyLinkedList<T>::getLast() {
    return this->tail->data;
}

template<typename T>
void DoublyLinkedList<T>::display() {
    List<T> *list = this->head;
    while (list != nullptr) {
        std::cout << "item: " << list->data << std::endl;
        list = list->next;
    }
}

template<typename T>
int DoublyLinkedList<T>::length() {
    List<T> *list = this->head;

    while (list != nullptr) {
        this->size++;
        list = list->next;
    }

    return this->size;
}

template<typename T>
int DoublyLinkedList<T>::indexOf(T item) {
    int index = -1;
    int i = 0;
    List<T> *list = this->head;
    while (list != nullptr) {
        if (list->data == item) {
            index = i;
            return index;
        }
        i = i + 1;
        list = list->next;
    }

    return index;
}

template<typename T>
int DoublyLinkedList<T>::lastIndexOf(T item) {
    int index = -1;
    int i = 0;
    List<T> *list = this->head;
    while (list != nullptr) {
        if (list->data == item) index = i;
        i = i + 1;
        list = list->next;
    }

    return index;
}

template<typename T>
void DoublyLinkedList<T>::prepend(T item) {
    List<T> *list = new List<T>();
    list->data = item;
    list->next = this->head;
    this->head = list;
    list->prev = nullptr;

    if (this->tail == nullptr) {
        this->tail = list;
    }
}

template<typename T>
void DoublyLinkedList<T>::replace(int index, T item) {
    List<T> *list = this->head;
    int i = 0;

    while (list != nullptr) {
        if (i == index) {
            list->data = item;
            return;
        }
        i++;
        list = list->next;
    }
}

template<typename T>
void DoublyLinkedList<T>::replaceByValue(T old, T item) {
    List<T> *list = this->head;
    while (list != nullptr) {
        if (old == list->data) {
            list->data = item;
            return;
        }
        list = list->next;
    }
}

template<typename T>
void DoublyLinkedList<T>::flush() {
    List<T> *list = this->head;
    while (list != nullptr) {
        List<T> * tmp = list;
        delete tmp;
        list = list->next;
    }

    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
T DoublyLinkedList<T>::search(T item) {
    //todo
    return nullptr;
}

template<typename T>
T DoublyLinkedList<T>::removeFIrst() {
    T item = this->head->data;
    if (this->head != nullptr) {
        if (this->head != this->tail) {
            List<T> *list = this->head->next;
            delete this->head;
            this->head = list;
            this->head->prev = nullptr;
        } else {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        }
    }

    return item;
}

template<typename T>
T DoublyLinkedList<T>::removeLast() {
    // todo
}

template<typename T>
void DoublyLinkedList<T>::remove(int index) {
    // todo
}

template<typename T>
void DoublyLinkedList<T>::add(int index, T item) {
    // todo
}
