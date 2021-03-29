//
// Created by M Umer Farooq on 3/26/2021.
//

#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H

template <typename T>
class List {
public:
    T data;
    List *prev;
    List *next;
};

#endif //DATA_STRUCTURE_LIST_H
