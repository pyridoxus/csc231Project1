#include "square.h"

// Create the square
Square::Square(GLfloat xp, GLfloat yp, GLfloat w, GLfloat h)
{
	this->data[0] = this->data[6] = xp;
	this->data[1] = this->data[3] = yp;
	this->data[2] = this->data[4] = xp + w;
	this->data[5] = this->data[7] = yp + h;
	return;
}

void Square::setColor(GLfloat r, GLfloat g, GLfloat b)
{
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
	return;
}

void Square::draw(void)
{
  glColor3fv( this->color );
  glBegin( GL_POINTS );
  glVertex2fv( this->data );
  glVertex2fv( this->data + 2 );
  glVertex2fv( this->data + 4 );
  glVertex2fv( this->data + 6 );
  glEnd();
	return;
}