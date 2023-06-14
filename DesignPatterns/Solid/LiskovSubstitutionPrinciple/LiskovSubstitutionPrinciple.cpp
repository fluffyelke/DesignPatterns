/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "LiskovSubstitutionPrinciple.h"


namespace Solid {
    Rectangle::Rectangle(const int& width, const int& height) :
        width(width), height(height) {
    }

    int Rectangle::getHeight() const {
        return height;
    }

    void Rectangle::setHeight(const int& height) {
        this->height = height;
    }

    int Rectangle::getWidth() const {
        return width;
    }

    void Rectangle::setWidth(const int& width) {
        this->width = width;
    }

    int Rectangle::area() const {
        return width * height;
    }
    
    void process(Rectangle& r) {
        int w = r.getWidth();
        r.setHeight(10);
        
        std::cout << "excpected area: " << (w * 10) << ", we got: " << r.area() << std::endl;
    }
    void testProcess() {
        Rectangle r{3, 4};
        process(r);
        
        //to avoid such wrongs, we can use flag in rectangle to check if the 
        //rect is square, or we can create Factory. Check next chapters.
        Square sq{5};
        process(sq);
    }

    
    
    //class Square
    Square::Square(const int& size) 
        : Rectangle(size, size) {
    }

    void Square::setHeight(const int& height) {
        this->height = this->width = height;        //this broke the liskov substitution
    }

    void Square::setWidth(const int& width) {
        this->width = this->height = width;         //this broke the liskov substitution
    }

}