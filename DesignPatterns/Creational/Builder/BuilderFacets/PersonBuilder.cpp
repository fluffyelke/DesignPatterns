/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonBuilder.cpp
 * Author: default
 * 
 * Created on June 15, 2023, 12:50 PM
 */

#include <deque>

#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

namespace BuilderFacet {     
    
    PersonBuilderBase::PersonBuilderBase(Person& person) 
        : person{person} {

    }

    PersonAddressBuilder PersonBuilderBase::lives() const {
        return PersonAddressBuilder{person};
    }

    PersonJobBuilder PersonBuilderBase::works() const {
        return PersonJobBuilder{person};
    }

    PersonBuilderBase::operator Person() const {
        return std::move(person);
    }

    //end of PersonBuilderBase
        
    PersonBuilder::PersonBuilder() 
        : PersonBuilderBase(p) {
        
    }

}