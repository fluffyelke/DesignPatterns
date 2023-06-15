/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Builder.h
 * Author: default
 *
 * Created on June 15, 2023, 10:47 AM
 */

#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include <vector>


namespace Builder {
    
    //Class for modeling html in c++
    struct HtmlElement {
        std::string name, text;
        std::vector<HtmlElement> elements;
        const std::size_t indentSize = 2;
        
        HtmlElement();
        HtmlElement(const std::string& name, const std::string& text);
        
        std::string toString(int indent = 0) const; 
    };

    //The actual Builder
    struct HtmlBuilder {
        HtmlElement root;
        HtmlBuilder(const std::string& name);
        
        void addChild(const std::string& childName, const std::string& childText);
        std::string toString() const;
    };
    
    extern void builderExample();
    
}



#endif /* BUILDER_H */

