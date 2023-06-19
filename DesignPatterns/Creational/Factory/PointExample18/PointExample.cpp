/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <complex>

#include "PointExample.h"


namespace PointExample {
    
    Point::Point(const float& a, const float& b, PointType type) {
        if(type == PointType::cartesian) {
            x = a;
            y = b;
        }
        else {
            x = a * cos(a);
            y = b * sin(b);
        }
    }
}