/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrototypeFactory.h
 * Author: default
 *
 * Created on June 19, 2023, 4:35 PM
 */

#ifndef PROTOTYPEFACTORY_H
#define PROTOTYPEFACTORY_H

#include <string>
#include <memory>

namespace PrototypeFactory {
        struct Address {
        std::string street;
        std::string city;
        int suite;
        
        Address(const std::string& street, const std::string& city, int suite);

        //!! we can continue after previous stuff to add copy constructor here aswell
        Address(const Address& obj);
        
        friend std::ostream& operator<<(std::ostream& os, const Address& obj);

    };
    struct Contact {
        std::string name;
        Address* address;
        Contact(const std::string& name, Address* address);
        
        //copy constructor for perform deep copy.
        Contact(const Contact& obj);
        ~Contact();
        friend std::ostream& operator<<(std::ostream& os, const Contact& obj);

    };
    
    
    //PrototypeFactory
    //After factory is created we can make a lots of Address and Contact constructors private.
    struct EmployeeFactory {
//        static Contact mainOffice;
//        static Contact auxiliaryOffice;
        //actual function to use prototype
        static std::unique_ptr<Contact> newMainOfficeEmployee(const std::string& name, const int& suite);
    private:
        static std::unique_ptr<Contact> newEmployee(const std::string& name, const int& suite, const Contact& prototype);
    };
    
    extern void contactExample();
}

#endif /* PROTOTYPEFACTORY_H */

