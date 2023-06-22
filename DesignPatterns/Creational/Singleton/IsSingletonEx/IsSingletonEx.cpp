/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "IsSingletonEx.h"


namespace SingletonEx {
    template<typename T>
    bool SingletonTester::isSingleton(std::function<T*()> factory) {
        T* first = factory();
        T* second = factory();
        return first == second;
    }
}