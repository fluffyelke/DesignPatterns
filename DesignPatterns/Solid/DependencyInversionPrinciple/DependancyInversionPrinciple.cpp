/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DependencyInversionPrinciple.h"
#include <tuple>
#include <iostream>

namespace Solid {
    
    void Relationships::addParentAndChild(const Person& parent, const Person& child) {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    std::vector<Person> Relationships::findAllChildrensOf(const std::string& name) {
        std::vector<Person> result;
        for(myCollection::iterator it = relations.begin(); it != relations.end(); ++it) {
            std::cout << std::get<0>(*it)  << ", " << std::get<2>(*it) << std::endl;
            if(std::get<0>(*it).name == "John" && std::get<1>(*it) == Relationship::parent) {
                result.push_back(std::get<2>(*it));
            }
        }
        return result;
    }

    
    void testRelations() {
        Person parent{"John"};
        Person child1{"Chris"}, child2{"Matt"};
        
        Relationships relats;
        relats.addParentAndChild(parent, child1);
        relats.addParentAndChild(parent, child2);
        
        
        //wrond way
        Research _(relats);
    }
    
    
//    Research::Research(Relationships& relat) {
//        //Wrong way now we break the A: point, high-level module should not depend on low-level modules
//        //because now abstract depends of details.
//        auto& relations = relat.relations;
//        for(myCollection::iterator it = relations.begin(); it != relations.end(); ++it) {
//            std::cout << std::get<0>(*it)  << ", " << std::get<2>(*it) << std::endl;
//            if(std::get<0>(*it).name == "John" && std::get<1>(*it) == Relationship::parent) {
//                std::cout << "John has a child called " << std::get<2>(*it).name << std::endl;
//            }
//        }
//    }
    
    Research::Research(RelationshipBrowser& browser) {
        for(auto& child : browser.findAllChildrensOf("John")) {
            std::cout << "John has a child called: " << child.name << std::endl;
        }
    }
}