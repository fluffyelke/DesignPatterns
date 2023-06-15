/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <iostream>
#include <sstream>
#include "LifeWithoutBuilder.h"


namespace Builder {
    void simpleExample() {
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
        std::cout << oss.str();
    }
}