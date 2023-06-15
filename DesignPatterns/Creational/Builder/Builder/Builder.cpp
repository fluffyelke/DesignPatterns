/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Builder.h"
#include <sstream>
#include <iostream>

namespace Builder {
    HtmlElement::HtmlElement() {
        
    }

    HtmlElement::HtmlElement(const std::string& name, const std::string& text) 
        : name { name },
          text { text } {
        
    }
    std::string HtmlElement::toString(int indent) const {
        std::ostringstream oss;
        std::string i(indentSize * indent, ' ');
        oss << i << "<" << name << ">" << std::endl;
        if (text.size() > 0) {
            oss << std::string(indentSize * (indent + 1), ' ') << text << std::endl;
        }
        for(const auto& e : elements) {
            oss << e.toString(indent + 1);
        }
        oss << i << "</" << name << ">" << std::endl;
        return oss.str();
    }

//the Actual Builder

    HtmlBuilder::HtmlBuilder(const std::string& name) {
        root.name = name;
    }

    void HtmlBuilder::addChild(const std::string& childName, const std::string& childText) {
        HtmlElement childElement{childName, childText};
        root.elements.emplace_back(childElement);
    }

    std::string HtmlBuilder::toString() const {
        return root.toString();
    }

    void builderExample() {
        //Without Builder
        auto text = "hello";
        
        std::string output{};
        output += "<p>";
        output += text;
        output += "</p>";
        std::cout << output << std::endl;
        
        std::string words[] = {"hello", "world"};
        std::ostringstream oss;
        oss << "<ul>";
        for(auto w : words) {
            oss << std::endl << "\t<li>" << w << "</li>";
        }
        oss << "\n<ul>";
        std::cout << oss.str() << std::endl << std::endl;
        
        //Builder 
        HtmlBuilder builder{"ul"};
        builder.addChild("li", "hello");
        builder.addChild("li", "world");
        std::cout << builder.toString() << std::endl;
        
    }
    
}