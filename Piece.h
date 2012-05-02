#ifndef PIECE_H
#define PIECE_H

enum PieceColor {NONE, BLACK, RED};
enum PieceType {none, man, king};

class Piece
{
	public:
		PieceColor color;
		PieceType type;

		Piece();
		Piece(PieceColor col, int x, int y);

		PieceType getPieceType();
		PieceColor getPieceColor();

		void makeKing();
		void pieceTaken();
};

#endif
