/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InnerFactory.h
 * Author: default
 *
 * Created on June 15, 2023, 4:24 PM
 */

#ifndef INNERFACTORY_H
#define INNERFACTORY_H

namespace InnerFactory {
    //InnerFactory - Provide the hint to the user how to create an object. Factory is the inner to the class
    //
    enum class PointType {
        cartesian,
        polar,
    };

    class Point {
        Point(const float& x, const float& y);
    public:
        float x, y; 
        friend std::ostream& operator << (std::ostream& os, const Point& obj);
        
        //we can make the factory singleton to hide the inner class
        
    private:
        //This is inner factory.
        class PointFactory {
            PointFactory();
        public:
            //static is optional can be done and without static.
            //Factory Method for creation a point in cartesian coords
            static Point newCartesian(const float& x, const float& y);
            //Factory Method for creation a point in polar coord system.
            static Point newPolar(const float& r, const float& theta);
        };
        
    public:
        static PointFactory Factory;
    };
    
    extern void testFactoryMethod();
}

#endif /* INNERFACTORY_H */

