#include "AllPieces.h"
#include "CheesBoard.h"

vector<Possible_Move> Bishop::protected_move()
{
	PiecePosition current_position,tmp;
	Possible_Move _possible;
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible2;
	current_position = GetPosition();
	string Current_player= GetPlayer();
	tmp=current_position;
	if(Current_player=="White")
	{
		
		if(tmp.y!=7&&tmp.x!=7)	                        //white down right
		{
			while(1)
			{
					tmp.y++,tmp.x++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
					if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==7||tmp.x==7)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;	
			}
		}
		tmp=current_position;
		 if(tmp.y!=0&&tmp.x!=7)	                        //white up right
		{
			while(1)
			{
				tmp.y--,tmp.x++;
				_possible.position=tmp;
				All_Possible2.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==0||tmp.x==7)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;	
			}
		}
		tmp=current_position;
		if(tmp.y!=7&&tmp.x!=0)	                        //white down left
		{
			while(1)
			{
					tmp.x--,tmp.y++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
					if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==7||tmp.x==0)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;		
			}
		}
		tmp=current_position;
		if(tmp.y!=0&&tmp.x!=0)	                        //white up left
		{
			while(1)
			{
				tmp.x--,tmp.y--;
				_possible.position=tmp;
				All_Possible2.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==0||tmp.x==0)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;	
			}
		}
	}
	else       // Black moves 
	{
		tmp=current_position;
		if(tmp.y!=7&&tmp.x!=7)	                        //Black down right
		{
			while(1)
			{
					tmp.y++,tmp.x++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
					if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==7||tmp.x==7)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;		
			}
		}
		tmp=current_position;
		if(tmp.y!=0&&tmp.x!=7)	                        //Black up right
		{
			while(1)
			{
				tmp.y--,tmp.x++;
				_possible.position=tmp;
				All_Possible2.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==0||tmp.x==7)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
		tmp=current_position;
		if(tmp.y!=7&&tmp.x!=0)	                        //Black down left
		{
			while(1)
			{
					tmp.x--,tmp.y++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
					if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==7||tmp.x==0)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;	
			}
		}
		tmp=current_position;
		if(tmp.y!=0&&tmp.x!=0)	                        //Black up left
		{
			while(1)
			{
				tmp.x--,tmp.y--;
				_possible.position=tmp;
				All_Possible2.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.y==0||tmp.x==0)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
	}
	return All_Possible2;
}

vector<Possible_Move> Bishop::move()
{
	PiecePosition current_position , tmp;
	Possible_Move _possible;
	///////////////////////////////////////
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible2;
	current_position = GetPosition();
	string Current_player= GetPlayer();
	tmp=current_position;
	if(Current_player=="White")
	{
		
		if(tmp.y!=7&&tmp.x!=7)	                        //white down right
		{
			while((tmp.y!=7&&tmp.x!=7)&&(Board[tmp.y+1][tmp.x+1]->GetPlayer()==""||Board[tmp.y+1][tmp.x+1]->GetPlayer()=="Black"))
			{
					tmp.y++,tmp.x++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;	
			}
		}
		tmp=current_position;
		 if(tmp.y!=0&&tmp.x!=7)	                        //white up right
		{
			while((tmp.y!=0&&tmp.x!=7)&&(Board[tmp.y-1][tmp.x+1]->GetPlayer()==""||Board[tmp.y-1][tmp.x+1]->GetPlayer()=="Black"))
			{
				tmp.y--,tmp.x++;
				_possible.position=tmp;
				All_Possible2.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
		tmp=current_position;
		if(tmp.y!=7&&tmp.x!=0)	                        //white down left
		{
			while((tmp.y!=7&&tmp.x!=0)&&(Board[tmp.y+1][tmp.x-1]->GetPlayer()==""||Board[tmp.y+1][tmp.x-1]->GetPlayer()=="Black"))
			{
					tmp.x--,tmp.y++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;	
			}
		}
		tmp=current_position;
		if(tmp.y!=0&&tmp.x!=0)	                        //white up left
		{
			while((tmp.y!=0&&tmp.x!=0)&&(Board[tmp.y-1][tmp.x-1]->GetPlayer()==""||Board[tmp.y-1][tmp.x-1]->GetPlayer()=="Black"))
			{
				tmp.x--,tmp.y--;
				_possible.position=tmp;
				All_Possible2.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
	}
	else       // Black moves 
	{
		tmp=current_position;
		if(tmp.y!=7&&tmp.x!=7)	                        //Black down right
		{
			while(tmp.y!=7&&tmp.x!=7&&(Board[tmp.y+1][tmp.x+1]->GetPlayer()==""||Board[tmp.y+1][tmp.x+1]->GetPlayer()=="White"))
			{
					tmp.y++,tmp.x++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;	
			}
		}
		tmp=current_position;
		if(tmp.y!=0&&tmp.x!=7)	                        //Black up right
		{
			while(tmp.y!=0&&tmp.x!=7&&(Board[tmp.y-1][tmp.x+1]->GetPlayer()==""||Board[tmp.y-1][tmp.x+1]->GetPlayer()=="White"))
			{
				tmp.y--,tmp.x++;
				_possible.position=tmp;
				All_Possible2.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
		tmp=current_position;
		if(tmp.y!=7&&tmp.x!=0)	                        //Black down left
		{
			while(tmp.y!=7&&tmp.x!=0&&(Board[tmp.y+1][tmp.x-1]->GetPlayer()==""||Board[tmp.y+1][tmp.x-1]->GetPlayer()=="White"))
			{
					tmp.x--,tmp.y++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;	
			}
		}
		tmp=current_position;
		if(tmp.y!=0&&tmp.x!=0)	                        //Black up left
		{
			while(tmp.y!=0&&tmp.x!=0&&(Board[tmp.y-1][tmp.x-1]->GetPlayer()==""||Board[tmp.y-1][tmp.x-1]->GetPlayer()=="White"))
			{
				tmp.x--,tmp.y--;
				_possible.position=tmp;
				All_Possible2.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
	}


	return All_Possible2;
}
void Bishop::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetPlayer()=="White")
		texture.loadFromFile("BishopW.png");
	else
		texture.loadFromFile("BishopB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * 75,this->GetPosition().y * 75);
	window.draw(sprite);
}