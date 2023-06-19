/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "HotDrink.h"


namespace AbstractFactory {
    
    void Tea::prepare(int volume) {
        std::cout << "Take tea bag, boil water, pour  " << volume 
                  <<  "ml, add some lemon" << std::endl;
    }

    void Coffee::prepare(int volume) {
        std::cout << "Grind some beans, boil water, pour  " << volume 
                  <<  "ml, add some cream, enjoy" << std::endl;
    }

}