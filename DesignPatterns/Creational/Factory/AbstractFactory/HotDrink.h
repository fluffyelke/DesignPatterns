/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HotDrink.h
 * Author: default
 *
 * Created on June 19, 2023, 10:32 AM
 */

#ifndef HOTDRINK_H
#define HOTDRINK_H

#include <memory>

namespace AbstractFactory {

    //Concrete classes which we want to use in the abstract factory.
    struct HotDrink{
        virtual ~HotDrink() = default;
        virtual void prepare(int volume) = 0;
    };

    struct Tea : public HotDrink {
        void prepare(int volume) override;
    };
    struct Coffee : public HotDrink {
        void prepare(int volume) override;
    };
    
}

#endif /* HOTDRINK_H */

