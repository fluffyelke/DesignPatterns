/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConcreteA.cpp
 * Author: default
 * 
 * Created on June 22, 2023, 8:41 AM
 */

#include <iostream>

#include "ConcreteA.h"

namespace AbstractFactory {

    ConcreteA::ConcreteA() {
        std::cout << "Concrete A() constructor" << std::endl;
    }

    ConcreteA::~ConcreteA() {
        std::cout << "~Concrete A() Destructor" << std::endl;
    }

    void ConcreteA::create() {
        std::cout << "Concrete A::create() method called" << std::endl;
    }

}

