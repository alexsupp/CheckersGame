#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Grid.h"
#include <new>

// Red is on top Black is on bottom

int convertLetter(char a)
{
	int x;
	x=a-65;
	if(x>9)
		x-=32;	
	if(x<0||x>9)
		return -1;
	return x;
}

int convertNumber(char a)
{
	int x;
	x=a-49;
	return x;
}

int main()
{
	enum turns {blackTurn, redTurn};
	turns turn = redTurn;
	int redPieces = 16;
	int blackPieces = 16;
	bool gameOver = false;
	Grid gridBoard;
	char from[2], to[2];
	int fromPos[2], toPos[2];

	while(!gameOver)
	{
		std::cout << gridBoard << endl;
		std::cout << "Enter move: ";
		std::cin>>from;
		std::cin>>to;
		fromPos[0]=convertLetter(from[0]);
		fromPos[1]=convertNumber(from[1]);
		toPos[0]=convertLetter(to[0]);
		toPos[1]=convertNumber(to[1]);
		
		switch(turn)
		{
			case blackTurn:
				if(gridBoard.getPosition(fromPos[0],fromPos[1]).color==BLACK)
					gridBoard.move(fromPos, toPos);			
				break;

			case redTurn:

				break;
		}	
	}
	return 0;
}
