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
#include "Primitive.h"

class Material;

class Sphere :public Primitive{

public: 
    float mRadius;
    Material *mMaterial; ///< Color and Material (Sphere)
    Sphere() {
        mRadius = 5;
    }
    
    Sphere(float radius, Material* material) {
        mRadius = radius;
        mMaterial = material;
    }
    
    virtual ~Sphere();
    

    void setRadius(float r);
    
    virtual bool intersect(const Ray& ray);
    virtual bool intersect(const Ray& ray, Intersection& isect);
    
    protected:
    bool solveQuadratic(float A, float B, float C, float& t0, float& t1);
    

};

#endif /* Sphere_h */
