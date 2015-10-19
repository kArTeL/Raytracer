//
//  PointLight.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 10/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef PointLight_h
#define PointLight_h

#include <stdio.h>
#include "Primitive.h"

class PointLight:public Primitive {
public:
    PointLight();
    PointLight(const Point3D& p, const Color& c, float i=1.0f);
    virtual ~PointLight();
    
    void setPosition(const Point3D& p);
    void setColor(const Color& c);
    void setIntensity(float i);
    Color getRadiance();
    Point3D getPosition();
    
    virtual bool intersect(const Ray& ray);
    virtual bool intersect(const Ray& ray, Intersection& isect);
    
protected:
    float mIntensity; ///< Intensity (multiplication factor).
    Color mColor; ///< Color of light.
    Point3D mPosition; ///< Position of light (local space).
    Color mRadiance; ///< Cached intensity*color.
    
    
};

#endif /* PointLight_hpp */
