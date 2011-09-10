/**********************************************************************
Project Checkerboard

Description
-----------
Design and implement a two-dimensional resizable checkerboard.


Details
Draw a checkerboard pattern of equal-sized black and white checker squares (polygons)
that fill the entire viewport. Draw the initial checkboard pattern with 4 checkers
in the horizontal direction and compute the number of rows of vertical checkers
based on the width and height of the viewport. Recompute the sizes and number of
rows of vertical checkers if the window viewport is resized. Make every effort to
draw each checker as an equal-sized square regardless of the viewport dimensions.
Provide a GLUT pop-up menu and keyboard callbacks to perform the following:
•	increase number of horizontal checkers (or '+' key)
•	decrease number of horizontal checkers (or '-' key)
•	toggle black/white colors with random colors (or 'c' key)
•	exit program (or 'q' key)

**********************************************************************/

#include <iostream>
using namespace std;
#include <math.h>
#include <stdlib.h> // for exit() in Linux
#include <GL/glut.h>

void myInit();
void myDraw();
void keyboard( unsigned char, int, int );
void menu( int );
void increase(void);
void decrease(void);
void toggleColors(void);

int main( int argc, char *argv[] )
{
  // Initialize window system
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
  glutInitWindowSize( 640, 480 );
  glutCreateWindow( "Checkerboard" );

  // Initialize graphics
  myInit();

  // Display callback
  glutDisplayFunc( myDraw );

	// Keyboard callback
	glutKeyboardFunc( keyboard );

	// Pop-up menu
  glutCreateMenu( menu );
	glutAddMenuEntry( "Increase Horizontal Squares ('+' key)", 1 );
	glutAddMenuEntry( "Decrease Horizontal Squares ('-' key)", 2 );
	glutAddMenuEntry( "Toggle (black/white, or random colors) ('c' key)", 3 );
	glutAddMenuEntry( "Exit ('q' key)", 4 );
  glutAttachMenu( GLUT_RIGHT_BUTTON );

	// Event loop
  glutMainLoop();

  return 0;
}

// Initialize drawing
void myInit()
{
  // Background color
  glClearColor(0.0, 0.0, 0.0, 0.0);

  // Projection
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho( -2.0, 2.0, -2.0, 2.0, -2.0, 2.0 );
}

// Display callback
void myDraw()
{
  // Clear the screen
  glClear(GL_COLOR_BUFFER_BIT );

  // Example code to draw 4 white points
  // Draw your points here
  glColor3f( 1.0, 1.0, 1.0 );
  glBegin( GL_POINTS );
  glVertex3f( -0.25, -0.25, 0.0 );
  glVertex3f( 0.25, -0.25, 0.0 );
  glVertex3f( 0.25, 0.25, 0.0 );
  glVertex3f( -0.25, 0.25, 0.0 );

  glEnd();

  // Execute draw commands
  glFlush();
}

// Keyboard callback
void keyboard( unsigned char key, int x, int y )
{
  // Process keys
  switch (key)
    {
		case 'q':			// exit program
			exit(1);
			break;
		case '+':			// increase number of horizontal squares
			increase();
			break;
		case '-':			// decrease number of horizontal squares
			decrease();
			break;
		case 'c':			// toggle between black/white and random colors
			toggleColors();
			break;
    }

  // Redraw the scene
  glutPostRedisplay();
}

// Menu callback
void menu( int value )
{
  switch( value )
    {
		case 1:			// increase number of horizontal squares
			increase();
      break;
		case 2:			// decrease number of horizontal squares
			decrease();
      break;
		case 3:			// toggle between black/white and random colors
			toggleColors();
      break;
		case 4:			// exit program
      exit(1);
      break;
    }

	// Redraw the scene
  glutPostRedisplay();
}

void increase(void)
{
	return;
}

void decrease(void)
{
	return;
}

void toggleColors(void)
{
	return;
}