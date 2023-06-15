/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Person.cpp
 * Author: default
 * 
 * Created on June 15, 2023, 12:44 PM
 */

#include "Person.h"
#include "PersonBuilder.h"

namespace BuilderFacet {
    
    PersonBuilder Person::create() {
        return PersonBuilder();
    }
    
}