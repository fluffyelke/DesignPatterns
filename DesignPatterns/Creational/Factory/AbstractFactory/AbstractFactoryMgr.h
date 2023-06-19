/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractFactoryMgr.h
 * Author: default
 *
 * Created on June 19, 2023, 10:46 AM
 */

#ifndef ABSTRACTFACTORYMGR_H
#define ABSTRACTFACTORYMGR_H

#include "HotDrinkFactory.h"

namespace AbstractFactory {
    extern std::unique_ptr<HotDrink> make_drink(const std::string& type);
    
    extern void runExample();
}

#endif /* ABSTRACTFACTORYMGR_H */

