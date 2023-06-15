/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonJobBuilder.h
 * Author: default
 *
 * Created on June 15, 2023, 1:02 PM
 */

#ifndef PERSONJOBBUILDER_H
#define PERSONJOBBUILDER_H

#include "PersonBuilder.h"

namespace BuilderFacet {
    
    class PersonJobBuilder : public PersonBuilderBase {
        using Self = PersonJobBuilder;
    public:
        PersonJobBuilder(Person& person);
        
        Self& worksAt(const std::string& compName);
        Self& atPosition(const std::string& position);
        Self& earnings(int income);
    };
    
}

#endif /* PERSONJOBBUILDER_H */

