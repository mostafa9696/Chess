#include "AllPieces.h"
#include "CheesBoard.h"
#include <iostream>
using namespace std;
vector<Possible_Move> pawn::move()
{
	PiecePosition current_position;
	Possible_Move _possible;
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible;
	current_position = GetPosition();
	string Current_player= GetPlayer();

	if(Current_player=="White")  // Black player -> pawn move
	{
		if(current_position.y!=7)
		{
			ChessPiece piece=*Board[current_position.y+1][current_position.x]; // point to piece after one step
			PiecePosition P;
			P.x=current_position.x;
			P.y=current_position.y+1;
			if(piece.GetName()=="")  // down one step
			{
				if(P.y==7){    // tr2ya el pawn lma ywsel le 2a5er :D
				_possible.position=P;
				All_Possible.push_back(_possible);
				}
				else 
				{
					_possible.position=P;
					
					All_Possible.push_back(_possible);
				}
			}
			if(current_position.y==1 && Board[current_position.y+2][current_position.x]->GetName()=="" && Board[current_position.y+1][current_position.x]->GetName()=="")
			{		 // down 2 step if it empty
				piece=*Board[current_position.y+2][current_position.x];
				P.y=current_position.y+2;
				P.x=current_position.x;
				_possible.position=P;
				
				All_Possible.push_back(_possible);
			}
			if(current_position.x!=0) // move down->left
			{
				piece=*Board[current_position.y+1][current_position.x-1];
				P.x=current_position.x-1;  // left
				P.y=current_position.y+1;  // down
				if(piece.GetName()!="" && piece.GetPlayer()!="White"){	
					_possible.position=P;
					
					All_Possible.push_back(_possible);
				}
			}
			if(current_position.x!=7)     //move down->right
			 {
				piece=*Board[current_position.y+1][current_position.x+1];
				 P.x=current_position.x+1;  // right
				P.y=current_position.y+1;  // down
				if(piece.GetName()!="" && piece.GetPlayer()!="White"){	
					_possible.position=P;
					
					All_Possible.push_back(_possible);
			   }
			}

		}
	}
	else //black player move
	{
		if(current_position.y!=0)
		{
			ChessPiece piece=*Board[current_position.y-1][current_position.x]; // point to piece after one step
			PiecePosition P;
			P.x=current_position.x;
			P.y=current_position.y-1;
			if(piece.GetName()=="")  // up one step
			{
				if(P.y==0){    // tr2ya el pawn lma ywsel le 2a5er :D
				_possible.position=P;
				
				All_Possible.push_back(_possible);
				}
				else 
				{
					_possible.position=P;
					
					All_Possible.push_back(_possible);
				}
			}
			
			if(current_position.y==6 && Board[current_position.y-2][current_position.x]->GetName()==""&& Board[current_position.y-1][current_position.x]->GetName()=="")
			{    // up 2 step if it empty
				piece=*Board[current_position.y-2][current_position.x];
				P.y=current_position.y-2;
				P.x=current_position.x;
				_possible.position=P;
				
				All_Possible.push_back(_possible);
			}
			if(current_position.x!=0) // move up->left
			{
				piece=*Board[current_position.y-1][current_position.x-1];
				P.x=current_position.x-1;  // left
				P.y=current_position.y-1;  // up
				if(piece.GetName()!="" && piece.GetPlayer()=="White"){
				if(P.y==0)  // attack & promote pawn
				{
					_possible.position=P;
					
					All_Possible.push_back(_possible);
				}
				else 
				{
					_possible.position=P;
					
					All_Possible.push_back(_possible);
				}
				}
			}
			if(current_position.x!=7)     //move up->right
			 {
				piece=*Board[current_position.y-1][current_position.x+1];
				 P.x=current_position.x+1;  // right
				P.y=current_position.y-1;  // up
				if(piece.GetPlayer()=="White" && piece.GetName()!="")
				{
				if(P.y==7)  // attack & promote pawn
				{
					_possible.position=P;
					
					All_Possible.push_back(_possible);
				}
				else
				{
					_possible.position=P;
					
					All_Possible.push_back(_possible);
				}
			   }
			}
		}
	}
	return All_Possible;
}
vector<Possible_Move> pawn::protected_move()
{
	PiecePosition current_position , tmp;
	Possible_Move _possible;
	///////////////////////////////////////
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> all_protected;
	current_position = GetPosition();
	string Current_player= GetPlayer();
	if(Current_player=="White")
	{
		if(current_position.y!=7)
		{
			if(current_position.x!=0)
			{
			_possible.position.x=current_position.x-1;
			_possible.position.y=current_position.y+1;
				all_protected.push_back(_possible) ;
			}
			if(current_position.x!=7)
			{
				_possible.position.x=current_position.x+1;
			    _possible.position.y=current_position.y+1;
				all_protected.push_back(_possible) ;
			}
		}
	}
	else 
	{
		if(current_position.y!=0)
		{
			if(current_position.x!=0)
			{
			_possible.position.x=current_position.x-1;
			_possible.position.y=current_position.y-1;
				all_protected.push_back(_possible) ;
			}
			if(current_position.x!=7)
			{
				_possible.position.x=current_position.x+1;
			    _possible.position.y=current_position.y-1;
				all_protected.push_back(_possible) ;
			}
		}
	}
	return all_protected;
}
void pawn::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetPlayer()=="White")
		texture.loadFromFile("PawnW.png");
	else
		texture.loadFromFile("PawnB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * 75,this->GetPosition().y * 75);
	window.draw(sprite);
}
