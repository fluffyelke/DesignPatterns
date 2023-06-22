/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SingletonInDI.h
 * Author: default
 *
 * Created on June 22, 2023, 2:04 PM
 */

#ifndef SINGLETONINDI_H
#define SINGLETONINDI_H

#include <string>
#include <map>
#include <vector>

namespace SingletonInDI {
    
    class IDataBase {
    public:
        virtual int getPopulation(const std::string& name) = 0;
    };
    
    class SingletonDataBase : public IDataBase {
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
        
        //Instead of this method here, we should create interface with that method for to be able to use dependency injection
        int getPopulation(const std::string& city) override;
    };
    
    
    class DummyDataBase : public IDataBase {
        std::map<std::string, int> capitals;
    public:
        DummyDataBase();

        int getPopulation(const std::string& name) override;
    };
    class ConfigurableRecordFinder {
    public:
        IDataBase& db;
        ConfigurableRecordFinder(IDataBase& ldb);
        int totalPopulation(const std::vector<std::string>& names);
    };
    
    
    
    
    class SingletonRecordFinder {
    public:
        int totalPopulation(const std::vector<std::string>& names);
    };
    
    
    
    extern void testSingleton();
    extern bool testOne();
    extern bool testTwo();
}

#endif /* SINGLETONINDI_H */

