/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Person.h
 * Author: default
 *
 * Created on June 15, 2023, 12:44 PM
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

namespace BuilderFacet {

    class PersonBuilder;
    
    class Person {
        // address information
        std::string streetAdress, postCode, city;
        // employment information
        std::string companyName, position;
        
        int annualIncome{0};

    public:
        //Point of actually initializing the builders
        static PersonBuilder create();
        
        //Person Builder classes
        friend class PersonBuilder;
        friend class PersonJobBuilder;
        friend class PersonAddressBuilder;
        
        friend std::ostream& operator<<(std::ostream& os, const Person& obj) {
            os << "street address: " << obj.streetAdress << std::endl
                << "post code: " << obj.postCode << std::endl
                << "city: " << obj.city << std::endl
                << "company name: " << obj.companyName << std::endl
                << "position: " << obj.position << std::endl
                << "annual income: " << obj.annualIncome;
            // Write obj to stream
            return os;
        }

    };

}
#endif /* PERSON_H */

