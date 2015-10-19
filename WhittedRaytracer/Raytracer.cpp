//
//  Raytracer.cpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 9/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#include "Raytracer.h"
#include "Defines.h"
#include "PointLight.h"
#include "Material.h"

Raytracer::Raytracer(Color **img, Camera *cam,Sphere *scenario,PointLight* light  ) {
    mImage = img;
    mCamera = cam;
    mScene = scenario;
    mLight = light;
}

void Raytracer::computeImage() {
    int height = V_SIZE;
    int width  = H_SIZE;
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
        
        // Raytrace the pixel at (x,y).
        Color c = tracePixel(x,y);
        // Store the result in the image.
        mImage[x][y] = c;
            
        }
        // Print progress approximately every 5%.
        if ((y+1) % (height/20) == 0 || (y+1) == height) {
            std::cout << (100*(y+1)/height) << "% done" << std::endl;
        }
    }
}

Color Raytracer::tracePixel(int x, int y) {
    // Default color is black
    Color pixelColor = Color(0.0f, 0.0f, 0.0f);
    // Center of the pixel.
    float cx = (float)x + 0.5f; float cy = (float)y + 0.5f;
    // Let the camera setup the ray.
    Ray ray = mCamera->getRay(cx,cy);
    pixelColor = trace( ray, 0 );
    return pixelColor;
}

Color Raytracer::trace(const Ray& ray, int depth) {
    Intersection i;
    if (mScene->intersect(ray, i)) {
        Vector3D light = i.mPosition - this->mLight->getPosition();
        light.normalize();
        return i.mMaterial->evalBRDF( i, light );
    }
    else {
        return Color(0,0,0); // Background color
    }
}