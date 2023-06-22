/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "PrototypeEx.h"


namespace DeepCopy {
    Point::Point(const int& lx, const int& ly) 
        : x {lx},
          y {ly} {
            std::cout << "Point() Constructor, Point with coords " << *this << " created" << std::endl;
    }

    Point::Point(const Point& obj) 
        : x{ obj.x },
          y{ obj.y } {
         std::cout << "Point(const Point& obj) copy Constructor Point with coords " << *this << " created" << std::endl;    
    }

    Point::~Point() {
        std::cout << "~Point() Destructor called on point: " << *this <<std::endl;
    }

    std::ostream& operator<<(std::ostream& os, const Point& obj) {
        os << "{ " << obj.x << ", " << obj.y << " }";
        return os;
    }

          
    Line::Line(Point * const lstart, Point * const lend) 
        : start { lstart },
          end { lend } {
            std::cout <<"Line() Constructor Created with points: " << *this << " Created" << std::endl;
    }

    Line::Line(const Line& obj) 
        : start{ new Point{ *obj.start } },
          end{ new Point{ *obj.end } } {
            std::cout << "Line(const Line& obj) copy Constructor called for points: " << *this << std::endl;
    }

    Line::~Line() {
        std::cout << "~Line() Destructor for points: " << *this << " called " << std::endl;
        delete start;
        delete end;
    }
    std::ostream& operator << (std::ostream& os, const Line& obj) {
        os << "[" << *(obj.start) << " and " << *(obj.end) << "]";
        return os;
    }
    
    Line Line::deepCopy() const {
        return *this;
    }
    
    void deepCopyExercise() {
        Line line{new Point(10, 10), new Point(25, 25)};
        Line newLine{line.deepCopy()};
    }
}