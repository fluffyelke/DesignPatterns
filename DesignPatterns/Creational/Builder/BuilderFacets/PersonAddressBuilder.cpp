/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonAddressBuilder.cpp
 * Author: default
 * 
 * Created on June 15, 2023, 1:01 PM
 */

#include "PersonAddressBuilder.h"
namespace BuilderFacet {
    
    PersonAddressBuilder::PersonAddressBuilder(Person& person) 
        : PersonBuilderBase(person) {
        
    }

    PersonAddressBuilder::Self& PersonAddressBuilder::at(const std::string& streetAddress) {
        person.streetAdress = streetAddress;
        return *this;
    }

    PersonAddressBuilder::Self& PersonAddressBuilder::withPostCode(const std::string& postCode) {
        person.postCode = postCode;
        return *this;
    }
    
    PersonAddressBuilder::Self& PersonAddressBuilder::in(const std::string& city) {
        person.city = city;
        return *this;
    }
}