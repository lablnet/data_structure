//
// Created by Umer on 5/13/2021.
//

#ifndef DOUBLYLINKEDLIST_H_HASHUTILITY_H
#define DOUBLYLINKEDLIST_H_HASHUTILITY_H

#include <typeinfo>

namespace lablnet {

    /**
     * Determine whether the given number is prime?.
     *
     * @param num given number
     *
     * @since 1.0.0
     * @return bool
     */
    inline bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    /**
     * Find the last small prime of given number.
     *
     * @param num given number
     *
     * @since 1.0.0
     * @return int
     */
    inline int findLeastPrime(int num) {
        for (int i = num; i >= 2; i--) {
            if (isPrime(i)) return i;
        }
        return -1;
    }

    /**
     * Convert given string into hash.
     *
     * @param key      given string
     * @param capacity Hash table capacity
     *
     * @bug Known issue
     * @since 1.0.0
     * @return int
     */
    template <typename T>
    inline int hash_string(T key, long capacity) {
        int hash = 0;
        std::string sKey = std::to_string(key);

        for (int i = 0; i < 5; i++) {
            hash = (256 * hash + sKey[i]) % capacity;
        }
        return hash;
    }

    /**
     * Determine the type of template parameter.
     *
     * @param param given parameter
     *
     * @since 1.0.0
     * @return <char *>
     */
    template <typename T>
    inline std::string get_type(T param)
    {
        if (typeid(param).name() == typeid(int).name()) {
            return "int";
        } else if (typeid(param).name() == typeid(float).name()) {
            return "float";
        } else if (typeid(param).name() == typeid(double).name()) {
            return "double";
        } else if (typeid(param).name() == typeid(long).name()) {
            return "long";
        } else if (typeid(param).name() == typeid(long long).name()) {
            return "long long";
        }

        return "string";
    }

}


#endif //DOUBLYLINKEDLIST_H_HASHUTILITY_H
