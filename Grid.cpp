#include "Grid.h"
#include <cmath>


using namespace std;

ostream& operator<<(ostream& output, Grid& input) // << operator
{
	output << endl;
	output<<"  A B C D E F G H" << endl;
	for(int j = 0; j < 8; j++)
	{
		output << j << " ";
		for(int i = 0; i<8; i++)
		{
			switch (input.board[i][j].color)
			{
				case BLACK:
					if(input.board[i][j].type == man)
						output << "x ";
					else if(input.board[i][j].type == king)
						output << "* ";
					break;
				case RED:
					if(input.board[i][j].type == man)
						output << "o ";
					else if(input.board[i][j].type == king)
						output << "0 ";
					break;
				case none:
					if((i+j)%2==0)
						output << ". ";
					else
						output << "  ";
					break;
			}
			
		}
		output << endl;
	}

	output << endl;
	return output;
} // end operator<<

Grid::Grid()
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		{
			//black
			if(j>=5&&(i%2+j%2==1))
			{
				board[i][j].color = BLACK;
				board[i][j].type = man;
			}
			//red
			else if(j<=2&&(i%2+j%2==1))
			{
				board[i][j].color = RED;
				board[i][j].type = man;
			}
			else
			{
				board[i][j].color = NONE;
				board[i][j].type = none;
			}
		}
}

Grid::Grid(Grid& grid)
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		{
			board[i][j].color = grid.board[i][j].color;
			board[i][j].type = grid.board[i][j].type;
		}
}

Grid& Grid::operator=(const Grid& orig)
{
        for(int i = 0; i < 8; i++)
                for(int j = 0; j < 8; j++)
                {
                        board[i][j].color = orig.board[i][j].color;
                        board[i][j].type = orig.board[i][j].type;
                }
	
}

Square Grid::getPosition(int x, int y)
{
	Square spot = board[x][y];
	return spot;
}

void Grid::move(int from[2], int to[2])
{
	int x,y,X,Y;
	int moves;
	Square tempSquare;
	x=from[0];
	y=from[1];
	X=to[0];
	Y=to[1];

	tempSquare = getPosition(x,y);
	
	if(abs(X-x)==abs(Y-y))
		if(getPosition(X,Y).color==NONE&&getPosition(X,Y).type==none)
			if(tempSquare.type!=king)
			{
				if(tempSquare.color==RED)
				{
				}
				else if(tempSquare.color==RED)
				{
				}
			}
				
}

void Grid::makeKing(int x, int y)
{
	board[x][y].type = king;
}

void Grid::pieceTaken(int x, int y)
{
	board[x][y].color = NONE;
	board[x][y].type = none;
}