#include "AllPieces.h"
#include "CheesBoard.h"
#include <iostream>
using namespace std ;
vector<Possible_Move> knight::move()
{
	PiecePosition current_position,tmp;
	Possible_Move _possible;
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible_moves;
	current_position = GetPosition();
	tmp=current_position;
	string Current_player= GetPlayer();
	
	if(Current_player == "White")
	{
		/////////////////////// down moves
		if(tmp.y<6 && tmp.x!=7 )        // white player down+2 right   y+=2 x+=1
		{
			if( Board[tmp.y+2][tmp.x+1]->GetPlayer()=="Black" || Board[tmp.y+2][tmp.x+1]->GetName()=="") 
			{	
				tmp.y +=2 ;
				tmp.x +=1 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		
		tmp = current_position ;
		
		if(tmp.y<6 && tmp.x!=0  )        // white player down+2 left    y+=2  x-=1 
		{
			if( Board[tmp.y+2][tmp.x-1]->GetPlayer()=="Black" || Board[tmp.y+2][tmp.x-1]->GetName()=="") 
			{	
				tmp.y +=2 ;
				tmp.x -=1 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		
		tmp = current_position ;
		if(tmp.y<=6 && tmp.x<6  )        // white player down+1 right   y+=1  x+=2
		{
			if( Board[tmp.y+1][tmp.x+2]->GetPlayer()=="Black" || Board[tmp.y+1][tmp.x+2]->GetName()=="") 
			{	
				tmp.y +=1 ;
				tmp.x +=2 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		tmp = current_position ;
		if(tmp.y<=6 && tmp.x>1  )        // white player down +1 left    y+=1 , x-=2 
		{
			if( Board[tmp.y+1][tmp.x-2]->GetPlayer()=="Black" || Board[tmp.y+1][tmp.x-2]->GetName()=="") 
			{   
				
				tmp.y +=1 ;
				tmp.x -=2 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
			
		////////////////////////// up  moves
		tmp = current_position ;
		if(tmp.y>1 && tmp.x!=7 )        // white player up +2 right  y-=2  x+1
		{
			if( Board[tmp.y-2][tmp.x+1]->GetPlayer()=="Black" || Board[tmp.y-2][tmp.x+1]->GetName()=="") {
				tmp.y -=2 ;
				tmp.x +=1 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
			
		tmp = current_position ;
		if(tmp.y>1 && tmp.x!=0  )        // white player down+2 left  y-+2  x-1
		{
			if( Board[tmp.y-2][tmp.x-1]->GetPlayer()=="Black" || Board[tmp.y-2][tmp.x-1]->GetName()=="") {
				tmp.y -=2 ;
				tmp.x -=1 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		
		tmp = current_position ;
		if(tmp.y<=7 && tmp.x<6  && tmp.y!=0)        // white player up+1 right  y-=1 x+=2
		{
			if( Board[tmp.y-1][tmp.x+2]->GetPlayer()=="Black" || Board[tmp.y-1][tmp.x+2]->GetName()=="") { 
				tmp.y -=1 ;
				tmp.x +=2 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		
		tmp = current_position ;
		if(tmp.y>0 && tmp.x>1  )        // white player down+1 left   y-=1  x-=2
 		{
			if( Board[tmp.y-1][tmp.x-2]->GetPlayer()=="Black" || Board[tmp.y-1][tmp.x-2]->GetName()=="")  {
				tmp.y -=1 ;
				tmp.x -=2 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
	}

	else     /// black moves
	{
		/////////////////////// up moves
		if(tmp.y>1 && tmp.x!=7 )        // black player up+2 right   y+=2  x+=1
		{
			if( Board[tmp.y-2][tmp.x+1]->GetPlayer()=="White" || Board[tmp.y-2][tmp.x+1]->GetName()=="") 
			{	
				tmp.y -=2 ;
				tmp.x +=1 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		
		tmp = current_position ;
		if(tmp.y>1 && tmp.x!=0  )        // black player up+2 left    y+=2  x-=1 
		{
			if( Board[tmp.y-2][tmp.x-1]->GetPlayer()=="White" || Board[tmp.y-2][tmp.x-1]->GetName()=="") 
			{	
				tmp.y -=2 ;
				tmp.x -=1 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}

		tmp = current_position ;
		if(tmp.y>=1 && tmp.x<6  )        // black player up+1 right   y+=1  x+=2
		{
			if( Board[tmp.y-1][tmp.x+2]->GetPlayer()=="White" || Board[tmp.y-1][tmp.x+2]->GetName()=="") 
			{	
				tmp.y -=1 ;
				tmp.x +=2 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		
		tmp = current_position ;
		if(tmp.y>=1 && tmp.x>1  )        // black player up +1 left    y+=1 , x-=2 
		{
			if( Board[tmp.y-1][tmp.x-2]->GetPlayer()=="White" || Board[tmp.y-1][tmp.x-2]->GetName()=="") 
			{   
				tmp.y -=1 ;
				tmp.x -=2 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
	
		}
		////////////////////////// down  moves
		tmp = current_position ;
		if(tmp.y<6 && tmp.x!=7 )        // black player down +2 right  y+=2  x+1
		{
			if( Board[tmp.y+2][tmp.x+1]->GetPlayer()=="White" || Board[tmp.y+2][tmp.x+1]->GetName()=="") {
				tmp.y +=2 ;
				tmp.x +=1 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
			
		tmp = current_position ;
		if(tmp.y<=5 && tmp.x!=0  )        // black player down+2 left  y+2  x-1
		{
			if( Board[tmp.y+2][tmp.x-1]->GetPlayer()=="White" || Board[tmp.y+2][tmp.x-1]->GetName()=="") {
				tmp.y +=2 ;
				tmp.x -=1 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		
		tmp = current_position ;
		if(tmp.y<7 && tmp.x<6 )        // black player down+1 right  y+=1 x+=2
		{
			if( Board[tmp.y+1][tmp.x+2]->GetPlayer()=="White" || Board[tmp.y+1][tmp.x+2]->GetName()=="") {
				tmp.y +=1 ;
				tmp.x +=2 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
		
		tmp = current_position ;
		if(tmp.y<7 && tmp.x>1  )        // black player down+1 left   y+=1  x-=2
 		{
			if( Board[tmp.y+1][tmp.x-2]->GetPlayer()=="White" || Board[tmp.y+1][tmp.x-2]->GetName()=="") {
				tmp.y +=1 ;
				tmp.x -=2 ;
				_possible.position = tmp ; 
				All_Possible_moves.push_back(_possible);
			}
		}
	}
	return All_Possible_moves;
}
vector<Possible_Move> knight::protected_move()
{
	vector<Possible_Move> All_protected;
	PiecePosition current_position,tmp;
	Possible_Move _possible;
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible_moves;
	current_position = GetPosition();
	tmp=current_position;
	string Current_player= GetPlayer();
	
	if(Current_player == "White")
	{
		/////////////////////// down moves
		if(tmp.y<6 && tmp.x!=7 )        // white player down+2 right   y+=2 x+=1
		{
				tmp.y +=2 ;
				tmp.x +=1 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		
		tmp = current_position ;
		
		if(tmp.y<6 && tmp.x!=0  )        // white player down+2 left    y+=2  x-=1 
		{
	
				tmp.y +=2 ;
				tmp.x -=1 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		
		tmp = current_position ;
		if(tmp.y<=6 && tmp.x<6  )        // white player down+1 right   y+=1  x+=2
		{
				tmp.y +=1 ;
				tmp.x +=2 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		tmp = current_position ;
		if(tmp.y<=6 && tmp.x>1  )        // white player down +1 left    y+=1 , x-=2 
		{
				tmp.y +=1 ;
				tmp.x -=2 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
			
		////////////////////////// up  moves
		tmp = current_position ;
		if(tmp.y>1 && tmp.x!=7 )        // white player up +2 right  y-=2  x+1
		{
				tmp.y -=2 ;
				tmp.x +=1 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
			
		tmp = current_position ;
		if(tmp.y>1 && tmp.x!=0  )        // white player down+2 left  y-+2  x-1
		{
				tmp.y -=2 ;
				tmp.x -=1 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		
		tmp = current_position ;
		if(tmp.y<=7 && tmp.x<6  && tmp.y!=0)        // white player up+1 right  y-=1 x+=2
		{
				tmp.y -=1 ;
				tmp.x +=2 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		
		tmp = current_position ;
		if(tmp.y>0 && tmp.x>1  )        // white player down+1 left   y-=1  x-=2
 		{
				tmp.y -=1 ;
				tmp.x -=2 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
	}

	else     /// black moves
	{
		/////////////////////// up moves
		if(tmp.y>1 && tmp.x!=7 )        // black player up+2 right   y+=2  x+=1
		{
			 
				tmp.y -=2 ;
				tmp.x +=1 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		
		tmp = current_position ;
		if(tmp.y>1 && tmp.x!=0  )        // black player up+2 left    y+=2  x-=1 
		{
				tmp.y -=2 ;
				tmp.x -=1 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}

		tmp = current_position ;
		if(tmp.y>=1 && tmp.x<6  )        // black player up+1 right   y+=1  x+=2
		{
				tmp.y -=1 ;
				tmp.x +=2 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		
		tmp = current_position ;
		if(tmp.y>=1 && tmp.x>1  )        // black player up +1 left    y+=1 , x-=2 
		{
				tmp.y -=1 ;
				tmp.x -=2 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		////////////////////////// down  moves
		tmp = current_position ;
		if(tmp.y<6 && tmp.x!=7 )        // black player down +2 right  y+=2  x+1
		{
				tmp.y +=2 ;
				tmp.x +=1 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
			
		tmp = current_position ;
		if(tmp.y<=5 && tmp.x!=0  )        // black player down+2 left  y+2  x-1
		{
		
				tmp.y +=2 ;
				tmp.x -=1 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		
		tmp = current_position ;
		if(tmp.y<7 && tmp.x<6 )        // black player down+1 right  y+=1 x+=2
		{
				tmp.y +=1 ;
				tmp.x +=2 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
		
		tmp = current_position ;
		if(tmp.y<7 && tmp.x>1  )        // black player down+1 left   y+=1  x-=2
 		{
				tmp.y +=1 ;
				tmp.x -=2 ;
				_possible.position = tmp ; 
				All_protected.push_back(_possible);
		}
	}
	return All_protected;
}
void knight::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetPlayer()=="White")
		texture.loadFromFile("KnightW.png");
	else
		texture.loadFromFile("KnightB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * 75,this->GetPosition().y * 75);
	window.draw(sprite);
}