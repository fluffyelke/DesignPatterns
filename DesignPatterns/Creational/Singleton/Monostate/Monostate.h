/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Monostate.h
 * Author: default
 *
 * Created on June 22, 2023, 3:08 PM
 */

#ifndef MONOSTATE_H
#define MONOSTATE_H

//Monostate is particually bad idea.
namespace Monostate {
    class Printer {
        static int id;
    public:
        int getId() const;
        void setId(const int& value);
    };
    
    extern void testMonostate();
}

#endif /* MONOSTATE_H */

