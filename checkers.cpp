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
#include "checkers.h"

// Setup the initial viewport
Checkers::Checkers(void)
{
	this->numHorizontal = 4;
	this->squares = 0;
	this->numSquares = 0;
	this->colorMode = 0;	// Initialize to black and white
//	cout<<"Initialize Checkers:"<<endl;
//	cout<<"this->numHorizontal= "<<this->numHorizontal<<endl;
//	cout<<"this->squares= "<<this->squares<<endl;
//	cout<<"this->numSquares= "<<this->numSquares<<endl;
//	cout<<"this->colorMode= "<<this->colorMode<<endl;
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

//	cout<<"Creating Squares:"<<endl;
//	cout<<"Width of squares= "<<w<<endl;
//	cout<<"Number of vertical squares= "<<numVertical<<endl;
//	cout<<"Height of squares= "<<h<<endl;
//	cout<<"Total Number of Squares= "<<newNumSquares<<endl;

	if(this->squares != 0)
	{
//		cout<<"Allocated once before..."<<endl;
		this->deleteSquares();
	}
	this->numSquares = newNumSquares;
	this->squares = (Square **)malloc(this->numSquares * sizeof(Square *));
//	cout<<"this->squares allocated at "<<this->squares<<endl;
	count = 0;
	for(int y = 0; y < numVertical; y++)
	{
		for(int x = 0; x < this->numHorizontal; x++)
		{
			// Store coordinates and sizes as normalized values in order to fit
			// inside the projection that was initially setup.
			this->squares[count] = new Square(x * w / this->windowParams[2],
																				y * h / this->windowParams[3],
																				w / this->windowParams[2],
																				h / this->windowParams[3]);
			this->setColor(count);
			this->squares[count]->draw();
//			cout<<"Square["<<count<<"] = "<<"("<<x*w<<", "<<y*h<<", "<<w<<", "<<h<<")"<<endl;
			count++;
		}
	}
	return;
}

void Checkers::deleteSquares(void)
{
//	cout<<"Deleting all squares..."<<endl;
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
	int invert;
	if(!this->colorMode)
	{
		// Do black and white checkers
		// The basis for alternating the colors is (index % 2), but the alternating
		// needs to be inverted between every row, but only if there are an even
		// number of horizontal squares.
		if(this->numHorizontal % 2 == 0) invert = index / this->numHorizontal;
		else invert = 0;
		if((index % 2) ^ (invert % 2)) r = g = b = 1.0;
		else r = g = b = 0.0;
//		cout<<"index="<<index<<" horz="<<this->numHorizontal<<" invert="<<invert;
//		cout<<" color="<<r<<endl;
	}
	else
	{
		r = (rand() % 256) / 256.0;
		g = (rand() % 256) / 256.0;
		b = (rand() % 256) / 256.0;
	}
//	cout<<"Storing color of: ("<<r<<", "<<g<<", "<<b<<")"<<endl;
	this->squares[index]->setColor(r, g, b);
	return;
}
