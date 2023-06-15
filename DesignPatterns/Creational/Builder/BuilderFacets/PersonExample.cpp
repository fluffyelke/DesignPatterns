/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "PersonExample.h"
#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

namespace BuilderFacet {
    void personBuilderTest() {
        Person vanya = Person::create()
            .lives().at("Todor Kableshkov 155")
                    .withPostCode("1000")
                    .in("Sofia")
            .works().worksAt("PipeSystems")
                    .atPosition("Architect")
                    .earnings(10e6);
        std::cout << vanya << std::endl;
    }
}