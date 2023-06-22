/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IBase.h
 * Author: default
 *
 * Created on June 22, 2023, 8:39 AM
 */

#ifndef IBASE_H
#define IBASE_H

#include <iostream>


namespace AbstractFactory {
    class IBase {
    public:
        IBase() {
            std::cout << "IBase() Constructor" << std::endl;
        }
        virtual ~IBase() {
            std::cout << "~IBase() Destructor" << std::endl;
        }
        virtual void create() = 0;
    };
}

#endif /* IBASE_H */

