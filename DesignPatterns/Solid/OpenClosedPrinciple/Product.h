/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Product.h
 * Author: default
 *
 * Created on May 31, 2023, 12:27 PM
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>


namespace Solid {

    enum class Color {
        red,
        orange,
        blue,
        green,
    };
    enum class Size {
        small, 
        medium, 
        large,
    };

    class Product {
    public:
        std::string name;
        Color color;
        Size size;

        Product(const std::string& name, Color color, Size size);

    private:

    };
    
    //Wrong approach cause we can be shipped already that binary to the client 
    //and we cant continue to add more functions...
    class ProductFilter {
    public:

        std::vector<Product*> byColor(std::vector<Product*> items, Color color);
        std::vector<Product*> bySize(std::vector<Product*> items, Size size);
        std::vector<Product*> bySizeAndColor(std::vector<Product*> items, Color color, Size size);
    };
    
    //Right approach for adding extensions, without modifications.
    template<typename T>
    class Specification {
    public:
        virtual bool isSatisfied(T* item) = 0;
        
        
    };
    
    template<typename T> 
    class Filter {
    public:
        virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
    };
    
    class BetterFilter : public Filter<Product>{
    public:
        std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override {
            std::vector<Product*> result;
            for(auto& item : items) {
                if(spec.isSatisfied(item)) {
                    result.push_back(item);
                }
            }
            return result;
        }
    };
    
    template<typename T>
    class GenericFilter : public Filter<T> {
    public:
        std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) override {
            std::vector<T*> result;
            for(auto& item : items) {
                if(spec.isSatisfied(item)) {
                    result.push_back(item);
                }
            }
            return result;
        }
    };
    
    //Specifications
    class ColorSpecification : public Specification<Product> {
    public:
        Color c;
        ColorSpecification(Color color) : c(color) {
        }
        
        bool isSatisfied(Product* item) override {
            return item->color == c;
        }
    }; 
    
    class SizeSpecification : public Specification<Product> {
    public:
        Size size;
        
        explicit SizeSpecification(const Size s) : size(s) {
        }
        
        bool isSatisfied(Product* item) override {
            return item->size == size;
        }
    };
    
    //Generic Specification
    template<typename T>
    class GenericSpecification : public Specification<T> {
    public:
        Specification<T>& first;
        Specification<T>& second;
        
        GenericSpecification(Specification<T>& f, Specification<T>& s) 
            : first{f},
              second{s} {
                
        }
        
        bool isSatisfied(T* item) override {
            return first.isSatisfied(item) && second.isSatisfied(item);
        }

        
    };
    
    template<typename T> GenericSpecification<T> operator && (Specification<T>&& left, Specification<T>&& right) {
        return {left, right};
    }
    
    extern void colorFilterExample();
    
    
    extern void rightWayFilterExample();
    
    extern void genericWayFilterExample();
    
    extern void genericWayExample();

}

#endif /* PRODUCT_H */

