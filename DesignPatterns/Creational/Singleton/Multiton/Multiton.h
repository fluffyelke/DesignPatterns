/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Multiton.h
 * Author: default
 *
 * Created on June 22, 2023, 3:43 PM
 */

#ifndef MULTITON_H
#define MULTITON_H

#include <string>
#include <memory>
#include <map>
#include <iostream>

namespace Multiton {
    enum class Importance {
        primary,
        secondary,
        tertiary,
    };
    //Class which is mean to not be instantiated, insted we use static get() method. 
    template<typename T, typename Key = std::string>
    class Multiton {
        public:
            static std::shared_ptr<T> get(const Key& key) {
                const auto it = instances.find(key);
                if(it != instances.end()) {
                    return it->second;
                }
                
                auto instance = std::make_shared<T>();
                instances[key] = instance;
                return instance;
            }
        protected:
            Multiton() = default;
            virtual ~Multiton() = default;
        private:
            static std::map<Key, std::shared_ptr<T>> instances;
    };
    
    template<typename T, typename Key>
    std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;
    
    
    class Printer {
    public:
        Printer() {
            ++Printer::totalInstanceCount;
            std::cout << "A total of a " << Printer::totalInstanceCount << " instances created so far" << std::endl;
        }
    private:
        static int totalInstanceCount;
    };

    extern void testMultiton();
}

#endif /* MULTITON_H */

