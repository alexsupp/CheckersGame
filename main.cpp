#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Grid.h"
#include <new>

// Red is on top Black is on bottom
int main()
{
	enum turns {blackTurn, redTurn};
	turns turn = redTurn;
	int redPieces = 16;
	int blackPieces = 16;
	bool gameOver = false;
	Grid gridBoard;
	char position[2];


	while(!gameOver)
	{
		std::cout << gridBoard << endl;
		std::cout << "Please type the position you which to move from: ";
		
		std::cin>>position;
		switch(turn)
		{
			case blackTurn:

				break;

			case redTurn:

				break;
		}	
	}
	return 0;
}

