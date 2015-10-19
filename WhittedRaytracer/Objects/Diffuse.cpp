//
//  Diffuse.cpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 10/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#include "Diffuse.h"

Diffuse::Diffuse( Color c ){
    this->mColor = c;
}

Color Diffuse::evalBRDF(const Intersection& is, const Vector3D& L)
{
    // color * DotProduct between N and L
    Color r = mColor * (is.mNormal.dot(L));
    return r;
}