/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConcreteB.cpp
 * Author: default
 * 
 * Created on June 22, 2023, 8:42 AM
 */

#include "ConcreteB.h"
namespace AbstractFactory {

    ConcreteB::ConcreteB() {
        std::cout << "Concrete B() Constructor" << std::endl;
    }

    ConcreteB::~ConcreteB() {
        std::cout << "~Conrete B() Destructor" << std::endl;
    }

    void ConcreteB::create() {
        std::cout << "Concrete B::create() method called" << std::endl;
    }
    
}

