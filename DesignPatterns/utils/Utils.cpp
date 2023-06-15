/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Utils.h"


namespace Utils {
    float Q_rsqrt(float number) {
        long i;
        float x2, y;
        const float treehalfs = 1.5F;
        
        x2 = number * 0.5F;
        y = number;
        i = * ( long* ) &y;                       //evil floating point bit hack
        i = 0x5f3759df - ( i >> 1 );              //what the fuck
        y = * ( float* ) &i;
        y = y * (treehalfs - (x2 * y * y));       //1st iteration
//        y = y * (treehalfs - (x2 * y * y));     //2nd iteration
        
        return y;
    }
}