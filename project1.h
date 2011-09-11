#ifndef PROJECT1_H_
#define PROJECT1_H_

#include <iostream>
using namespace std;
#include <stdlib.h> // for exit() in Linux
#include <GL/glut.h>
#include "checkers.h"

void myInit();
void myDraw();
void keyboard( unsigned char, int, int );
void menu( int );
void increase(void);
void decrease(void);
void toggleColors(void);


Checkers checkers;
#endif
