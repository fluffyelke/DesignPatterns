/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PrototypeFactory.h"
#include <iostream>

namespace PrototypeFactory {
    
    Address::Address(const std::string& street, const std::string& city, int suite) 
        : street{street}, 
          city{city}, 
          suite{suite}{
    }

    Address::Address(const Address& obj) 
        : street{obj.street},
          city{obj.city},
          suite{obj.suite}{
        
    }
      

    std::ostream& operator<<(std::ostream& os, const Address& obj) {
        
        os << "\tStreet: " << obj.street << std::endl 
            << "\tCity: " << obj.city << std::endl
            << "\tSuite: " << obj.suite;
        
        return os;
    }

          
    Contact::Contact(const std::string& name, Address* address)
        : name{name}, 
          address{address} {
    }

    Contact::Contact(const Contact& obj) 
        : name{obj.name},
            //this is if Address copy constructor is not provided.
//          address{new Address{obj.address->street, obj.address->city, obj.address->suite}}
            //otherwise if copy constructor of Address is provided:
          address{ new Address{ *obj.address } }
        {
    }
    Contact::~Contact() {
        delete address;
    }      
    std::ostream& operator <<(std::ostream& os, const Contact& obj) {
        
        os << "Name: " << obj.name << "\n" << obj.address << *obj.address;
        
        return os;
    }
    
    void contactExample() {
        //now we can use our factory
        auto john = EmployeeFactory::newMainOfficeEmployee("John", 123);
        auto vanya = EmployeeFactory::newMainOfficeEmployee("Vanya", 150);
        std::cout << *john << std::endl << *vanya << std::endl;
    }
    
    
    //PrototypeFactory

    std::unique_ptr<Contact> EmployeeFactory::newMainOfficeEmployee(const std::string& name, const int& suite) {
        static Contact defaultEmployee{ "", new Address { "123 East Dr", "London", 0 } };
        return newEmployee(name, suite, defaultEmployee);
    }

    std::unique_ptr<Contact> EmployeeFactory::newEmployee(const std::string& name, const int& suite, const Contact& prototype) {
        //std::unique_ptr<Contact>
        auto result = std::make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }

}