/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "IBaseFactory.h"

namespace AbstractFactory {

    IBaseFactory::IBaseFactory() {
        std::cout << "IBaseFactory() Constructor" << std::endl;
    }

    IBaseFactory::~IBaseFactory() {
        std::cout << "IBaseFactory() Destructor" << std::endl;
    }

}