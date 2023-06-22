/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prototype.h
 * Author: default
 *
 * Created on June 19, 2023, 4:13 PM
 */

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <string>

namespace Prototype {
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
    
    extern void contactExample();
}

#endif /* PROTOTYPE_H */

