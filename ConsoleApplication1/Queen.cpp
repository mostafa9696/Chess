#include "AllPieces.h"
#include "CheesBoard.h"

vector<Possible_Move> Queen::move()
{
	PiecePosition current_position,tmp;
	Possible_Move _possible;
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible2;
	current_position = GetPosition();
	tmp=current_position;
	string Current_player= GetPlayer();
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
		////////////////////////////////////////////////////////////////////
		tmp=current_position;
		if(tmp.y!=7)	                        //down
		{
			while(tmp.y!=7&&(Board[tmp.y+1][tmp.x]->GetPlayer()==""||Board[tmp.y+1][tmp.x]->GetPlayer()=="Black"))
			{
					tmp.y++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
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
				All_Possible2.push_back(_possible);
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
					All_Possible2.push_back(_possible);
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
				All_Possible2.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
		

	}
	else // black moves :D
	{
		if(tmp.y!=7)	                        //up
		{
			while(tmp.y!=7&&(Board[tmp.y+1][tmp.x]->GetPlayer()==""||Board[tmp.y+1][tmp.x]->GetPlayer()=="White"))
			{
					tmp.y++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
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
				All_Possible2.push_back(_possible);
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
					All_Possible2.push_back(_possible);
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
				All_Possible2.push_back(_possible);
				if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
		////////////////////////////////////////////////////////////////
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

vector<Possible_Move> Queen::protected_move()
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
		////////////////////////////////////////////////////////////////////
		tmp=current_position;
		if(tmp.y!=7)	                        //down
		{
			while(true)
			{
					tmp.y++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
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
				All_Possible2.push_back(_possible);
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
					All_Possible2.push_back(_possible);
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
				All_Possible2.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="Black"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.x==0)  break; 
					if(Board[tmp.y][tmp.x]->GetPlayer()=="White") break;
			}
		}
		

	}
	else // black moves :D
	{tmp=current_position;
		if(tmp.y!=7)	                        //up
		{
			while(true)
			{
					tmp.y++;
					_possible.position=tmp;
					All_Possible2.push_back(_possible);
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
				All_Possible2.push_back(_possible);
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
					All_Possible2.push_back(_possible);
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
				All_Possible2.push_back(_possible);
				if((Board[tmp.y][tmp.x]->GetPlayer()=="White"&&Board[tmp.y][tmp.x]->GetName()!="King")||tmp.x==0) break;	
					if(Board[tmp.y][tmp.x]->GetPlayer()=="Black") break;
			}
		}
		////////////////////////////////////////////////////////////////
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
void Queen::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetPlayer()=="White")
		texture.loadFromFile("QueenW.png");
	else
		texture.loadFromFile("QueenB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * 75,this->GetPosition().y * 75);
	window.draw(sprite);
}