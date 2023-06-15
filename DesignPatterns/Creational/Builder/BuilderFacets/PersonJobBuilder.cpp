/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonJobBuilder.cpp
 * Author: default
 * 
 * Created on June 15, 2023, 1:02 PM
 */

#include "PersonJobBuilder.h"
namespace BuilderFacet {
    
    PersonJobBuilder::PersonJobBuilder(Person& person)
        : PersonBuilderBase(person) {
    }

    PersonJobBuilder::Self& PersonJobBuilder::worksAt(const std::string& compName) {
        person.companyName = compName;
        return *this;
    }

    PersonJobBuilder::Self& PersonJobBuilder::atPosition(const std::string& position) {
        person.position = position;
        return *this;
    }

    PersonJobBuilder::Self& PersonJobBuilder::earnings(int income) {
        person.annualIncome = income;
        return *this;
    }


}
