//
//  main.cpp
//  RT_Lab01
//
//  Created by Edgar Benavides.
//  Copyright (c) 2014 E.Benavides. All rights reserved.
//

#include <iostream>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include "defines.h"
#include "Raytracer.h"
#include "Sphere.h"
#include "Color.h"
#include "Camera.h"

Color **buffer;


void draw_scene() {
    int i, j;
    
    for (i = 0; /*last_x;*/ i < H_SIZE; i++) {
        for (j = 0; j < V_SIZE; j++) {
            glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
            glBegin(GL_POINTS);
            glVertex2i(i,j);
            glEnd();
        }
    }
    glFlush();
}

void initializeCanvas()
{
    int i, j;
    
    buffer = (Color **)calloc(H_SIZE, sizeof(Color * ) );
    for (i = 0; i < H_SIZE; i++) {
        buffer[i] = (Color *)calloc(V_SIZE,sizeof(Color));
    }
    
    for (i = 0; i < H_SIZE; i++) {
        for (j = 0; j < V_SIZE; j++) {
            buffer[i][j].r = 0;
            buffer[i][j].g = 0;
            buffer[i][j].b = 0;
        }
    }
}


void startRaytracer()
{
    Sphere sphere =  Sphere(20);
    Camera camera = Camera();
    Point3D origin = Point3D(100, 100, 0);
    Point3D target = Point3D(140, 140, 1);
    
    camera.setLookAt(origin, target, origin,30.0f);
        //camera.mOrigin = origin;
    Raytracer rayTracer = Raytracer(buffer, &camera,&sphere);
    
    rayTracer.computeImage();
//
    
    
    
    
    
//    int i, j;
//    for ( i = 0; i < H_SIZE; i++ ) {
//        for ( j = 0; j < V_SIZE; j++ ) {
//            if ( i == j ) {
//                buffer[i][j] = Color( 1, 1, 1 );
//                buffer[H_SIZE - i - 1][ j ] = Color( 1, 1, 1 );
//            }
//        }
//    }
}


int main(int argc, char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // Initialize buffer used to store color pixels
    initializeCanvas();
    
    // Start rendering the scene
    startRaytracer();
    
    // Show the canvas using OpenGL
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize( H_SIZE, V_SIZE );
    glutCreateWindow("Raytracer LAB");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
    glutDisplayFunc(draw_scene);
    glutMainLoop();
    
    
    return 0;
}
