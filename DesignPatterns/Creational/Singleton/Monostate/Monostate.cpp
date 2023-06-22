/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Monostate.h"


namespace Monostate {
    void Printer::setId(const int& value) {
        id = value;
    }

    int Printer::getId() const {
        return id;
    }
    
    int Printer::id = 0;
    
    void testMonostate() {
        Printer p;  //we work with the same id. Its static after all.
        int id = p.getId();
        
        Printer p2;
    }
}