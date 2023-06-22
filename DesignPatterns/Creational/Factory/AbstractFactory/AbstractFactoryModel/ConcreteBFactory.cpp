/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConcreteBFactory.cpp
 * Author: default
 * 
 * Created on June 22, 2023, 8:55 AM
 */

#include "ConcreteBFactory.h"
#include "ConcreteB.h"

namespace AbstractFactory {

    ConcreteBFactory::ConcreteBFactory() {
        std::cout << "Concrete B Factory() Constructor" << std::endl;
    }

    ConcreteBFactory::~ConcreteBFactory() {
        std::cout << "~Concrete B Factory() Destructor" << std::endl;
    }

    std::unique_ptr<IBase> ConcreteBFactory::make() const {
        std::cout << "Concrete B Factory::make() called" << std::endl; 
        return std::make_unique<ConcreteB>();
    }

}