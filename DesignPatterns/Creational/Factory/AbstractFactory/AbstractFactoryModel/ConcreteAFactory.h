/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConcreteAFactory.h
 * Author: default
 *
 * Created on June 22, 2023, 8:51 AM
 */

#ifndef CONCRETEAFACTORY_H
#define CONCRETEAFACTORY_H

#include "IBaseFactory.h"

namespace AbstractFactory {

    class ConcreteAFactory : public IBaseFactory {
    public:
        ConcreteAFactory();
        ~ConcreteAFactory();
        std::unique_ptr<IBase> make() const override;
    private:

    };

}

#endif /* CONCRETEAFACTORY_H */

