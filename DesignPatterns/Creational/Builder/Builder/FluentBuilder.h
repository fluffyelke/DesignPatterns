/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FluentBuilder.h
 * Author: default
 *
 * Created on June 15, 2023, 11:15 AM
 */

#ifndef FLUENTBUILDER_H
#define FLUENTBUILDER_H
#include <string>
#include <vector>
#include <memory>

namespace FluentBuilder {
    
    //Class for modeling html in c++
    class HtmlBuilder;
    
    class HtmlElement {
        friend class HtmlBuilder;
        std::string name, text;
        std::vector<HtmlElement> elements;
        const std::size_t indentSize = 2;
        
        HtmlElement();
        HtmlElement(const std::string& name, const std::string& text);
    public:
        std::string toString(int indent = 0) const; 
        
        //Often classes which can be used for builder classes provide a static function to the builder itself
        static HtmlBuilder create(const std::string& rootName);
        
        //for using ptrs
        static std::unique_ptr<HtmlBuilder> createPtr(const std::string& name);
    };

    //The actual Builder
    class HtmlBuilder {
    public:
        HtmlElement root;
        HtmlBuilder(const std::string& name);
        
        /**
         * /For to able to use HtmlBuilder instead of that
         *  builder.addChild("li", "hello");
            builder.addChild("li", "world");
         * to do something like that builder.addChild("li", "hello").addChild("li", "world").addChild().addChild()... and so on
         * just change the function from void to return pointer or reference to the Builder class
         * @return HtmlBuilder&
         *
         */
        HtmlBuilder& addChild(const std::string& childName, const std::string& childText);
        
        /**
         * /For to able to use HtmlBuilder instead of that
         *  builder.addChild("li", "hello");
            builder.addChild("li", "world");
         * to do something like that builder.addChild("li", "hello").addChild("li", "world").addChild().addChild()... and so on
         * just change the function from void to return pointer or reference to the Builder class
         * @return HtmlBuilder*
         *
         */
        HtmlBuilder* addChildPtr(const std::string& childName, const std::string& childText);
        
        
        HtmlElement build();
        std::string toString() const;
        operator HtmlElement() const;
    };
    
    extern void builderExample();
    
}

#endif /* FLUENTBUILDER_H */

