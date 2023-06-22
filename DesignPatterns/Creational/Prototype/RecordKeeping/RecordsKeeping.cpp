/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "RecordsKeeping.h"
#include <iostream>

namespace PrototypeProblem {
    
    Address::Address(const std::string& street, const std::string& city, int suite) 
        : street{street}, 
          city{city}, 
          suite{suite}{
    }

    std::ostream& operator<<(std::ostream& os, const Address& obj) {
        
        os << "\tStreet: " << obj.street << std::endl 
            << "\tCity: " << obj.city << std::endl
            << "\tSuite: " << obj.suite;
        
        return os;
    }

          
    Contact::Contact(const std::string& name, const Address& address)
        : name{name}, 
          address{address} {
    }
//    Contact::Contact(const std::string& name, Address* ptrAddress) 
//        : name{name},
//          ptrAddress{ptrAddress}{
//        
//    }      
    std::ostream& operator <<(std::ostream& os, const Contact& obj) {
        
        os << "Name: " << obj.name << "\n" << obj.address;
        
        return os;
    }
    
    void contactExample() {
        Contact john{"John Doe", Address{"123 East Drive", "London", 123}};
        Contact jane{"Jane Smith", Address{"123 East Drive", "London", 103}};
        //Instead of creating more and more objects with same address, we can just do that
        Contact jane2 = john;
        jane2.name = "Vanya Smith";
        jane2.address.suite = 150;
        
        std::cout << john << std::endl;
        std::cout << jane << std::endl;
        std::cout << jane2 << std::endl;
        
//        std::cout << "After using address pointer" << std::endl;
//        Contact newJohn{"New John Doe", new Address{"123, East Drive", "London", 123}}; //memory leak of course.
//        Contact newJane = newJohn;
//        newJane.name = "New Jane Doe";
//        newJane.ptrAddress->suite = 155;
//        std::cout << &newJohn << std::endl << &newJane << std::endl;
//        std::cout << newJohn << std::endl << newJane << std::endl << newJohn <<std::endl;
    }

}