/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConcreteA.h
 * Author: default
 *
 * Created on June 22, 2023, 8:41 AM
 */

#ifndef CONCRETEA_H
#define CONCRETEA_H

#include "IBase.h"


namespace AbstractFactory {
    class ConcreteA : public IBase{
    public:
        ConcreteA();
        ~ConcreteA();
        void create() override;
    };
}

#endif /* CONCRETEA_H */

