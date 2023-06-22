/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "RunFactory.h"
#include "FactoryMgr.h"


namespace AbstractFactory {
    void runMyBaseFactoryProgram() {
        FactoryMgr obj;
        
        auto myConcreteA = obj.makeObj("concreteA");
        auto myConcreteB = obj.makeObj("concreteB");
    }
}