#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Grid.h"
#include <new>

// Red is on top Black is on bottom
void instructions()
{
	cout<<"\tCheckers\n"<<
	"Each player takes turns moving their pieces diagonally\n"<<
	"Pieces may only move forward until they reach the opposite side\n"<<
	"If a piece reaches the opposite side it becomes a KING and can\n"<<
	"move in any direction. State your moves with the letter column first\n"<<
	"then the row number. i.e. Move: A5 B6\n"<<
	"Jumps are made by specifying a move of two diagonal spaces over an opposing piece\n"<<
	"You win the game when you have jumped all of your opponents pieces\n\n"<<endl;
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
	x=a-48;
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
	int moveResult = 0;
	int redPieces = 12;
	int blackPieces = 12;
	bool gameOver = false;
	bool invalid = false;
	bool doublejump = false;
	Grid gridBoard;
	char from[2], to[2];
	int fromPos[2], toPos[2];


	///////////////////////////////////////////////////////////////////
	// Main Entry Point
	////////////////////////////////////////////////////////////////////

	instructions();

	while(!gameOver)
	{
		std::cout << gridBoard << endl;

		if(invalid){
			std::cout << "Invalid move, please try again" <<endl;
		}

		if(doublejump){
			std::cout << "You must double jump from " << fromPos[0] << fromPos[1] << " ";
		}
		else{
			std::cout << "Enter move ";
		}

		if(turn == blackTurn)
			cout<<"Black: ";
		else
			cout<<"Red: ";

		//USER MOVE INPUT
		std::cin >> from >> to;

		if(!doublejump)
		{
			fromPos[0] = convertLetter(from[0]);
			fromPos[1] = convertNumber(from[1]);
		}

		toPos[0] = convertLetter(to[0]);
		toPos[1] = convertNumber(to[1]);

		if(fromPos[0] == -1 || fromPos[1] == -1 || toPos[0] == -1 || fromPos[1] == -1)
			invalid = true;
		else
			invalid = false;

	cout<<endl<<"BEFORE !INVALID, invalid="<<invalid<<endl;
	cout<<"ALSO MOVE FROM " << fromPos[0] << "," << fromPos[1] << " to " << toPos[0] << "," << toPos[1] << endl;

		//MOVE THE PIECES
		if(!invalid)
		{
			moveResult = gridBoard.move(fromPos, toPos);
			doublejump = false;
			switch(turn)
			{
				case blackTurn:
					if(gridBoard.getPosition(fromPos[0],fromPos[1]).color != BLACK ||
					   moveResult == -1)
					{
						invalid = true;
						break;
					}
					if(moveResult ==  1)
						redPieces--;
					turn = redTurn;
					break;

				case redTurn:
					if(gridBoard.getPosition(fromPos[0],fromPos[1]).color != RED ||
					   moveResult == -1)
					{
						invalid = true;
						break;
					}
					if(moveResult == 1) //JUMP
					{
						blackPieces--;
			std::cout << "BLACK PIECES" << blackPieces<<endl;
			std::cout << "RED PIECES"  << redPieces<<endl;
						for(int i=-1; i<2; i+=2)
						{
							if(gridBoard.getPosition(toPos[0],toPos[1]).type == king)
							{
								if(gridBoard.getPosition(toPos[0]+i,toPos[1]+1).color == BLACK &&
								   gridBoard.getPosition(toPos[0]+(i*2), toPos[1]+2).color == NONE)
								{
									doublejump == true;
								}
							}
							if(gridBoard.getPosition(toPos[0]+i,toPos[1]-1).color == BLACK &&
							   gridBoard.getPosition(toPos[0]+(i*2), toPos[1]-2).color == NONE)
							{
								doublejump == true;
							}
						}
					}//End JUMP
					if(!doublejump)
						turn = blackTurn;
					break;
			}//end turn switch
		}//end invalid check
		if(blackPieces == 0 || redPieces == 0)
			gameOver == true;
	}//end while

	if(blackPieces == 0)
		std::cout << "RED WINS!"<<endl;
	if(redPieces == 0)
		std::cout << "BLACK WINS!"<<endl;
	if(blackPieces != 0 && redPieces != 0)
		std::cout << "NOBODY WINS :("<<endl;
	return 0;
}
