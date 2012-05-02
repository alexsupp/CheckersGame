#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <stdlib.h>  

using namespace std;

enum PieceColor{NONE, BLACK, RED};
enum PieceType{none, man, king};

struct Square 
{
	PieceColor color;
	PieceType type;
	int posX, posY;
};
	

class Grid{
	friend ostream& operator<<(ostream& out, Grid& m);

public:
	Grid();
	Grid(Grid& grid);

	Square getPosition(int x, int y);
	int move(int from[2], int to[2]);
	void makeKing(int x, int y);
	void pieceTaken(int x, int y);
	void pieceAdded(PieceColor col, PieceType typ, int x, int y);
	
        Grid& operator=(const Grid& orig); 
private:
	Square board[8][8];

};

#endif
