/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConcreteAFactory.cpp
 * Author: default
 * 
 * Created on June 22, 2023, 8:51 AM
 */

#include "ConcreteAFactory.h"
#include "ConcreteA.h"

namespace AbstractFactory {

    ConcreteAFactory::ConcreteAFactory() {
        std::cout << "Concrete A Factory() Constructor" << std::endl;
    }

    ConcreteAFactory::~ConcreteAFactory() {
        std::cout << "~Concrete A Factory() Destructor" << std::endl;
    }

    std::unique_ptr<IBase> ConcreteAFactory::make() const {
        std::cout << "Concrete A Factory::make() called" << std::endl; 
        return std::make_unique<ConcreteA>();
    }

}
