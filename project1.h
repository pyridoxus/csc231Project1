#ifndef PROJECT1_H_
#define PROJECT1_H_

#include <GL/glut.h>
#include "checkers.h"

void myInit();
void myDraw();
void keyboard( unsigned char, int, int );
void menu( int );

Checkers checkers;
#endif
