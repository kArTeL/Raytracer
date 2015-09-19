//
//  Camera.cpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/18/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#include "Camera.h"


///Set camera to look at a specific area.
void Camera::setLookAt(const Point3D& pos, const Point3D& target, const Vector3D& up, float fov, float near, float far)
{
    // Set camera origin, near/far plane.
    mOrigin     = pos;
    mNearPlane  = near;
    mFarPlane   = far;
    
    // Setup orthogonal camera frame defined by right,forward,up vectors.
    mForward = target - pos;
    mForward.normalize();
    mRight   = mForward % up;
    mRight.normalize();
    mUp      = mRight % mForward;
    
    // Compute extent of image plane from the given field-of view,
    // where the image plane is at unit distance from the origin
    // in the local camera frame.
    float aspect = (float)(H_SIZE) / (float)(V_SIZE); // Compute aspect ratio.
    mImageExtentX = std::tan(0.5f * fov * M_PI/180.0f);
    mImageExtentY = std::tan(0.5f * fov/aspect * M_PI/180.0f);
    mFieldOfView = fov;
}

///Determ the ray passing through the point (x,y)
Ray Camera::getRay(float x, float y) const {
    
    Vector3D right  = 2.0f/(float)(H_SIZE) * mImageExtentX * mRight;
    Vector3D up     = -2.0f/(float)(V_SIZE) * mImageExtentY * mUp;
    Vector3D view   = mForward - mImageExtentX * mRight + mImageExtentY * mUp;
    Vector3D d      = view + x*right + y*up; float dLength = d.length();
    d /= dLength;
    return Ray(mOrigin, d, mNearPlane, mFarPlane);
}