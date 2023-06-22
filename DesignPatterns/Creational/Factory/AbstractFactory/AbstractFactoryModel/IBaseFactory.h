/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IBaseFactory.h
 * Author: default
 *
 * Created on June 22, 2023, 8:49 AM
 */

#ifndef IBASEFACTORY_H
#define IBASEFACTORY_H

#include <memory>

#include "IBase.h"


namespace AbstractFactory {
    class IBaseFactory {
    public:
        IBaseFactory();
        virtual ~IBaseFactory();
        virtual std::unique_ptr<IBase> make() const = 0;
    };
}

#endif /* IBASEFACTORY_H */

