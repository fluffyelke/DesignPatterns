/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BuilderExcercise.h
 * Author: default
 *
 * Created on June 15, 2023, 1:35 PM
 * 
 * 
 * 
 * Builder Coding Exercise

You are asked to implement the Builder design pattern for rendering simple chunks of code.

Sample use of the builder you are asked to create:

    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    cout << cb;

The expected output of the above code is:

    class Person
    {
      string name;
      int age;
    };

Please observe the same placement of curly braces and use two-space indentation.
 */

#ifndef BUILDEREXCERCISE_H
#define BUILDEREXCERCISE_H

#include <string>
#include <vector>
#include <iostream>


namespace BuilderEx {
    class Component {
        std::string name;
        std::vector<std::pair<std::string, std::string>> members;
    public:     
        Component(const std::string& name);
        
        void addMembers(const std::string& name, const std::string& type);
        
        friend std::ostream& operator<<(std::ostream& os, const Component& obj);
        
    };
    
    class ComponentBuilder {
        Component className;
    public:
        ComponentBuilder(const std::string& name);

        ComponentBuilder& addField(const std::string& name, const std::string& type);
        
        friend std::ostream& operator<<(std::ostream& os, const ComponentBuilder& obj);

    };
    
    extern void testExcercise();
}

#endif /* BUILDEREXCERCISE_H */

