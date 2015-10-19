//
//  Diffuse.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 10/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef Diffuse_h
#define Diffuse_h

#include <stdio.h>
#include "Material.h"

class Diffuse : public Material {
protected:
    Color mColor;
public:
    Diffuse( Color c );
    ~Diffuse(){}
    virtual Color evalBRDF(const Intersection& is, const Vector3D& L);
};

#endif /* Diffuse_hpp */
