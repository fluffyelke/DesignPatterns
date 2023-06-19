/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HotDrinkFactory.h
 * Author: default
 *
 * Created on June 19, 2023, 10:37 AM
 */

#ifndef HOTDRINKFACTORY_H
#define HOTDRINKFACTORY_H

#include "HotDrink.h"


namespace AbstractFactory {
    //This is the abstract factory class
    struct HotDrinkFactory {
        virtual std::unique_ptr<HotDrink> make() const = 0;
    };
    
    struct TeaFactory : public HotDrinkFactory {
        std::unique_ptr<HotDrink> make() const override {
            return std::make_unique<Tea>();
        }
    };
    struct CoffeeFactory : public HotDrinkFactory {
        std::unique_ptr<HotDrink> make() const override {
            return std::make_unique<Coffee>();
        }
    };
}

#endif /* HOTDRINKFACTORY_H */

