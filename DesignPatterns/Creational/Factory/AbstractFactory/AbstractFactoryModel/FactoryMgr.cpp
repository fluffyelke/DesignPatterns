/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FactoryMgr.cpp
 * Author: default
 * 
 * Created on June 22, 2023, 8:59 AM
 */

#include "FactoryMgr.h"
#include "ConcreteAFactory.h"
#include "ConcreteBFactory.h"

namespace AbstractFactory {
    
    FactoryMgr::FactoryMgr() {
        std::cout << "FactoryMgr() Constructor" << std::endl;
        factories["concreteA"] = std::make_unique<ConcreteAFactory>();
        factories["concreteB"] = std::make_unique<ConcreteBFactory>();
    }

    FactoryMgr::~FactoryMgr() {
        std::cout << "FactoryMgr() Destructor" << std::endl;
    }

    std::unique_ptr<IBase> FactoryMgr::makeObj(const std::string& type) {
        auto myObj = factories[type]->make();
        myObj->create();
        return myObj;
    }

}