#include "Piece.h"

Piece::Piece()
{
}

Piece::Piece(PieceColor col, int x, int y)
{
	color = col;
	type  = man;
}

PieceType Piece::getPieceType()
{
	return type;
}

PieceColor Piece::getPieceColor()
{
	return color;
}

void Piece::makeKing()
{
	type = king;
}

void Piece::pieceTaken()
{
	type = none;
	color = NONE;
}
