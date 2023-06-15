/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonAddressBuilder.h
 * Author: default
 *
 * Created on June 15, 2023, 1:01 PM
 */

#ifndef PERSONADDRESSBUILDER_H
#define PERSONADDRESSBUILDER_H

#include "PersonBuilder.h"
#include <string>

namespace BuilderFacet {
    class PersonAddressBuilder : public PersonBuilderBase {
        using Self = PersonAddressBuilder;
    public:
        PersonAddressBuilder(Person& person);
        
        Self& at(const std::string& streetAddress);
        Self& withPostCode(const std::string& postCode);
        Self& in(const std::string& city);
    };
    
}
#endif /* PERSONADDRESSBUILDER_H */

