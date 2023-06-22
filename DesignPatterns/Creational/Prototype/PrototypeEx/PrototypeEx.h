/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrototypeEx.h
 * Author: default
 *
 * Created on June 22, 2023, 12:12 PM
 */

#ifndef PROTOTYPEEX_H
#define PROTOTYPEEX_H

namespace DeepCopy {
    struct Point {
        int x;
        int y;
        Point(const int& lx, const int& ly);
        Point(const Point& obj);
        ~Point();
        friend std::ostream& operator<<(std::ostream& os, const Point& obj);
    };
    
    struct Line {
        Point* start;
        Point* end;
        Line(Point* const lstart, Point* const lend);
        Line(const Line& obj);
        ~Line();
        friend std::ostream& operator<<(std::ostream& os, const Line& obj);
        Line deepCopy() const;
    };
    
    extern void deepCopyExercise();
    
}

#endif /* PROTOTYPEEX_H */

