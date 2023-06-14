/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Journal.h
 * Author: default
 *
 * Created on May 31, 2023, 12:09 PM
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include <fstream>
#include <string>
#include <vector>

namespace Solid {

    class Journal {
    public:
        std::string title;
        std::vector<std::string> entries;

        Journal(const std::string& title);

        void addEntry(const std::string& entry);
        
        //wrong way is if we make function about saving to file.
        //this should be done in other class manager responsible for that.
        //because when we have another class for example Book, we should create 
        //similar save/load functions and this is not responsibility of the Journal/Book class.
        
        void save(const std::string& fileName);
    private:

    };

    class PersistantMgr {
    public:
        static void save(const Journal& journal, const std::string& fileName) {
            std::ofstream file{fileName};
            for(auto& elem : journal.entries) {
                file << elem << std::endl;
            }
        }
    };
    
    extern void testJournal();

}
#endif /* JOURNAL_H */

