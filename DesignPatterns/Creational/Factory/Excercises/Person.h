/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Person.h
 * Author: default
 *
 * Created on June 19, 2023, 11:55 AM
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>


namespace FactoryEx {
    struct Person {
        int id;
        std::string name;
        Person(const int& id, const std::string& name);
        ~Person();
    };
    
    class PersonFactory {
        static int id;
    public:
        static Person createPerson(const std::string& name);
    };
    
    
    extern void runFactoryEx();
}

#endif /* PERSON_H */

