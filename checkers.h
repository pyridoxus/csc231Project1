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
#ifndef CHECKERS_H_
#define CHECKERS_H_

#include <iostream>
using namespace std;
#include "square.h"
#include <math.h>
#include <stdlib.h>

class Checkers
{
	public:
		Checkers(void);		// Setup the initial viewport
		~Checkers();		// Clean up
		void increase(void);	// Increase number of horizontal squares
		void decrease(void);	// Decrease number of horizontal squares
		void toggleColors(void);	// Toggle all squares between B/W and random color
		void draw(void);	// Draw all squares
	private:
		void createSquares(void); // Calculate total number of squares and make them
		void deleteSquares(void);	// Free all memory allocated to all squares
		void setColor(int index);	// Set the color of square
		int numSquares;		// Number of squares
		int numHorizontal;		// Number of horizontal squares
		int windowParams[4];	// Used for getting H and W of viewport
		int colorMode;	// 0 = black and white, -1 = random colors
		Square **squares;	// Pointer to array of pointers to squares
};

#endif /* CHECKERS_H_ */
