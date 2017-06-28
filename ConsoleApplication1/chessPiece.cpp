
#include "chessPiece.h"
ChessPiece::ChessPiece()
{
	player=name="";
	position.x=position.y=-1;
}
string ChessPiece::GetPlayer()
{
	return player;
}
void ChessPiece::SetPlayer(string s)
{
	player = s;
}
string ChessPiece::GetName()
{
	return name;
}
void ChessPiece::SetName(string N)
{
	name=N;
}
PiecePosition ChessPiece::GetPosition()
{
	return position;
}
void ChessPiece::SetPosition(PiecePosition P)
{
	position=P;
}
vector<Possible_Move> ChessPiece::move()
{
	vector<Possible_Move> All_Possible_Positions;
	return All_Possible_Positions;
}
vector<Possible_Move> ChessPiece::protected_move()
{
	vector<Possible_Move> All_protect;
	return All_protect;
}