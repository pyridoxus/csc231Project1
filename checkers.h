#ifndef CHECKERS_H_
#define CHECKERS_H_

#include "square.h"

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
		int calcNumSquares(void); // Calculate total number of squares
		int numHorizontal;		// Number of horizontal squares
		float windowParams[4];	// Used for getting H and W of viewport
		Square *squares;	// Pointer to array of squares
};

#endif /* CHECKERS_H_ */
