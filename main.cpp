#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Grid.h"
#include <new>

// Red is on top Black is on bottom
void instructions()
{
	cout<<"/tCheckers/n"<<
	"Each player takes turns moving their pieces diagonally/n"<<
	"Pieces may only move forward until they reach the opposite side/n"<<
	"If a piece reaches the opposite side it becomes a KING and can/n"<<
	"move in any direction. State your moves with the letter column first/n"<<
	"then the row number. i.e. Move: A5 A6"<<endl;
}

int convertLetter(char a)
{
	int x;
	x=a-65;
	if(x>9)	x-=32;
	if(x<0 || x>7)	return -1;
	return x;
}

int convertNumber(char a)
{
	int x;
	x=a-49;
	if(x<0 || x>7) return -1;
	return x;
}

int main()
{
	enum turns {
		blackTurn,
		redTurn
	};
	turns turn = redTurn;
	int redPieces = 12;
	int blackPieces = 12;
	bool gameOver = false;
	bool invalid = false;
	Grid gridBoard;
	char from[2], to[2];
	int fromPos[2], toPos[2];

	instructions();

	while(!gameOver)
	{
		std::cout << gridBoard << endl;
		if(invalid)
			std::cout << "Invalid move, please try again" <<endl;
		std::cout << "Enter move ";
		if(turn==blackTurn)
			cout<<"Black: ";
		else
			cout<<"Red: ";
		std::cin >> from >> to;

		fromPos[0] = convertLetter(from[0]);
		fromPos[1] = convertNumber(from[1]);
		toPos[0] = convertLetter(to[0]);
		toPos[1] = convertNumber(to[1]);

		if(fromPos[0] == -1 || fromPos[1] == -1 || toPos[0] == -1 || fromPos[1] == -1)
			invalid = true;
		else
			invalid = false;

		if(!invalid)
		{
			switch(turn)
			{
				case blackTurn:
					if((gridBoard.getPosition(fromPos[0],fromPos[1]).color != BLACK)
						|| (gridBoard.move(fromPos, toPos) == -1))
					{
						invalid = true;
						break;
					}
					turn = redTurn;
					break;

				case redTurn:
					if((gridBoard.getPosition(fromPos[0],fromPos[1]).color != RED)
						|| (gridBoard.move(fromPos, toPos) == -1))
					{
						invalid = true;
						break;
					}
					turn = blackTurn;
					break;
			}//end turn switch
		}//end invalid check
	}//end while
	return 0;
}
