//
//  Sphere.cpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#include "Sphere.h"


bool Sphere::solveQuadratic(float A, float B, float C, float& t0, float& t1) const {
    
    float d = B*B - 4.0f*A*C; if (d < 0.0f)
        return false;
    d = std::sqrt(d);
    t0 = (-B - d) / (2.0f*A); t1 = (-B + d) / (2.0f*A);
    return true;
}


bool Sphere::intersect(const Ray& ray) const {
    
    Vector3D direction = ray.getDirection();
    Point3D origin = ray.getOrigin();
    // Compute polynom coefficients.
    float A = direction.x*direction.x + direction.y*direction.y + direction.z*direction.z;
    float B = 2.0f * ( direction.x*origin.x + direction.y*origin.y + direction.z*origin.z );
    float C = origin.x*origin.x + origin.y*origin.y + origin.z*origin.z - mRadius*mRadius;
    // Solve quadratic equation for ray enter/exit point t0,t1.
    float t0, t1;
    // no real solutions -> ray missed
    if(!solveQuadratic(A,B,C,t0,t1))
        return false;
    
    return true;
    
    
    
}

bool Sphere::intersect(const Ray& ray, Intersection intersection) const {
    return true;
}