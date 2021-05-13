//
// Created by Umer on 5/7/2021.
//

#ifndef H_ENV_H
#define H_ENV_H

// for windows
#if _WIN32 || _WIN64
    #if _WIN64
        #define ENV64BIT
    #else
        #define ENV32BIT
    #endif
#endif

// for GCC
#if __GNUC__
    #if __x86_64__ || __ppc64__
        #define ENV64BIT
    #else
        #define ENV32BIT
    #endif
#endif


#endif //H_ENV_H
