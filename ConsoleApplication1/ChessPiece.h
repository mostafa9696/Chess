#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<string>
#include<vector>
using namespace std;
using namespace sf;
struct PiecePosition
{
	int x,y;
};
struct Possible_Move
{
	PiecePosition position;
};
class ChessPiece
{
	string player;  // black or white
	string name;   // piece name
	PiecePosition position;   // current position of piece
public:
	ChessPiece();
	~ChessPiece(){}
	string GetPlayer();
	void SetPlayer(string PL);
	string GetName();
	void SetName(string input);
	PiecePosition GetPosition();
	void SetPosition(PiecePosition input);
	virtual void Draw(RenderWindow &window){}  // draw piece 3la 7sb el board btshawer 3la eh :D
	virtual vector<Possible_Move> move();     // move piece //   //
	virtual vector<Possible_Move> protected_move();
};
#endif