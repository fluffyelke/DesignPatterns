/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "InterfaceSegregationPrinciple.h"


namespace Solid {
    void Machine::print(Document& doc) {
        printer.print(doc);
    }

    void Machine::scan(Document& doc) {
        scanner.scan(doc);
    }

}