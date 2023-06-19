/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DrinkFactory.h
 * Author: default
 *
 * Created on June 19, 2023, 10:54 AM
 */

#ifndef DRINKFACTORY_H
#define DRINKFACTORY_H

#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include <map>
#include <functional>

namespace AbstractFactory {
    //Concrete Factory for using the abstract factory HotDrinkFactor class
    class DrinkFactory {
        std::map<std::string, std::unique_ptr<HotDrinkFactory>> hotFactories;
        
    public:
        DrinkFactory();
        
        std::unique_ptr<HotDrink> makeDrink(const std::string& type);
    };
    
    //Functional Factory, using lambda instead of object oriented aproach,
    class DrinkWithVolumeFactory {
        std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;
    public:
        DrinkWithVolumeFactory();
        std::unique_ptr<HotDrink> makeDrink(const std::string& name);
    };
}

#endif /* DRINKFACTORY_H */

