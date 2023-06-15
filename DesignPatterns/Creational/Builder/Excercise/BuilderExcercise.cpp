/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * 
 * class Person
    {
      string name;
      int age;
    };
 */

#include "BuilderExcercise.h"
#include <sstream>
#include <string>
#include <algorithm>
namespace BuilderEx {

    Component::Component(const std::string& name) 
        : name{name} {
        this->name[0] =  std::toupper(this->name.at(0));
    }

    std::ostream& operator << (std::ostream& os, const Component& obj) {
        os << "class " << obj.name << std::endl
            << "{" << std::endl;
        
        for(const auto& elem : obj.members) {
            os << "  " << elem.second << " " << elem.first << ";" << std::endl;
        }
        os << "};";
        return os;
    }

    void Component::addMembers(const std::string& name, const std::string& type) {
        members.emplace_back(std::make_pair(name, type));
        
    }

    //End of Component class
    
    //Builder Class ComponentBuilder

    ComponentBuilder::ComponentBuilder(const std::string& name) 
        : className {name} {

    }
    ComponentBuilder& ComponentBuilder::addField(const std::string& name, const std::string& type) {
        className.addMembers(name, type);
        return *this;
    }
    std::ostream& operator << (std::ostream& os, const ComponentBuilder& obj) {
        os << obj.className;
        return os;
    }
    void testExcercise() {
        auto compBuilder = ComponentBuilder("Person").addField("name", "string").addField("age", "int");
        std::cout << compBuilder;
    }
}