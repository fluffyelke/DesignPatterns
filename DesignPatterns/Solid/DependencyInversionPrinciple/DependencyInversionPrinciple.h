/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DependencyInversionPrinciple.h
 * Author: default
 *
 * Created on June 14, 2023, 12:17 PM
 */

#ifndef DEPENDENCYINVERSIONPRINCIPLE_H
#define DEPENDENCYINVERSIONPRINCIPLE_H

#include <string>
#include <vector>
#include <tuple>


namespace Solid {
    enum class Relationship {
        parent,
        child,
        sibling,
    };
    
    struct Person {
        std::string name;
        friend std::ostream& operator << (std::ostream& os, const Person& obj) {
            // Write obj to stream
            os << obj.name;
            return os;
        }
    };
    
    //Part 3 after the addPersonTest()
    struct RelationshipBrowser {
        virtual std::vector<Person> findAllChildrensOf(const std::string& name) = 0;
    };
    
    
    //low-level module, is what we typically call that
    //Because this class is only storage with utility functions
    using myCollection = std::vector<std::tuple<Person, Relationship, Person>>;
    struct Relationships : RelationshipBrowser{      
        //Problem here is that high-level module depend on this variable which is public now,
        //but if the user change it to private everything in the high-level module
        //will be broken.
        //The solution is 2 way, abstraction called RelationshipBrowser, 
        // or to move the high level module into the low-level module.
        myCollection relations;
        
        void addParentAndChild(const Person& parent, const Person& child);
        
        std::vector<Person> findAllChildrensOf(const std::string& name) override;

    };
    
    //High-level module.
    struct Research {
        //Wrong way now we break the A: point, high-level module should not depend on low-level modules
//        Research(Relationships& relat);   
        //Now after RelationsBrowser we can use the other, right way.
        
        Research(RelationshipBrowser& browser);
    };
    
    
    extern void testRelations();
}

#endif /* DEPENDENCYINVERSIONPRINCIPLE_H */

