/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointExample.h
 * Author: default
 *
 * Created on June 15, 2023, 3:32 PM
 */

#ifndef POINTEXAMPLE_H
#define POINTEXAMPLE_H

namespace PointExample {
    
    enum class PointType {
        cartesian,
        polar,
    };
    
    struct Point {
        float x, y;
        //cartesian coords
//        Point(const float& x, const float& y);
        
        //imposible to create another constructor for example to take coords
        // from polar coordinate
//        Point(const float& rho, const float& theta); //same numbers of params
        //so create enum instead
        Point(const float& a, const float& b, PointType type = PointType::cartesian);
    };
}

#endif /* POINTEXAMPLE_H */

