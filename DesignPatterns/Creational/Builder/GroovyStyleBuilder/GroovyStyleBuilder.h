/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GroovyStyleBuilder.h
 * Author: default
 *
 * Created on June 15, 2023, 11:57 AM
 */

#ifndef GROOVYSTYLEBUILDER_H
#define GROOVYSTYLEBUILDER_H

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

namespace GroovyBuilder {
    struct Tag {
        std::string name, text;
        std::vector<Tag> children;
        std::vector<std::pair<std::string, std::string>> attributes;
        
        friend std::ostream& operator<<(std::ostream& os, const Tag& obj);
        
    protected:
        Tag(const std::string& name, const std::string& text);
        Tag(const std::string& name, const std::vector<Tag>& children);
    }; //end class Tag
    
    struct Paragraph : Tag {
        Paragraph(const std::string& text);
        Paragraph(std::initializer_list<Tag> children);
    };
    struct Image : Tag {
        explicit Image(const std::string& url);
    };
    
    extern void htmlExample();
}

#endif /* GROOVYSTYLEBUILDER_H */

