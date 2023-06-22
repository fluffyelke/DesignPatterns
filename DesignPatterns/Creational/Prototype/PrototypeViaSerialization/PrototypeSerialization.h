/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrototypeSerialization.h
 * Author: default
 *
 * Created on June 22, 2023, 10:13 AM
 */

#ifndef PROTOTYPESERIALIZATION_H
#define PROTOTYPESERIALIZATION_H

#include <string>
#include <memory>
//For Serialization
//#include <boost/serialization/serialization.hpp>
//For Input/Output
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>

namespace PrototypeSerialization {
    struct Address {
        std::string street;
        std::string city;
        int suite;
        
        Address();
        Address(const std::string& street, const std::string& city, int suite);

        //!! we can continue after previous stuff to add copy constructor here aswell
        Address(const Address& obj);
        
        friend std::ostream& operator<<(std::ostream& os, const Address& obj);

    private:
//        friend class boost::serialization::access;
        
        template<class archive>
        void serialize(archive& ar, const unsigned version);
    };
    struct Contact {
        std::string name;
        Address* address;   //The problem is this pointer, we have to use copy constructor, for proper transfer.
                            //Instead we can use Serialization/Deserialization,  we can use boost lib
        
        Contact();
        Contact(const std::string& name, Address* address);
        
        //copy constructor for perform deep copy.
        Contact(const Contact& obj);
        ~Contact();
        friend std::ostream& operator<<(std::ostream& os, const Contact& obj);

        //Serialization/Deserialization
    private:
//        friend class boost::serialization::access;
        
        template<class archive>
        void serialize(archive& ar, const unsigned version);
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
    
    extern void serializeDeserializeExample();
}

#endif /* PROTOTYPESERIALIZATION_H */

