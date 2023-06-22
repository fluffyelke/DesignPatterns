/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FactoryMgr.h
 * Author: default
 *
 * Created on June 22, 2023, 8:59 AM
 */

#ifndef FACTORYMGR_H
#define FACTORYMGR_H

#include <map>
#include <string>
#include <memory>

#include "IBaseFactory.h"

namespace AbstractFactory {
    class FactoryMgr {
        std::map<std::string, std::unique_ptr<IBaseFactory>> factories;
    public:
        FactoryMgr();
        ~FactoryMgr();
        std::unique_ptr<IBase> makeObj(const std::string& type);
    private:

    };
}

#endif /* FACTORYMGR_H */

