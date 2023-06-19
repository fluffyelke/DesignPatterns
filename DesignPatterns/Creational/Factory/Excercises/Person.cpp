/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>

#include "Person.h"


namespace FactoryEx {
    Person::Person(const int& id, const std::string& name) 
        : id{id},
          name{name}{
            std::cout << "Person with id: " << id << " and name: " << name << " created" << std::endl;
    }
    Person::~Person() {
        std::cout << "Person with id: " << id << " and name: " << name << " destroyed" << std::endl;
    }      

    int PersonFactory::id = 0;
    
    Person PersonFactory::createPerson(const std::string& name) {
        return {id++, name};
    }

    void runFactoryEx() {

        Person p1 = PersonFactory::createPerson("Ivan");
        Person p2 = PersonFactory::createPerson("Vanya");
        Person p3 = PersonFactory::createPerson("Elinna");
        Person p4 = PersonFactory::createPerson("Maria");
 
    }
}