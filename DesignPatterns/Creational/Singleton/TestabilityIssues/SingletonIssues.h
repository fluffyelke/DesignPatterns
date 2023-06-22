/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SingletonIssues.h
 * Author: default
 *
 * Created on June 22, 2023, 1:50 PM
 */

#ifndef SINGLETONISSUES_H
#define SINGLETONISSUES_H

#include <string>
#include <map>
#include <vector>

namespace SingletonIssues {
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
    
    class SingletonRecordFinder {
    public:
        int totalPopulation(const std::vector<std::string>& names);
    };
    
    extern void testSingleton();
    extern bool testOne();
}

#endif /* SINGLETONISSUES_H */

