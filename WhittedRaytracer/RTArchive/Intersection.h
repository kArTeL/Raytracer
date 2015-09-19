//
//  Intersection.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef Intersection_h
#define Intersection_h

#include <stdio.h>
#include "Ray.h"
#include "RTMath.h"

///Intersection struct, is struct because we need access to all the properties, and it is not referency, it's a copy of each variable.
struct Intersection {
    
    ///Ray that cause the intersection.
    Ray mRay;
    
    //Intersection position in 3D.
    Point3D mPosition;
    
    ///Normal vector on the object surface.
    Vector3D mNormal;
    
    //Determ if the normal vector points outside or inside.
    bool mFrontFacing;
    
    Vector3D mView;
    
    float mT;
};


#endif /* Intersection_hpp */
