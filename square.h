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
