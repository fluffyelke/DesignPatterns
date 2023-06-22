/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Singleton.h
 * Author: default
 *
 * Created on June 22, 2023, 1:12 PM
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>
#include <map>

namespace Singleton {
    class SingletonDataBase {
        SingletonDataBase();
        std::map<std::string, int> capitals;
    public:
        //Delete copy/move operations for singletons.
        SingletonDataBase(const SingletonDataBase& obj) = delete;   
        void operator = (const SingletonDataBase& obj) = delete;
        SingletonDataBase(const SingletonDataBase&& obj) = delete;
        void operator = (const SingletonDataBase&& obj) = delete;
        
        //actually get the singleton.
        static SingletonDataBase& getInstance();
        
        int getPopulation(const std::string& city);
    };
    
    extern void testSingleton();
}

#endif /* SINGLETON_H */

