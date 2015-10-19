//
//  Primitive.cpp
//  WhittedRaytracer
//
//  Created by Neil García Vargas on 10/18/15.
//  Copyright © 2015 Neil García Vargas. All rights reserved.
//

#include "Primitive.h"
Primitive::~Primitive()
{
    
}

Primitive::Primitive() {
    this->mLocalTransform.identity();
    this->mWorldTransform.identity();
    this->prepared= true;
    this->mS= Vector3D(1);
    this->mR= Vector3D(0);
    this->mT= Vector3D(0);
}

void Primitive::setTransform( Matrix &m )
{
    this->mLocalTransform = m;
    this->mWorldTransform = m.inverse();
    prepared = true;
}
void Primitive::translate( const Vector3D &t )
{
    this->prepared = false;
    this->mT = t;
}
void Primitive::scale( const Vector3D &s )
{
    this->prepared = false;
    mS = s;
}
void Primitive::rotate( const Vector3D &r )
{
    this->prepared = false;
    mR = r;
}
void Primitive::calculateTransform()
{
    Matrix Rx, Ry, Rz, S, T;
    Rx.rotX(mR.x);
    Ry.rotY(mR.y);
    Rz.rotZ(mR.z);
    S.scale(mS.x,mS.y,mS.z);
    T.translation(mT.x,mT.y,mT.z);
    
    mLocalTransform = T*Rz*Ry*Rx*S;
    
    mWorldTransform = mLocalTransform.inverse();
}

Matrix& Primitive::toLocal( )
{
    if (!prepared) {
        calculateTransform();
        prepared = true;
    }
    return( this->mLocalTransform );
    
}
Matrix& Primitive::toGlobal( )
{
    if (!prepared) {
        calculateTransform();
        prepared = true;
    }
    return( this->mWorldTransform );
}
