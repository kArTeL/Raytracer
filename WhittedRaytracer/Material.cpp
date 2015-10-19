//
//  Material.cpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 10/18/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#include "Material.h"

Material::Material() {
    mReflectivity = 0;
    mRefractionIndex= 0;
    mTransparency = 0;
}

Material::~Material() {
    
}