/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Singleton.h"


namespace Singleton {
    SingletonDataBase::SingletonDataBase() {
//        std::cout << "Initializing DataBase" << std::endl;
        const std::string pathToFile{"Creational/Singleton/Singleton/capitals.txt"};
        std::ifstream dbFile{pathToFile};
        if(!dbFile.is_open()) {
            std::cerr << "File: " << pathToFile << " cannot be opened " << std::endl;
            exit(1);
        }
        
        std::string city, population;
        while(std::getline(dbFile, city)) {
            std::getline(dbFile, population);
            std::stringstream ss{population};
            int pop = 0;
            ss >> pop;
            capitals[city] = pop;
//            std::cout << city << ", pop: " << pop << std::endl;
        }
    }

    SingletonDataBase& SingletonDataBase::getInstance() {
        static SingletonDataBase db;    //this is created only once, cause is static global variable.
        return db;
    }

    int SingletonDataBase::getPopulation(const std::string& city) {
        return capitals[city];
    }

    void testSingleton() {
        std::string city = "Mumbai";
        std::cout << city << " has population " << SingletonDataBase::getInstance().getPopulation(city) << std::endl;
    }
}