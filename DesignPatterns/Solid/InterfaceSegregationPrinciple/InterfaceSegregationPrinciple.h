/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InterfaceSegregationPrinciple.h
 * Author: default
 *
 * Created on June 14, 2023, 11:54 AM
 */

#ifndef INTERFACESEGREGATIONPRINCIPLE_H
#define INTERFACESEGREGATIONPRINCIPLE_H

namespace Solid {
    struct Document;

    //Wrong approach, instead this interface, we have to have different interfaces,
    //to segregate the interface.
//    struct IMachine {
//        virtual void print(Document& doc) = 0;
//        virtual void scan(Document& doc) = 0;
//        virtual void fax(Document& doc) = 0;
//    };
//    
//    struct MultiFunctionPrinter : IMachine {
//        void fax(Document& doc) override;       //Ok
//        void print(Document& doc) override;     //Ok
//        void scan(Document& doc) override;      //Ok
//    };
//    
//    //but what about if we want a Scanner
//    struct Scanner : IMachine {
//        void fax(Document& doc) override;       //NOT ok
//        void print(Document& doc) override;     //NOT ok
//        void scan(Document& doc) override;      //Ok
//    };
    
    //Interface Segregation Principle.
    struct IPrinter {
        virtual void print(Document& doc) = 0;
    };
    struct IScanner {
        virtual void scan(Document& doc) = 0;
    };
    struct IFax {
        virtual void fax(Document& doc) = 0;
    };
    
    //Now if we want to implement only printer
    //we can create just printer
    struct Printer : IPrinter {
        void print(Document& doc) override;
    };
    struct Scanner : IScanner {
        void scan(Document& doc) override;
    };
    //Or if we want more complex machine we can create new interface
    struct IMachine : IPrinter, IScanner {
        //This interface does not need a body aswel
    };
    //Now we can create concrete machine from the new interface.
    struct Machine : IMachine {
        //this is from decorator pattern
        IPrinter& printer;
        IScanner& scanner;
        Machine(IPrinter& printer, IScanner& scanner)
            : printer(printer), scanner(scanner) {
        }
        
        void print(Document& doc) override;
        void scan(Document& doc) override;
    };
}

#endif /* INTERFACESEGREGATIONPRINCIPLE_H */

