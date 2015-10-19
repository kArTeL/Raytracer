//
//  PointLight.cpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 10/19/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#include "PointLight.h"

PointLight::PointLight(const Point3D& p, const Color& c, float i) {
    this->mPosition = p;
    mIntensity = i;
    this->mColor = c;
}

PointLight::PointLight() {
    
}
PointLight::~PointLight()
{
    
}
void PointLight::setPosition(const Point3D& p){
    this->mPosition = p;
}
void PointLight::setColor(const Color& c){
    this->mColor = c;
}
void PointLight::setIntensity(float i)
{
    mIntensity = i;
    
}

Color PointLight::getRadiance()
{
    return mRadiance;
}

Point3D PointLight::getPosition()
{
    return this->toGlobal() * mPosition;
}

bool PointLight::intersect(const Ray& ray) {return true;}
bool PointLight::intersect(const Ray& ray, Intersection& isect){return true;}

