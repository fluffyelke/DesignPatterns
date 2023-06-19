/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FactoryMethod.h
 * Author: default
 *
 * Created on June 15, 2023, 3:41 PM
 */

#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

namespace FactoryMethod {
    //FactoryMethod - Remove the construction from constructor to some other method.
    enum class PointType {
        cartesian,
        polar,
    };
    
    class Point {

        Point(const float& x, const float& y);

    public:
        float x, y;
        
        //static is optional can be done and without static.
        //Factory Method for creation a point in cartesian coords
        static Point newCartesian(const float& x, const float& y);
        //Factory Method for creation a point in polar coord system.
        static Point newPolar(const float& r, const float& theta);
        
        friend std::ostream& operator << (std::ostream& os, const Point& obj);

    };
    
    extern void testFactoryMethod();
}

#endif /* FACTORYMETHOD_H */

