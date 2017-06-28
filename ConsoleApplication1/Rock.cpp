#include "AllPieces.h"
#include "CheesBoard.h"

vector<Possible_Move> Rock::move()
{
	PiecePosition current_position,tmp;
	Possible_Move _possible;
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> all_protected;
	current_position = GetPosition();
	tmp=current_position;
	string Current_player= GetPlayer();
	if(Current_player=="White")
	{
		if(tmp.y!=7)	                        //down
		{
			while(tmp.y!=7&&(Board[tmp.y+1][tmp.x]->GetPlayer()==""||Board[tmp.y+1][tmp.x]->GetPlayer()=="Black"))
			{
					tmp.y++;
					_possible.position=tmp;
					all_protected.push_back(_possible);
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;	
			}
		}
		tmp=current_position;
		if(tmp.y!=0)	                        //up
		{
			while(tmp.y!=0&&(Board[tmp.y-1][tmp.x]->GetPlayer()==""||Board[tmp.y-1][tmp.x]->GetPlayer()=="Black"))
			{
				tmp.y--;
				_possible.position=tmp;
				all_protected.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
		tmp=current_position;
		if(tmp.x!=7)	                        //rightt
		{
			while(tmp.x!=7&&(Board[tmp.y][tmp.x+1]->GetPlayer()==""||Board[tmp.y][tmp.x+1]->GetPlayer()=="Black"))
			{
					tmp.x++;
					_possible.position=tmp;
					all_protected.push_back(_possible);
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;	
			}
		}
		tmp=current_position;
		if(tmp.x!=0)	                        //left
		{
			while(tmp.x!=0&&(Board[tmp.y][tmp.x-1]->GetPlayer()==""||Board[tmp.y][tmp.x-1]->GetPlayer()=="Black"))
			{
				tmp.x--;
				_possible.position=tmp;
				all_protected.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
	}
	else 
	{
		if(tmp.y!=7)	                        //up
		{
			while(tmp.y!=7&&(Board[tmp.y+1][tmp.x]->GetPlayer()==""||Board[tmp.y+1][tmp.x]->GetPlayer()=="White"))
			{
					tmp.y++;
					_possible.position=tmp;
					all_protected.push_back(_possible);
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;	
			}
		}
		tmp=current_position;
		if(tmp.y!=0)	                        //down
		{
			while(tmp.y!=0&&(Board[tmp.y-1][tmp.x]->GetPlayer()==""||Board[tmp.y-1][tmp.x]->GetPlayer()=="White"))
			{
				tmp.y--;
				_possible.position=tmp;
				all_protected.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
		tmp=current_position;
		if(tmp.x!=7)	                        //rightt
		{
			while(tmp.x!=7&&(Board[tmp.y][tmp.x+1]->GetPlayer()==""||Board[tmp.y][tmp.x+1]->GetPlayer()=="White"))
			{
					tmp.x++;
					_possible.position=tmp;
					all_protected.push_back(_possible);
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;	
			}
		}
		tmp=current_position;
		if(tmp.x!=0)	                        //left
		{
			while(tmp.x!=0&&(Board[tmp.y][tmp.x-1]->GetPlayer()==""||Board[tmp.y][tmp.x-1]->GetPlayer()=="White"))
			{
				tmp.x--;
				_possible.position=tmp;
				all_protected.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
	}
	return all_protected;
}

vector<Possible_Move> Rock::protected_move()
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
		tmp=current_position;
		if(tmp.y!=7)	                        //down
		{
			while(true)
			{
					tmp.y++;
					_possible.position=tmp;
					all_protected.push_back(_possible);
					if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==7)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
		tmp=current_position;
		if(tmp.y!=0)	                        //up
		{
			while(true)
			{
				tmp.y--;
				_possible.position=tmp;
				all_protected.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==0)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
		tmp=current_position;
		if(tmp.x!=7)	                        //rightt
		{
			while(true)
			{
					tmp.x++;
					_possible.position=tmp;
					all_protected.push_back(_possible);
					if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.x==7)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;	
			}
		}
		tmp=current_position;
		if(tmp.x!=0)	                        //left
		{
			while(true)
			{
				tmp.x--;
				_possible.position=tmp;
				all_protected.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.x==0)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
	}
	else 
	{
		tmp=current_position;
		if(tmp.y!=7)	                        //up
		{
			while(true)
			{
					tmp.y++;
					_possible.position=tmp;
					all_protected.push_back(_possible);
					if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==7) break;	
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
		tmp=current_position;
		if(tmp.y!=0)	                        //down
		{
			while(1)
			{
				tmp.y--;
				_possible.position=tmp;
				all_protected.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==0) break;	
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
		tmp=current_position;
		if(tmp.x!=7)	                        //rightt
		{
			while(1)
			{
					tmp.x++;
					_possible.position=tmp;
					all_protected.push_back(_possible);
					if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.x==7) break;	
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;	
			}
		}
		tmp=current_position;
		if(tmp.x!=0)	                        //left
		{
			while(1)
			{
				tmp.x--;
				_possible.position=tmp;
				all_protected.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.x==0) break;	
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
	}
	return all_protected;
}
void Rock::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetPlayer()=="White")
		texture.loadFromFile("RockW.png");
	else
		texture.loadFromFile("RockB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * 75,this->GetPosition().y * 75);
	window.draw(sprite);
}