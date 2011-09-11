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
