/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Journal.cpp
 * Author: default
 * 
 * Created on May 31, 2023, 12:09 PM
 */

#include <boost/lexical_cast.hpp>
#include <ostream>
#include <fstream>
#include "Journal.h"

namespace Solid {

    Journal::Journal(const std::string& title) 
        : title{title} {

    }

    void Journal::addEntry(const std::string& entry) {
        static int count = 1;
        entries.push_back(boost::lexical_cast<std::string>(count++) + ": " + entry);
    }
    
    ///Wrong to be here, 
    void Journal::save(const std::string& fileName) {
        std::ofstream file{fileName};
        for(auto& elem : entries) {
            file << elem << std::endl;
        }
    }

    
    void testJournal() {
        Journal journal{"Dear Diary"};
        journal.addEntry("I ate a bug");
        journal.addEntry("I Cried Today");
        
        PersistantMgr::save(journal, "Solid/files/journal.txt");
    }
}


