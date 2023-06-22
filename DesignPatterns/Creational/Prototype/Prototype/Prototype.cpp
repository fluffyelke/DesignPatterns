/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Prototype.h"
#include <iostream>

namespace Prototype {
    
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
        Contact john{"John Doe", new Address{"123 East Drive", "London", 123}};
        Contact jane{"Jane Smith", new Address{"123 East Drive", "London", 103}};
        //Instead of creating more and more objects with same address, we can just do that
//        Contact jane2 = john;   //this is shallow copy, and we want deep copy.
        //so now we can have
        Contact jane2{john};
        jane2.name = "Vanya Smith";
        //now we changed and john object cause we are taking the address of john,
        //we can create copy constructor to avoid this shallow copy.
        jane2.address->suite = 150; 
        
        
        std::cout << john << std::endl;
        std::cout << jane << std::endl;
        std::cout << jane2 << std::endl;
    }

}