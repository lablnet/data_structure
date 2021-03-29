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
        // update the size
        ++this->size;

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

    // update the size.
    ++this->size;
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
    int i = 0;
    while (list != nullptr) {
        std::cout << "index: " << i <<  " item: " << list->data << std::endl;
        list = list->next;
        i++;
    }
}

template<typename T>
int DoublyLinkedList<T>::length() {
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

    // update the size.
    ++this->size;
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

    // update the size.
    this->size = 0;
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

    // update the size.
    --this->size;

    return item;
}

template<typename T>
T DoublyLinkedList<T>::removeLast() {
    T item = this->tail->data;
    if (this->head != nullptr) {
        if (this->head != this->tail) {
            List<T> *prev = this->tail->prev;
            delete this->tail;
            this->tail = prev;
            this->tail->next = nullptr;
        } else {
            delete this->tail;
            this->head = nullptr;
            this->tail = nullptr;
        }
    }
    // update the size.
    --this->size;

    return item;
}

template<typename T>
void DoublyLinkedList<T>::remove(int index) {
    List<T> *list = this->head;
    int i = 0;
    List<T> *pre = this->tail->prev;
    if (this->head != nullptr) {
        if (this->head != this->tail) {
            if (index == 0) {
                this->head = list->next;
                delete list;
                // update the size.
                --this->size;
            } else {
                while (list != nullptr && index != i) {
                    pre = list;
                    i++;
                    list = list->next;
                }
                pre->next = list->next;
                delete list;
                // update the size.
                --this->size;
            }
        }
    }
}

template<typename T>
void DoublyLinkedList<T>::add(int index, T item) {
    List<T> *list = this->head;

    // if head is empty insert add to first place.
    if (this->head == nullptr) {
        this->add(item);
        return;
    }
    // if index is zero or less, prepend it.
    if (index <= 0) {
        this->prepend(item);
        return;
    } else if (index > this->length() - 1) { // if index is grater then append.
        this->add(item);
        return;
    } else {
        // if nothing, then find out the pointer before insertion.
        int i = 0;
        while (list != nullptr && i < index - 1) {
            list = list->next;
            i++;
        }
        // make temp list.
        auto *tmp = new List<T>();
        // list is now point to the pointer before insertion.
        // so next pointer is our place to insert item/data
        tmp->next = list->next;
        tmp->data = item;
        // get the previous pointer, as it's doubly linked list.
        tmp->prev = list;
        // finally update the next items of list.
        list->next = tmp;

        // update the size.
        ++this->size;
    }
}
