/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConcreteBFactory.h
 * Author: default
 *
 * Created on June 22, 2023, 8:55 AM
 */

#ifndef CONCRETEBFACTORY_H
#define CONCRETEBFACTORY_H

#include "IBaseFactory.h"


namespace AbstractFactory {

    class ConcreteBFactory : public IBaseFactory {
    public:
        ConcreteBFactory();
        ~ConcreteBFactory();
        std::unique_ptr<IBase> make() const override;
    private:

    };

}

#endif /* CONCRETEBFACTORY_H */

