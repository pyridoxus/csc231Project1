//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "square.h"
#include <iostream>
using namespace std;

// Create the square
Square::Square(GLfloat xp, GLfloat yp, GLfloat w, GLfloat h)
{
	this->data[0] = this->data[6] = xp;
	this->data[1] = this->data[3] = yp;
	this->data[2] = this->data[4] = xp + w;
	this->data[5] = this->data[7] = yp + h;
//	cout<<"Square is: ("<<this->data[0]<<", "<<this->data[1]<<"), " << \
//									"("<<this->data[2]<<", "<<this->data[3]<<"), " <<\
//									"("<<this->data[4]<<", "<<this->data[5]<<"), " <<\
//									"("<<this->data[6]<<", "<<this->data[7]<<"), " << endl;
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
  glBegin( GL_POLYGON );
  glVertex2fv( this->data );
  glVertex2fv( this->data + 2 );
  glVertex2fv( this->data + 4 );
  glVertex2fv( this->data + 6 );
  glEnd();
	return;
}
