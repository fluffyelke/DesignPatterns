/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Factory.h
 * Author: default
 *
 * Created on June 15, 2023, 4:10 PM
 */

#ifndef FACTORY_H
#define FACTORY_H

namespace Factory {
    //Factory - Remove the construction from constructor to some other class instead of a method.
    enum class PointType {
        cartesian,
        polar,
    };
    
    class Point {
    public:     //if everything is public
        friend class PointFactory;  //But this violates open closed principle. or make everything public
        Point(const float& x, const float& y);

    public:
        float x, y;
        
        
        
        friend std::ostream& operator << (std::ostream& os, const Point& obj);

    };
    
    //There is no such factory in Gang of Four, only Abstract Factory and Factory Method.
    //This is concrete factory.
    struct PointFactory {
        //static is optional can be done and without static.
        //Factory Method for creation a point in cartesian coords
        static Point newCartesian(const float& x, const float& y);
        //Factory Method for creation a point in polar coord system.
        static Point newPolar(const float& r, const float& theta);
    };
    
    extern void testFactoryMethod();
}

#endif /* FACTORY_H */

