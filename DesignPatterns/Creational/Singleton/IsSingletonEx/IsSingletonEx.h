/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IsSingletonEx.h
 * Author: default
 *
 * Created on June 22, 2023, 4:17 PM
 */

#ifndef ISSINGLETONEX_H
#define ISSINGLETONEX_H

#include <functional>

namespace SingletonEx {
    
    class SingletonTester {
    public:
        template<typename T>
        bool isSingleton(std::function<T*()> factory);
    };
    
}

#endif /* ISSINGLETONEX_H */

