//
//  Primitive.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 10/18/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef Primitive_h
#define Primitive_h


#include "RTMath.h"
#include "Intersection.h"
#include "Ray.h"

#include <stdio.h>

class Primitive {
public:
    Primitive();
virtual~Primitive();
    void setTransform( Matrix&m );
    void translate( const Vector3D&t );
    void scale( const Vector3D&s );
    void rotate( const Vector3D&r );
    virtual bool intersect(const Ray& ray) = 0;
virtual bool intersect(const Ray& ray, Intersection& isect) = 0;
protected:
    bool prepared;
    Vector3D mT;
    Vector3D mS;
    Vector3D mR;
    Matrix mLocalTransform;
    Matrix mWorldTransform;
    Matrix& toLocal();
    Matrix& toGlobal();
private:
    void calculateTransform();
};

#endif /* Primitive_hpp */
