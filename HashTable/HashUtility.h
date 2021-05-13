//
// Created by Hp on 5/13/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HASHUTILITY_H
#define DOUBLYLINKEDLIST_H_HASHUTILITY_H
namespace lablnet {
    inline bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    inline int findLeastPrime(int num) {
        for (int i = num; i >= 2; i--) {
            if (isPrime(i)) return i;
        }
        return -1;
    }

    inline int hash_string(std::string key, long capacity) {
        int hash = 0;
        for (int i = 0; i < 5; i++) {
            hash = (256 * hash + key[i]) % capacity;
        }
        return hash;
    }
}


#endif //DOUBLYLINKEDLIST_H_HASHUTILITY_H
