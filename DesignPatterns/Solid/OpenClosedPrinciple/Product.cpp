/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Product.cpp
 * Author: default
 * 
 * Created on May 31, 2023, 12:27 PM
 */

#include <iostream>

#include "Product.h"

namespace Solid {

    Product::Product(const std::string& name, Color color, Size size) 
        : name{name},
          color{color},
          size{size} {
        
    }

    
    /////End of class Product
    
    //Class ProductFilter
    std::vector<Product*> ProductFilter::byColor(std::vector<Product*> items, Color color) {
        std::vector<Product*> result;
        for(auto& item : items) {
            if(item->color == color) {
                result.push_back(item);
            }
        }
        return result;
    }
    std::vector<Product*> ProductFilter::bySize(std::vector<Product*> items, Size size) {
        std::vector<Product*> result;
        for(auto& item : items) {
            if(item->size == size) {
                result.push_back(item);
            }
        }
        return result;
    }
    
    std::vector<Product*> ProductFilter::bySizeAndColor(std::vector<Product*> items, Color color, Size size) {
        std::vector<Product*> result;
        for(auto& item : items) {
            if(item->size == size && item->color == color) {
                result.push_back(item);
            }
        }
        return result;
        
        char c = 'a';
    }
    
    void colorFilterExample() {
        Product apple("Apple", Color::green, Size::small);
        Product tree("Tree", Color::green, Size::large);
        Product house("House", Color::blue, Size::large);
        
        std::vector<Product*> items{ &apple, &tree, &house };
        
        ProductFilter pf;
        auto greenThings = pf.byColor(items, Color::green);
        for(auto& item : greenThings) {
            std::cout << item->name << " is green" << std::endl;
        }
    }

    
    
    
    //Right Way

    void rightWayFilterExample() {
        Product apple("Apple", Color::green, Size::small);
        Product tree("Tree", Color::green, Size::large);
        Product house("House", Color::blue, Size::large);
        
        std::vector<Product*> items{ &apple, &tree, &house };
        
        BetterFilter bf;
        ColorSpecification green{Color::green};
        
        for(auto& item : bf.filter(items, green)) {
            std::cout << item->name << " is green 2" << std::endl;
        }
        
    }
    
    void genericWayFilterExample() {
        Product apple("Apple", Color::green, Size::small);
        Product tree("Tree", Color::green, Size::large);
        Product house("House", Color::blue, Size::large);
        
        std::vector<Product*> items{ &apple, &tree, &house };
        
        GenericFilter<Product> genericFilter;
        ColorSpecification green{Color::green};
        
        for(auto& item : genericFilter.filter(items, green)) {
            std::cout << item->name << " is green 3" << std::endl;
        }
    }
    
    void genericWayExample() {
        Product apple("Apple", Color::green, Size::small);
        Product tree("Tree", Color::green, Size::large);
        Product house("House", Color::blue, Size::large);
        
        std::vector<Product*> items{ &apple, &tree, &house };
        
        BetterFilter bf;
        ColorSpecification green{Color::green};

        SizeSpecification large(Size::large);
        GenericSpecification<Product> greenAndLarge(green, large);
        
        for(auto& item : bf.filter(items, greenAndLarge)) {
            std::cout << item->name << " is green and large " << std::endl;
        }
        
        //after operator && defined in Specification we can do now that
        auto combine = ColorSpecification(Color::blue) && SizeSpecification(Size::large);
        
        for(auto& item : bf.filter(items, combine)) {
            std::cout << item->name << " is blue and large " << std::endl;
        }
    }
}