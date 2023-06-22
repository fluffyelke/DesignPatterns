/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AbstractFactoryMgr.h"
#include "DrinkFactory.h"
#include <iostream>

namespace AbstractFactory {
    std::unique_ptr<HotDrink> make_drink(const std::string& type) {
        std::unique_ptr<HotDrink> drink;
        if(type == "tea") {
            drink = std::make_unique<Tea>();
            drink->prepare(200);
        }
        else {
            drink = std::make_unique<Coffee>();
            drink->prepare(50);
        }
        return drink;
    }
    void runExample() {
        auto myDrink = make_drink("tea");
        //Instead of using if - statements to create our objects, we can use 
        //DrinkFactory for more organize creation.
        DrinkFactory drinkFactory;
        auto myCoffee = drinkFactory.makeDrink("coffee");
        
        std::cout << "Functional Factory" << std::endl;
        DrinkWithVolumeFactory myFunctionalFactory;
        auto myTea = myFunctionalFactory.makeDrink("tea");
        auto myCoffeeFunc = myFunctionalFactory.makeDrink("coffee");
    }
}