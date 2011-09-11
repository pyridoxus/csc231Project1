#ifndef SQUARE_H_
#define SQUARE_H_
#include <GL/glut.h>

class Square
{
	public:
		Square(GLfloat xp, GLfloat yp, GLfloat w, GLfloat h); // Create the square
		void setColor(GLfloat r, GLfloat g, GLfloat b);	// Set the color
		void draw(void);	// Draw the polygon into the buffer
	private:
		GLfloat data[8];	// Hold all coordinates of the vertices
		GLfloat color[3];	// Hold all color components
};

#endif
