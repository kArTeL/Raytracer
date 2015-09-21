//
//  Camera.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/18/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef Camera_h
#define Camera_h

#include <stdio.h>

#include "RTMath.h"
#include "Defines.h"
#include "Ray.h"

///Class to represent the camera image and perspective.
class Camera {
    
private:
    ///Camera origin in a 3D space representation.
    Point3D mOrigin;
    
    ///3D vector that indicate where you point the camera.
    Vector3D mForward;
    Vector3D mRight;
    Vector3D mUp;
    
    ///Distance to the nearest plane from the scene.
    float mNearPlane;
    
    ///Distance to the farthest plane from the scene.
    float mFarPlane;
    
    ///Field of view of the camera in radians.
    float mFieldOfView;
    
    //Camera horizontal extension.
    float mImageExtentX;
    
    ///Camera vertical extension.
    float mImageExtentY;

    
public:
    ///Set camera to look at a specific area.
    void setLookAt(const Point3D& pos, const Point3D& target, const Vector3D& up, float fov, float near=1.0f, float far=100.0f);
    
    ///Determ the ray passing through the point (x,y)
    Ray getRay(float x, float y) const;
    
    
};



#endif /* Camera_h */
