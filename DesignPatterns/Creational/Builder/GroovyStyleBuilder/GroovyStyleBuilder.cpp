/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GroovyStyleBuilder.h"


namespace GroovyBuilder {

    Tag::Tag(const std::string& name, const std::string& text) 
        : name{name},
          text{text} {

    }
    Tag::Tag(const std::string& name, const std::vector<Tag>& children) 
        : name{name}, 
          children{children} {
    }      
    
    std::ostream& operator <<(std::ostream& os, const Tag& obj) {
        os << "<" << obj.name;
        
        for(const auto& att :obj.attributes) {
            os << " " << att.first << "=\"" << att.second << "=\"";
        }
        
        if(obj.children.size() == 0 && obj.text.length() == 0) {
            os << "/>" << std::endl;
        }
        else {
            os << ">" << std::endl;
            
            if(obj.text.length()) {
                os << obj.text << std::endl;
            }

            for(const auto& child : obj.children) {
                os << child;
            }
            
            os << "</" << obj.name << ">" << std::endl;
        }
 
        return os;
    }
    
    //Paragraph Class
    Paragraph::Paragraph(const std::string& text) 
        : Tag{"p", text} {

    }

    Paragraph::Paragraph(std::initializer_list<Tag> children) 
        : Tag{"p", children} {
        
    }

    //Image class

    Image::Image(const std::string& url) 
        : Tag{"img", ""} {
        attributes.emplace_back(std::make_pair("src", url));
    }
    

    void htmlExample() {
        std::cout << 
                    Paragraph {
                        Image {"http://pokemon.com/pickachu.png"}
                    }
                  << std::endl;
    }
}