//
//  Material.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 10/18/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef Material_h
#define Material_h


#include "Intersection.h"
#include "color.h"
#include <stdio.h>

class Material {
public:
    Material();
    ~Material();
protected:
    float mReflectivity = 0;
    float mTransparency = 0;
    float mRefractionIndex = 0;
    
    /// Returns the BRDF at the intersection is for the light direction L.
public:
    virtual
    Color evalBRDF(const Intersection& is, const Vector3D& L) = 0;
    
    /// Returns the reflectivity of the material in the range [0,1] at the intersection,
    /// where 0 means not reflective at all, and 1 gives a perfect mirror.
    virtual float getReflectivity(const Intersection& is) const { return mReflectivity; }
    /// Sets the reflectivity of the material.
    virtual void setReflectivity(float r) { mReflectivity=r; }
    /// Returns the transparency of the material in the range [0,1] at the intersection,
    /// where 0 is fully opaque, and 1 is fully transparent.
    virtual float getTransparency(const Intersection& is) const { return mTransparency; }
    /// Sets the transparency of the material.
    virtual void setTransparency(float t) { mTransparency=t; }
    /// Returns the index of refraction for the material.
    virtual float getIndexOfRefraction() const { return mRefractionIndex; }
    /// Sets the index of refraction. Empty space is 1, denser materials higher.
    virtual void setIndexOfRefraction(float n) { mRefractionIndex=n; }
};

#endif /* Material_hpp */
