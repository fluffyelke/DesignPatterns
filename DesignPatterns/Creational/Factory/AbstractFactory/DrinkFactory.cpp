/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DrinkFactory.h"


namespace AbstractFactory {

    DrinkFactory::DrinkFactory() {
        hotFactories["coffee"] = std::make_unique<CoffeeFactory>();
        hotFactories["tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<HotDrink> DrinkFactory::makeDrink(const std::string& type) {
        auto drink = hotFactories[type]->make();
        drink->prepare(150);
        return drink;
    }

    //Functional Factory

    DrinkWithVolumeFactory::DrinkWithVolumeFactory() {
        factories["tea"] = [] () -> std::unique_ptr<Tea> {
            auto tea = std::make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };
        factories["coffee"] = [] () -> std::unique_ptr<Coffee> {
            auto coffee = std::make_unique<Coffee>();
            coffee->prepare(50);
            return coffee;
        };
    }

    std::unique_ptr<HotDrink> DrinkWithVolumeFactory::makeDrink(const std::string& name) {
        return factories[name]();       //Return the factory and call the function.
    }



}
