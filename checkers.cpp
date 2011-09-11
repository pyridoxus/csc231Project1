#include "checkers.h"

// Setup the initial viewport
Checkers::Checkers(void)
{
	this->numHorizontal = 4;
	this->squares = 0;
	this->numSquares = 0;
	this->colorMode = 0;	// Initialize to black and white
	this->createSquares();
	return;
}

// Clean up
Checkers::~Checkers()
{
	this->deleteSquares();
	return;
}

// Increase number of horizontal squares
void Checkers::increase(void)
{
	this->numHorizontal++;
	this->createSquares();
	return;
}

// Decrease number of horizontal squares
void Checkers::decrease(void)
{
	if(this->numHorizontal > 2)
	{
		this->numHorizontal--;
		this->createSquares();
	}
	return;
}

// Toggle all squares between B/W and random color
void Checkers::toggleColors(void)
{
	this->colorMode = ~this->colorMode;
	this->createSquares();
	return;
}

// Draw all squares
void Checkers::draw(void)
{
	this->createSquares();
	return;
}

// Calculate total number of squares and make them
void Checkers::createSquares(void)
{
	GLfloat w, h;
	double f_numV, i_numV, frac_numV;
	int newNumSquares, numVertical;
	int count;
	glGetIntegerv( GL_VIEWPORT, this->windowParams );
	w = this->windowParams[2] / this->numHorizontal;
	f_numV = this->windowParams[3] / w;
	frac_numV = modf(f_numV, &i_numV);
	if(frac_numV <= 0.5) numVertical = i_numV;
	else numVertical = i_numV + 1;
	newNumSquares = this->numHorizontal * numVertical;
	h = this->windowParams[3] / numVertical;

	if(this->squares != 0)
	{
		this->deleteSquares();
	}
	this->numSquares = newNumSquares;
	this->squares = (Square **)malloc(this->numSquares * sizeof(Square *));

	count = 0;
	for(int y = 0; y < numVertical; y++)
	{
		for(int x = 0; x < this->numHorizontal; x++)
		{

			this->squares[count] = new Square(x, y, w, h);
			this->setColor(count);
			this->squares[count]->draw();
			count++;
		}
	}
	return;
}

void Checkers::deleteSquares(void)
{
	for(int i = 0; i < this->numSquares; i++)
	{
		delete this->squares[i];
	}
	free(this->squares);
	this->squares = 0;
	return;
}

// Set the color of square at index using colorMode.
void Checkers::setColor(int index)
{
	GLfloat r, g, b;
//	if(!this->colorMode)
//	{
//		// Do black and white checkers
//	}
//	else
//	{
		r = rand();
		g = rand();
		b = rand();
//	}
	this->squares[index]->setColor(r, g, b);
	return;
}
