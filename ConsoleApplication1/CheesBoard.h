                             //________________________________________________________________//
                                // every cell in board is 75 in height and 75 in width
                             //________________________________________________________________//
#ifndef CHEESBOARD_H
#define CHEESBOARD_H
#include "ChessPiece.h"

class ChessBoard
{
	//ChessPiece Piece;
	static vector< vector<ChessPiece*> > Board ;  // 2D board that has chess pieces
public:
	ChessBoard();
	~ChessBoard();
	static vector< vector<ChessPiece*> > GetBoard();
	static void SetBoard(vector< vector<ChessPiece*> >B);
	void set_player(string name);
};
#endif
