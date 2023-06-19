/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <complex>
#include <iostream>

#include "FactoryMethod.h"


namespace FactoryMethod {

    Point::Point(const float& x, const float& y) 
        : x{x},
          y{y}{

    }

    Point Point::newCartesian(const float& x, const float& y) {
        return {x, y};
    }

    Point Point::newPolar(const float& r, const float& theta) {
        return { r * cos(theta), r * sin(theta) };
    }

    std::ostream& operator << (std::ostream& os, const Point& obj) {
        os << "(x: " << obj.x << ", " << "y:" << obj.y << ")";
        return os;
    }

    void testFactoryMethod() {
        //Now because of the private constructor is impossible to call
        //Point p{1, 2};
        //But we can use factory methods
        
        auto myPoint = Point::newPolar(5, M_PI_4);
        std::cout << myPoint << std::endl;
    }

}