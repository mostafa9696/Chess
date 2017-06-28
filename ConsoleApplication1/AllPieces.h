
#include "ChessPiece.h"
class pawn : public ChessPiece
{
public:
	pawn (){}
	~pawn (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
	vector<Possible_Move> protected_move();
};
class knight : public ChessPiece
{
public:
	knight (){}
	~knight (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
	vector<Possible_Move> protected_move();
};
class Rock : public ChessPiece
{
public:
	Rock (){}
	~Rock (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
	vector<Possible_Move> protected_move();
};
class Bishop : public ChessPiece
{
public:
	Bishop (){}
	~Bishop (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
	vector<Possible_Move> protected_move();
};
class King : public ChessPiece
{
public:

	King (){}
	~King (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
	vector<Possible_Move> protected_move();
	bool Tbyeta_Black(PiecePosition current,vector< vector<ChessPiece*> > Board , string pos);
	bool Tbyeta_White(PiecePosition current,vector< vector<ChessPiece*> > Board , string pos);
};
class Queen : public ChessPiece
{
public:
	Queen (){}
	~Queen (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
	vector<Possible_Move> protected_move();
};
