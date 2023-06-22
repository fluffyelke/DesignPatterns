/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Multiton.h"


namespace Multiton {
    int Printer::totalInstanceCount = 0;
    
    void testMultiton() {
        using myMultiton = Multiton<Printer, Importance>;
        auto mainPrinter = myMultiton::get(Importance::primary);   //1
        auto auxPrinter = myMultiton::get(Importance::secondary);  //2
        auto aux2Printer = myMultiton::get(Importance::secondary); // already created total 2 instances.
    }
}