/* 
 * File:   main.cpp
 * Author: default
 *
 * Created on May 31, 2023, 11:44 AM
 */

#include <cstdlib>
#include <iostream>

#include "Solid/SingleResponsibilityPrinciple/Journal.h"
#include "Solid/OpenClosedPrinciple/Product.h"
#include "Solid/LiskovSubstitutionPrinciple/LiskovSubstitutionPrinciple.h"
#include "Solid/DependencyInversionPrinciple/DependencyInversionPrinciple.h"
#include "Creational/Builder/LifeWithoutBuilder.h"
#include "utils/Utils.h"
#include "Creational/Builder/Builder/Builder.h"
#include "Creational/Builder/Builder/FluentBuilder.h"
#include "Creational/Builder/GroovyStyleBuilder/GroovyStyleBuilder.h"
#include "Creational/Builder/BuilderFacets/PersonExample.h"
#include "Creational/Builder/Excercise/BuilderExcercise.h"
#include "Creational/Factory/FactoryMethod/FactoryMethod.h"
#include "Creational/Factory/Factory/Factory.h"
#include "Creational/Factory/InnerFactory/InnerFactory.h"
#include "Creational/Factory/AbstractFactory/AbstractFactoryMgr.h"
#include "Creational/Factory/Excercises/Person.h"


void testReverseSqrt() {
    std::cout << (Utils::Q_rsqrt(1)) << std::endl;
}
void solidPatterns() {
    //    Solid::testJournal();
//    Solid::colorFilterExample();
//    Solid::rightWayFilterExample();
//    Solid::genericWayFilterExample();
//    Solid::genericWayExample();
//    Solid::testProcess();
    
//Dependancy Inversion Examples
//    Solid::testRelations();
    
}

void builderPattern() {
//    Builder::simpleExample();
//    Builder::builderExample();
//    FluentBuilder::builderExample();
//    GroovyBuilder::htmlExample();
//    BuilderFacet::personBuilderTest();
    
//    BuilderEx::testExcercise();
}

void factoryPattern() {
//    FactoryMethod::testFactoryMethod();
//    Factory::testFactoryMethod();
//    InnerFactory::testFactoryMethod();
//    AbstractFactory::runExample();
//    FactoryEx::runFactoryEx();
}

void creationalPatterns() {
//    builderPattern();
//    factoryPattern();
}

int main(int argc, char** argv) {

    creationalPatterns();
    
    return 0;
}

