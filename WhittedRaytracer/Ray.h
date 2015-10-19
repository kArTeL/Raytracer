//
//  Ray.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/18/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef Ray_h
#define Ray_h

#include <stdio.h>

#include "RTMath.h"
#include "defines.h"
///Class to represent a Ray
class Ray {
    
public:
    ///Origin point.
    Point3D  mOrg;
    
    ///Directional 3d vector.
    Vector3D mDir;
    
    ///Minimum value that can be T.
    float mMinT = 0;
    
    ///Maximum value that can be T.
    float mMaxT  = INF;
    
public :
    
    /** Constructor without parameters
      * just initialize class variables with default values (x=0, y=0, z=0)
     */
    Ray() {
        ///Initialized with x=0, y=0, z=0
        mOrg  = Point3D();
        
        ///Initialized with x=0, y=0, z=0
        mDir = Vector3D();
    }
    
    /** Constructor with origin and dierection parameters.
     * Initialize class variables with parameters.
     */
    Ray(Point3D origin, Vector3D direction, float minT, float maxT ) {
        mOrg    = origin;
        mDir    = direction;
        mMinT  = minT;
        mMaxT   = maxT;
        
    }
    
    ///Origin getter
     Point3D getOrigin() const {
        return mOrg;
    }
    
    ///Direction getter
    const Vector3D getDirection() const {
        return mDir;
    }
    
    
    
    
};


#endif /* Ray_h */
