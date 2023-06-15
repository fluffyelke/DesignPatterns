/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PreviousSolution.h
 * Author: default
 *
 * Created on June 15, 2023, 2:16 PM
 */

#ifndef PREVIOUSSOLUTION_H
#define PREVIOUSSOLUTION_H

#include <string>
#include <ostream>
#include <vector>
using namespace std;

namespace BuilderEx {

    class CodeBuilder;

    class Code {
    public:
        std::string className;
        std::string name, type;
        std::vector<Code> elements;

        const std::size_t indentSize = 2;
        Code() {}
        Code(const std::string& className) 
            : className{className} {

        }


        //Function to print
        friend std::ostream& operator<<(std::ostream& os, const Code& obj) {
            os << "class " <<obj.className << std::endl;
            os << "{" << std::endl;
            std::string i(obj.indentSize, ' ');
            for(const auto& elem : obj.elements) {
                os << i << elem.type << " " << elem.name << ";" << std::endl;
            }
            os << "};" << std::endl;
            return os;
        }

    };

    class CodeBuilder
    {
    Code code;
    public:
      CodeBuilder(const string& class_name)
      {
          // todo
          code.className = class_name;
      }

      CodeBuilder& add_field(const string& name, const string& type)
      {
        // todo
        code.name = name;
        code.type = type;
        code.elements.emplace_back(code);
        return *this;
      }

      friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
      {
        // todo
        os << obj.code;
        return os;
      }
    };

}
#endif /* PREVIOUSSOLUTION_H */

