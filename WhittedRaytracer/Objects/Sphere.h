//
//  Sphere.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef Sphere_h
#define Sphere_h

#include <stdio.h>
#include "Ray.h"
#include "RTMath.h"
#include "Intersection.h"

class Sphere {

public: 
    float mRadius;

    Sphere() {
        mRadius = 5;
    }
    
    Sphere(float radius) {
        mRadius = radius;
    }

    bool solveQuadratic(float A, float B, float C, float& t0, float& t1) const;
    
    bool intersect(const Ray& ray) const;
    
    bool intersect(const Ray& ray, Intersection& intersection) const;
};

#endif /* Sphere_h */
