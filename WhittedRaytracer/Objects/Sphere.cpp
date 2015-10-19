//
//  Sphere.cpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#include "Sphere.h"

Sphere::~Sphere() {
    
}
bool Sphere::solveQuadratic(float A, float B, float C, float& t0, float& t1) {
    
    float d = B*B - 4.0f*A*C; if (d < 0.0f)
        return false;
    d = std::sqrt(d);
    t0 = (-B - d) / (2.0f*A); t1 = (-B + d) / (2.0f*A);
    return true;
}


bool Sphere::intersect(const Ray& ray)
{
    Vector3D d = toLocal() * ray.getDirection(); //  Nuevo
    Point3D o = toLocal() * ray.getOrigin(); //  Nuevo
    // Compute polynom coefficients.
    float A = d.x*d.x + d.y*d.y + d.z*d.z;
    float B = 2.0f * ( d.x*o.x + d.y*o.y + d.z*o.z );
    float C = o.x*o.x + o.y*o.y + o.z*o.z - mRadius*mRadius;
    
    // Solve quadratic
    float t0, t1;
    if(!solveQuadratic(A,B,C,t0,t1)) return false;
    if(t0>ray.mMaxT || t1<ray.mMinT) return false;
    if(t0<ray.mMinT && t1>ray.mMaxT) return false;
    return true;
}
bool Sphere::intersect(const Ray& ray, Intersection& isect)
{
    isect.mMaterial = this->mMaterial;
    isect.mPrimitive = this;
    Vector3D d = toLocal() * ray.getDirection(); //  Nuevo!
    Point3D o = toLocal() * ray.getOrigin(); //  Nuevo!
    
    float A = d.x*d.x + d.y*d.y + d.z*d.z;
    float B = 2.0f * ( d.x*o.x + d.y*o.y + d.z*o.z );
    float C = o.x*o.x + o.y*o.y + o.z*o.z - mRadius*mRadius;
    
    float t0, t1;
    if(!solveQuadratic(A,B,C,t0,t1)) return false;
    if(t0>ray.mMaxT || t1<ray.mMinT) return false;
    if(t0<ray.mMinT && t1>ray.mMaxT) return false;
    // Compute hit position & normal at hit point.
    float t = t0<ray.mMinT ? t1 : t0;
    Point3D p = o + t*d;
    Vector3D n = p;
    n /= mRadius;
    
    // Compute info about the intersection point.
    isect.mRay = ray;
    isect.mT = t;
    isect.mPosition = p; // Store world space hit point.
    isect.mNormal = n; // Store world space normal.
    isect.mNormal.normalize(); // just in case
    isect.mView = -ray.getDirection();
    isect.mFrontFacing = isect.mView.dot(isect.mNormal) > 0.0f;
    if (!isect.mFrontFacing) isect.mNormal = -isect.mNormal;
    
    return true;
}


