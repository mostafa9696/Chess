#include "AllPieces.h"
#include "CheesBoard.h"

bool King::Tbyeta_Black(PiecePosition current,vector< vector<ChessPiece*> > Board , string pos)  // black player
{
	if(pos=="Left"){
	if(current.x!=0&&current.x==3&&current.y==7&&Board[7][0]->GetName()=="Rock"&&Board[7][3]->GetName()=="King")
	{
		current.x--;
		while(current.x!=0)
	{
		if(Board[current.y][current.x]->GetPlayer()!="") 
			return false;
		current.x--;
	}
		return true;
	}
	return false;
	}
	else 
	{
		if(current.x!=7&&current.x==3&&current.y==7&&Board[7][7]->GetName()=="Rock"&&Board[7][3]->GetName()=="King")
	{
		current.x++;
		while(current.x!=7)
	{
		if(Board[current.y][current.x]->GetPlayer()!="") 
			return false;
		current.x++;
	}
		return true;
	}
	return false;

	}
}
bool King::Tbyeta_White(PiecePosition current,vector< vector<ChessPiece*> > Board , string pos)  // black player
{
	if(pos=="Left"){
	if(current.x!=0&&current.x==3&&current.y==0&&Board[0][0]->GetName()=="Rock"&&Board[0][3]->GetName()=="King")
	{
		current.x--;
		while(current.x!=0)
	{
		if(Board[current.y][current.x]->GetPlayer()!="") 
			return false;
		current.x--;
	}
		return true;
	}
	return false;
	}
	else 
	{
		if(current.x!=7&&current.x==3&&current.y==0&&Board[0][7]->GetName()=="Rock"&&Board[0][3]->GetName()=="King")
	{
		current.x++;
		while(current.x!=7)
	{
		if(Board[current.y][current.x]->GetPlayer()!="") 
			return false;
		current.x++;
	}
		return true;
	}
	return false;

	}
}
////////////////////////////
vector<Possible_Move> King::move()
{
	PiecePosition current_position , tmp;
	Possible_Move _possible;
	///////////////////////////////////////
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible;
	current_position = GetPosition();
	string Current_player= GetPlayer();
	/////////////////// White moves
	if(Current_player =="White")
	{
		tmp = current_position; 
		if(Tbyeta_White(tmp,Board,"Left")) // Tr2ya el white king -> left rock
		{
			tmp.x=1;
			tmp.y=0;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position; 
		if(Tbyeta_White(tmp,Board,"Right")) // Tr2ya el white king -> right rock
		{
			tmp.x=5;
			tmp.y=0;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position; 
		if(tmp.y!= 7)
		if(  Board[tmp.y+1][tmp.x]->GetPlayer()!= "White" )   /////////// down
		{
			tmp.y +=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.y!=0)
		if( Board[tmp.y-1][tmp.x]->GetPlayer()!= "White"  )  ////////////// up
		{
			tmp.y -=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;  
		if(tmp.x!=7)
		if(Board[tmp.y][tmp.x+1]->GetPlayer()!= "White" )  ////////////// rigth
		{
			tmp.x +=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x !=0)
		if(Board[tmp.y][tmp.x-1]->GetPlayer()!= "White"  ) //////////// left
		{
			tmp.x -=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x!=7 && tmp.y!=7)
		if(Board[tmp.y+1][tmp.x+1]->GetPlayer()!= "White"  )  ///////////// down + right 
		{
			tmp.y +=1 ;
			tmp.x +=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x!=0 && tmp.y!=7)
		if(Board[tmp.y+1][tmp.x-1]->GetPlayer()!= "White"  )  /////////// down + left
		{
			tmp.y +=1 ;
			tmp.x -=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x!=0 && tmp.y!=0)
		if(Board[tmp.y-1][tmp.x-1]->GetPlayer()!= "White"  )   //////////// up + left
		{
			tmp.y -=1 ;
			tmp.x -=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x!=7 && tmp.y!=0)
		if(Board[tmp.y-1][tmp.x+1]->GetPlayer()!= "White" )   ///////////// up + right
		{
			tmp.y -=1 ;
			tmp.x +=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
	}
	else  //////////// black moves
	{
		tmp = current_position; 
		if(Tbyeta_Black(tmp,Board,"Left")) 
		{
			tmp.x=1;
			tmp.y=7;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position; 
		if(Tbyeta_Black(tmp,Board,"Right")) 
		{
			tmp.x=5;
			tmp.y=7;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position; 
		if(tmp.y!= 7)
		if(  Board[tmp.y+1][tmp.x]->GetPlayer()!= "Black" )   /////////// down
		{
			tmp.y +=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.y!=0)
		if( Board[tmp.y-1][tmp.x]->GetPlayer()!= "Black"  )  ////////////// up
		{
			tmp.y -=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;  
		if(tmp.x!=7)
		if(Board[tmp.y][tmp.x+1]->GetPlayer()!= "Black" )  ////////////// rigth
		{
			tmp.x +=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x !=0)
		if(Board[tmp.y][tmp.x-1]->GetPlayer()!= "Black"  ) //////////// left
		{
			tmp.x -=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x!=7 && tmp.y!=7)
		if(Board[tmp.y+1][tmp.x+1]->GetPlayer()!= "Black"  )  ///////////// down + right 
		{
			tmp.y +=1 ;
			tmp.x +=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x!=0 && tmp.y!=7)
		if(Board[tmp.y+1][tmp.x-1]->GetPlayer()!= "Black"  )  /////////// down + left
		{
			tmp.y +=1 ;
			tmp.x -=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x!=0 && tmp.y!=0)
		if(Board[tmp.y-1][tmp.x-1]->GetPlayer()!= "Black"  )   //////////// up + left
		{
			tmp.y -=1 ;
			tmp.x -=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
		tmp = current_position;
		if(tmp.x!=7 && tmp.y!=0)
		if(Board[tmp.y-1][tmp.x+1]->GetPlayer()!= "Black" )   ///////////// up + right
		{
			tmp.y -=1 ;
			tmp.x +=1 ;
			_possible.position = tmp ; 
			All_Possible.push_back(_possible);
		}
	} 
	return All_Possible;
}
vector<Possible_Move> King::protected_move()
{
	PiecePosition current_position , tmp;
	Possible_Move _possible;
	vector<Possible_Move> all_moves ;
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	current_position = GetPosition();
	string Current_player= GetPlayer();

			/////////////////// White moves
	if(Current_player =="White")
	{
		tmp = current_position; 
		if(tmp.y!= 7)
		{
			tmp.y +=1 ;
			_possible.position = tmp ; 
			all_moves.push_back(_possible) ;
		}

	
		tmp = current_position;
		if(tmp.y!=0)
		{
		tmp.y -=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;	
		}

		tmp = current_position;  
		if(tmp.x!=7)
		{	
		tmp.x +=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.x !=0)
		{
		tmp.x -=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.x!=7 && tmp.y!=7)
		{	
		tmp.y +=1 ;
		tmp.x +=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;

		if(tmp.x!=0 && tmp.y!=7)
		{
		tmp.y +=1 ;
		tmp.x -=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.x!=0 && tmp.y!=0)
		{
		tmp.y -=1 ;
		tmp.x -=1 ;
		_possible.position = tmp ;
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.x!=7 && tmp.y!=0)
		{
		tmp.y -=1 ;
		tmp.x +=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}
	}
	else  //////////// black moves
	{

		tmp = current_position; 
		if(tmp.y!= 7){
	
		tmp.y +=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.y!=0){
	
		tmp.y -=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;  
		if(tmp.x!=7){
	
		tmp.x +=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}
		
		tmp = current_position;
		if(tmp.x !=0){
		tmp.x -=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.x!=7 && tmp.y!=7){	
		tmp.y +=1 ;
		tmp.x +=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.x!=0 && tmp.y!=7){

		tmp.y +=1 ;
		tmp.x -=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.x!=0 && tmp.y!=0){
	
		tmp.y -=1 ;
		tmp.x -=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}

		tmp = current_position;
		if(tmp.x!=7 && tmp.y!=0){
	
		tmp.y -=1 ;
		tmp.x +=1 ;
		_possible.position = tmp ; 
		all_moves.push_back(_possible) ;
		}
		}
		return all_moves ;
}
void King::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetPlayer()=="White")
		texture.loadFromFile("KingW.png");
	else
		texture.loadFromFile("KingB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * 75,this->GetPosition().y * 75);
	window.draw(sprite);
}