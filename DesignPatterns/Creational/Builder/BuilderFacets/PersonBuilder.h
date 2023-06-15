/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonBuilder.h
 * Author: default
 *
 * Created on June 15, 2023, 12:50 PM
 */

#ifndef PERSONBUILDER_H
#define PERSONBUILDER_H

#include "Person.h"


namespace BuilderFacet {

    class PersonAddressBuilder;
    class PersonJobBuilder;
    
    class PersonBuilderBase {
    protected:
        Person& person;
    public:
        PersonBuilderBase(Person& person);

        PersonAddressBuilder lives() const;
        PersonJobBuilder works() const;
        
        operator Person() const;
    };
    
    //Person builder class is the actual Facade.
    class PersonBuilder : public PersonBuilderBase {
        Person p;
    public:
        PersonBuilder();
    };

}
#endif /* PERSONBUILDER_H */

