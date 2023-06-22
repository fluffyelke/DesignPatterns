/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConcreteB.h
 * Author: default
 *
 * Created on June 22, 2023, 8:42 AM
 */

#ifndef CONCRETEB_H
#define CONCRETEB_H

#include "IBase.h"

namespace AbstractFactory {
    class ConcreteB : public IBase {
    public:
        ConcreteB();
        ~ConcreteB();
        void create() override;
    };
}

#endif /* CONCRETEB_H */

