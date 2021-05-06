//
// Created by Umer on 5/6/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HASHFUNCTIONS_H
#define DOUBLYLINKEDLIST_H_HASHFUNCTIONS_H

class HashFunctions {
public:
    static int mod(int key, int capacity)
    {
        return key % capacity;
    }
    static int mul(int key, int capacity)
    {
    }
};

#endif //DOUBLYLINKEDLIST_H_HASHFUNCTIONS_H
