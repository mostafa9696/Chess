#include<string>
#include "CheesBoard.h"
#include "AllPieces.h"
vector<vector<ChessPiece* > > ChessBoard::Board = vector<vector<ChessPiece*> > ();  // crate 2D board 
ChessBoard::ChessBoard()
{
	Board.clear();
	Board.resize(8);
	for(int i=0 ; i<8 ; i++)   // nhgz piece le kol cell fe board 
	{
		for(int j=0 ; j<8 ; j++)
		{
			ChessPiece* p =new ChessPiece();     // create new chesspiece to make cell of board point to it
		    PiecePosition position;
			position.x=j;position.y=i;
			p->SetPosition(position);
			Board[i].push_back(p);
		}
	}
	set_player("Black");  // n7t pieces bta3t el white :D
    set_player("White");
}
/*ChessBoard::~ChessBoard()
{

	delete []Board;

}*/
void ChessBoard::set_player(string name)
{
	PiecePosition position;
	string InitBoard[2][8]={
		{"Rock","Knight","Bishop","King","Queen","Bishop","Knight","Rock"}  ,  {"Pawn","Pawn",  "Pawn",  "Pawn", "Pawn","Pawn",  "Pawn",  "Pawn"}};
	
	for(int y=0 ; y<2 ; y++)   // put every piece in board
	{
		for(int x=0 ; x<8 ; x++)
		{
			
			position.x=x;    
			if(name=="White")
				position.y=y;   // White player set at top of board
			else
				position.y=7-y;  // black player set at bottom of board

				///////////////////////////////
			 if(InitBoard[y][x]=="Pawn")   // lw el string dlw2ty = pawn hn5ly el board btshawer 3la pawn :D
			{
				pawn* P = new pawn(); //create new object pawn to make board point to him
				P->SetPlayer(name);
				P->SetName("Pawn");
				P->SetPosition(position);
				Board[position.y][position.x] =P;  // board btshawer 3la pawn
			}
			 else if(InitBoard[y][x]=="Rock")
			 {
				 Rock* R = new Rock();
				 R->SetPlayer(name);
				 R->SetName("Rock");
				 R->SetPosition(position);
				 Board[position.y][position.x] =R;
			 }
			  else if(InitBoard[y][x]=="Knight")
			 {
				 knight* K = new knight();
				 K->SetPlayer(name);
				 K->SetName("Knight");
				 K->SetPosition(position);
				 Board[position.y][position.x] =K;
			 }
			  else if(InitBoard[y][x]=="Bishop")
			 {
				 Bishop* B = new Bishop();
				 B->SetPlayer(name);
				 B->SetName("Bishop");
				 B->SetPosition(position);
				 Board[position.y][position.x] =B;
			 }
			   else if(InitBoard[y][x]=="Queen")
			 {
				 Queen*	Q = new Queen();
				 Q->SetPlayer(name);
				 Q->SetName("Queen");
				 Q->SetPosition(position);
				 Board[position.y][position.x] =Q;
			 }
			   else if(InitBoard[y][x]=="King")
			 {
				 King* KG = new King();
				 KG->SetPlayer(name);
				 KG->SetName("King");
				 KG->SetPosition(position);
				 Board[position.y][position.x] =KG;
			 }
		}
		}

}
vector< vector<ChessPiece*> > ChessBoard::GetBoard()   // Get current board with new updates
{
	return Board;
}
void ChessBoard::SetBoard(vector< vector<ChessPiece*> > B)
{
	Board=B;
}