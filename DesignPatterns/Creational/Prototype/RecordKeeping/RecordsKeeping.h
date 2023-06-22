/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RecordsKeeping.h
 * Author: default
 *
 * Created on June 19, 2023, 12:23 PM
 */

#ifndef RECORDSKEEPING_H
#define RECORDSKEEPING_H

#include <string>


namespace PrototypeProblem {
    struct Address {
        std::string street;
        std::string city;
        int suite;
        
        Address(const std::string& street, const std::string& city, int suite);

        friend std::ostream& operator<<(std::ostream& os, const Address& obj);

    };
    struct Contact {
        std::string name;
        Address address;
//        Address* ptrAddress;
        
//        Contact(const std::string& name, Address* ptrAddress);
        Contact(const std::string& name, const Address& address);
        
        friend std::ostream& operator<<(std::ostream& os, const Contact& obj);

    };
    
    extern void contactExample();
}

#endif /* RECORDSKEEPING_H */

