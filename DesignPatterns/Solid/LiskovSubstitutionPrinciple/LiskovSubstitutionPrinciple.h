/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LiskovSubstitutionPrinciple.h
 * Author: default
 *
 * Created on June 14, 2023, 11:27 AM
 */

#ifndef LISKOVSUBSTITUTIONPRINCIPLE_H
#define LISKOVSUBSTITUTIONPRINCIPLE_H

namespace Solid {
    
    class Rectangle {
    protected:
        int width, height;
    public:
        Rectangle(const int& width, const int& height);

        int getHeight() const;

        virtual void setHeight(const int& height);

        int getWidth() const;

        virtual void setWidth(const int& width);
        
        int area() const;

    };
    
    extern void process(Rectangle& r);
    extern void testProcess();
    
    
    //Continue for example lets create Square class which inherits from Rectangle
    //lets assume the setWidth, setHeight are virtual, till now they were not.
    class Square : public Rectangle {
    public:
        Square(const int& size);
        void setHeight(const int& height) override;
        void setWidth(const int& width) override;
    };
}


#endif /* LISKOVSUBSTITUTIONPRINCIPLE_H */

