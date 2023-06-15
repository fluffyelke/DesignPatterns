/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "FluentBuilder.h"
#include <sstream>
#include <iostream>

namespace FluentBuilder {
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

    HtmlBuilder HtmlElement::create(const std::string& rootName) {
        return {rootName};
    }

    std::unique_ptr<HtmlBuilder> HtmlElement::createPtr(const std::string& name) {
        return std::make_unique<HtmlBuilder>(name);
    }


//the Actual Builder

    HtmlBuilder::HtmlBuilder(const std::string& name) {
        root.name = name;
    }

    HtmlBuilder& HtmlBuilder::addChild(const std::string& childName, const std::string& childText) {
        HtmlElement childElement{childName, childText};
        root.elements.emplace_back(childElement);
        return *this;
    }

    HtmlBuilder* HtmlBuilder::addChildPtr(const std::string& childName, const std::string& childText) {
        HtmlElement childElement{childName, childText};
        root.elements.emplace_back(childElement);
        return this;
    }

    HtmlBuilder::operator HtmlElement() const {
        return root;
    }

    HtmlElement HtmlBuilder::build() {
        return root;
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
        builder.addChild("li", "hello").addChild("li", "world").addChild("li", "vanya");
        std::cout << builder.toString() << std::endl;
        
        HtmlElement newElem = HtmlElement::create("ul").addChild("li", "vanya").addChild("li", "beauty");
        std::cout << newElem.toString() << std::endl;
        
        
        //And now the correct way for user to use builder is
        std::cout << HtmlElement::create("ul").addChild("li", "first").addChild("li", "second").addChild("li", "third").build().toString() << std::endl;
    }
    
}