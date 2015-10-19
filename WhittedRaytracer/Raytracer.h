//
//  Raytracer.hpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#ifndef Raytracer_h
#define Raytracer_h

#include <stdio.h>
#include "color.h"
#include "Camera.h"
#include "Sphere.h"

class PointLight;

class Raytracer {
    
private:
    
    PointLight *mLight;
    Color **mImage;
    Sphere *mScene;
    Camera *mCamera;
    
    Color tracePixel(int x, int y);
    Color trace(const Ray& ray, int depth);
    
public:
    Raytracer(Color **img, Camera *cam,Sphere *scenario,PointLight* light );
    void computeImage();
    
   
};
#endif /* Raytracer_hpp */
