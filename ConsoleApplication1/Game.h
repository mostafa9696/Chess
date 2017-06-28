#include "CheesBoard.h"
#include "ChessPiece.h"
#include "AllPieces.h"
#include "MenuBase.h"
#include "MenuOptions.h"
#include "MenuExit.h"
class Game
{
  private:
			bool W_king_move,B_king_move,End;      // To check player can make tbyeta :D
			bool W_rock_left , W_rock_right , B_rock_left , B_rock_right;  
			vector<PiecePosition> W_Ksh_King,B_Ksh_King;
			struct light
			  {
				PiecePosition p;
			  };
			vector< vector<ChessPiece*> > Board;  // creat board 2D of pieces
			vector<light> possible_light;
			vector <int> promote;
			///////////////////////////////////////// Member function
  public:
	RenderWindow window;

	Game()      // Constructor
	{
		W_king_move=B_king_move=W_rock_left=W_rock_right=B_rock_left=B_rock_right=false;
		window.create(VideoMode(1100,600),"Chess Game.",Style::Close);
		End=0;
	}
	
ChessBoard* Start()    // start game and intialize board
{
	ChessBoard* MyBoard=new ChessBoard();   // call constructor in ChessBoard class and creat board with pieces
	Board=MyBoard->GetBoard();  
	return MyBoard;
}

void Ksh(string player,RenderWindow &window)   // Check if king in threat
{
	PiecePosition Gx ;
	for(int i=0 ; i<8  ; i++)
		for(int j=0 ; j<8 ; j++)
		{
			if(Board[i][j]->GetPlayer()=="Black")
			{
				for(int q=0 ; q<Board[i][j]->protected_move().size() ; q++)  // push all possible moves of white player to avoid black king to move to it 
				{
					PiecePosition P=Board[i][j]->protected_move().at(q).position;
					W_Ksh_King.push_back(P);
				}
			}
		}
		for(int i=0 ; i<W_Ksh_King.size() ; i++)   //  Highlite red at black king possition if its possition in white moves
		{
			if(Board[W_Ksh_King[i].y][W_Ksh_King[i].x]->GetName()=="King"&&Board[W_Ksh_King[i].y][W_Ksh_King[i].x]->GetPlayer()=="White")
			{
				Texture texture;
		Sprite sprite;
			texture.loadFromFile("ksh_king.png");	
		sprite.setTexture(texture);
		sprite.setPosition(W_Ksh_King[i].x * 75,W_Ksh_King[i].y * 75);
		window.draw(sprite);
			}
		}
	
	////////////////////////////////////////////////////
	for(int i=0 ; i<8  ; i++)
		for(int j=0 ; j<8 ; j++)
		{
			if(Board[i][j]->GetPlayer()=="White")
			{
				for(int q=0 ; q<Board[i][j]->protected_move().size() ; q++)
				{
					PiecePosition P=Board[i][j]->protected_move().at(q).position;
					B_Ksh_King.push_back(P);
				}
			}
		}
		for(int i=0 ; i<B_Ksh_King.size() ; i++)
		{
			if(Board[B_Ksh_King[i].y][B_Ksh_King[i].x]->GetName()=="King"&&Board[B_Ksh_King[i].y][B_Ksh_King[i].x]->GetPlayer()=="Black")
			{
		   Texture texture;
		   Sprite sprite;
		   texture.loadFromFile("ksh_king.png");	
	    	sprite.setTexture(texture);
		   sprite.setPosition(B_Ksh_King[i].x * 75,B_Ksh_King[i].y * 75);
		   window.draw(sprite);
			}
		}
}

//////////////////////////////////////////////////
void Check_mate(vector<Possible_Move> &P,string player)
{
	//vector<PiecePosition> iterator::it;
	if(player=="White")
	{
		for(int i=0;i<P.size();i++)   // Delete possible next moves of White king if it will be in threat
		{
			for(int j=0 ; j<W_Ksh_King.size() ; j++)
			{
				if(P[i].position.x==W_Ksh_King[j].x&&P[i].position.y==W_Ksh_King[j].y) 
				{
					P.erase(P.begin()+i);
					i=-1;
					break;
				}
			}
		}
	}
	else
		{
		for(int i=0 ; i<P.size() ; i++)  // Delete possible next moves of Black king if it will be in threat
		{
			for(int j=0 ; j<B_Ksh_King.size() ; j++)
			{
				if(P[i].position.x==B_Ksh_King[j].x&&P[i].position.y==B_Ksh_King[j].y) 
				{
					P.erase(P.begin()+i);
					i=-1;
					break;
				}
			}
		}
	}
}
/////////////////////////////

void HightLight(RenderWindow &window)  // highlight on cell which piece can move to it
{
	for(int i=0 ; i<possible_light.size() ; i++)
	{
		Texture texture;
		Sprite sprite;
			texture.loadFromFile("light.png");	
		sprite.setTexture(texture);
		sprite.setPosition(possible_light[i].p.x * 75,possible_light[i].p.y * 75);
		window.draw(sprite);
	}
}

void load_promote(RenderWindow &window)    // load box of piece promotion to choose from it
{
	for(int i=0 ; i<promote.size(); i++)
	{
	Texture tex;
	Sprite spr;
	tex.loadFromFile("Promotion.png");
	spr.setTexture(tex);
	spr.setPosition(700,300);
	window.draw(spr);
	}
}

void player_turn(RenderWindow &window , string turn)   // show current player turn 
{
	Texture tex;
	Sprite spr;
	if(turn=="White")
		tex.loadFromFile("white_turn.png");
	else
		tex.loadFromFile("Black_turn.png");
	spr.setTexture(tex);
	spr.setPosition(725,0);
	window.draw(spr);
	
}

void draw_board(string player)   // draw and update board after each step
{
	window.clear(Color::Color(0,144, 155 , 255));
	window.clear(Color::Color(00 , 66 , 66));
	Texture texture;
	Sprite sprite;
	texture.loadFromFile("board1.png");
	sprite.setTexture(texture);
	window.draw(sprite);
	HightLight(window);
	load_promote(window);
	player_turn(window, player);
	//piece_die(player,window);
	Ksh(player,window);
	for(int i=0 ; i<8 ; i++)    // Draw every piece which the board point.
	{
		for(int j=0 ; j<8 ; j++)
		{
			Board[i][j]->Draw(window);
		}
	}
	promote.clear();
	W_Ksh_King.clear();
	B_Ksh_King.clear();
	possible_light.clear();
	window.display();
}

void mouse_button(PiecePosition & pos , string &Mouse_event)  // get the click position from user
{
Event E;
	while (window.isOpen())
	{
		while (window.pollEvent(E))
		{
			if (E.type == sf::Event::Closed)
			{
				window.close();
				return;
			}
		}
		if(E.mouseButton.x>0 && E.mouseButton.x<597 && E.mouseButton.y>0 && E.mouseButton.y<597&&Mouse_event!="PR")   // check mouse press at board bound
		{

	        if (Mouse::isButtonPressed(Mouse::Left))    
			{
				Mouse_event="Left";
				pos.x = E.mouseButton.x;
				pos.y = E.mouseButton.y;
				return ;
			}
			else if (Mouse::isButtonPressed(Mouse::Right))
			{
				Mouse_event="Right";
				pos.x = E.mouseButton.x;
				pos.y = E.mouseButton.y;
				return ;
			}
		}
		else if(Mouse_event=="PR"&&E.mouseButton.y>300&&E.mouseButton.y<450&&E.mouseButton.x>700&&E.mouseButton.x<1000)  // choose piece promotion which player choose 
		{
			if (Mouse::isButtonPressed(Mouse::Left))    
			{
				pos.x = E.mouseButton.x;
				pos.y = E.mouseButton.y;
				return ;
			}
		}
		else if(Mouse_event=="Win"&&((E.mouseButton.x>300&&E.mouseButton.x<500&&E.mouseButton.y>200&&E.mouseButton.y<260)||(E.mouseButton.x>600&&E.mouseButton.x<800&&E.mouseButton.y>200&&E.mouseButton.y<260)))
		{
			if (Mouse::isButtonPressed(Mouse::Left))    
			{
				pos.x = E.mouseButton.x;
				pos.y = E.mouseButton.y;
				return ;
			}
		}

	}
}

void White_Win(RenderWindow &window)  // load window tell white is win
{
	string mouse_E="Win";
	PiecePosition From;
	while(true)
	{
	Texture texture;
	Sprite sprite;
	texture.loadFromFile("W_win.png");
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();
	mouse_button(From,mouse_E);
	if(From.x>300&&From.x<500&&From.y>200&&From.y<260) 
	StartMenu();
	else if(From.x>600&&From.x<800&&From.y>200&&From.y<260)
	{window.close(); break;}
	}
}

void Black_Win(RenderWindow &window)
{
	string mouse_E="Win";
		PiecePosition From;
	while(true)
	{
	Texture texture;
	Sprite sprite;
	texture.loadFromFile("B_win.png");
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();
	mouse_button(From,mouse_E);
	if(From.x>300&&From.x<500&&From.y>200&&From.y<260) 
		StartMenu();
	else if(From.x>600&&From.x<800&&From.y>200&&From.y<260)
	{window.close(); break; }
	}
}

void IN_board(string player , ChessBoard *at_board)  // player determined who has turn ,,,object at_board to set every update board 
{
	light HL;	
	string Mouse_event="";  // to know user click mouse right or left
	draw_board(player);
	/*while(window.isOpen())  // check board position
	{
		Event Event;
		while(window.pollEvent(Event)){
			if(Event.type== Event::MouseMoved)
				cout<<Event.mouseMove.x<<" "<<Event.mouseMove.y<<endl;
		}
	}*/
	while(window.isOpen())
	{

		draw_board(player);
		Ksh(player,window);
		PiecePosition from,to;       // from current position to next position
		from.x=from.y=to.x=to.y=-1;

		mouse_button(from,Mouse_event);      // get current piece position
		if(!window.isOpen()) break;
 		if(Mouse_event=="Right"||(from.x==-1 && from.y==-1)) continue;     // continue if press right click or click out board bound

		from.y/=75;        //get position of cell 
		from.x/=75;
        if(Board[from.y][from.x]->GetPlayer()!=player) continue;      // continue if selecet player that is not its turn

		
		if(from.x == to.x&& from.y==to.y) continue;  // if user change its decision
		////////////
		vector<Possible_Move> Piece_moves = Board[from.y][from.x]->move();  // get all possible move of piece
		if(Board[from.y][from.x]->GetName()=="King")
		{
			Check_mate(Piece_moves,player);
		}
		HL.p=from;
		possible_light.push_back(HL);
		for(int i=0 ; i<Piece_moves.size(); i++)
		{
			HL.p=Piece_moves[i].position;
			if(Board[from.y][from.x]->GetName()=="King"&&Piece_moves[i].position.x==1&&Piece_moves[i].position.y==7&&(B_king_move||B_rock_left)&&from.y==7&&from.x==3) continue; // TO not show the highlight bta3 el tbyeta if king or rock move 
			if(Board[from.y][from.x]->GetName()=="King"&&Piece_moves[i].position.x==5&&Piece_moves[i].position.y==7&&(B_king_move||B_rock_right)&&from.y==7&&from.x==3) continue;
			if(Board[from.y][from.x]->GetName()=="King"&&Piece_moves[i].position.x==1&&Piece_moves[i].position.y==0&&(W_king_move||W_rock_left)&&from.y==0&&from.x==3) continue;
			if(Board[from.y][from.x]->GetName()=="King"&&Piece_moves[i].position.x==5&&Piece_moves[i].position.y==0&&(W_king_move||W_rock_right)&&from.y==0&&from.x==3) continue;
			possible_light.push_back(HL);
		}
		////////////
		draw_board(player);
		
		mouse_button(to,Mouse_event);                  // get next piece position
		if(Mouse_event=="Right"||(to.x==-1 && to.y==-1)) continue;
		if(!window.isOpen())break;
		if(to.x==-1 && to.y==-1 || Mouse_event=="Right") continue;
		to.y/=75;
		to.x/=75;
		/////////////////
		for(int i=0 ; i<Piece_moves.size() ; i++) 
		     {
		if(Piece_moves[i].position.x == to.x  &&  Piece_moves[i].position.y == to.y) 
		        {
                     ////////////////  Tbyeta :D
					if(Board[from.y][from.x]->GetName()=="King"&&to.x==1&&to.y==7&&Board[from.y][from.x]->GetPlayer()=="Black"&&!B_king_move&&!B_rock_left)  // Tbyeta le king black na7ya -> left rock 
					{
						ChessPiece *P1=new ChessPiece();
						PiecePosition N;
						N.x=1;
						N.y=7;
						Board[from.y][from.x]->SetPosition(N);
						Board[7][1]=Board[from.y][from.x];
						Board[from.y][from.x]=P1;
						N.x=2 , N.y=7;
						ChessPiece *P2=new ChessPiece();
						Board[to.y][0]->SetPosition(N);
						Board[7][2]=Board[7][0];
						Board[7][0]=P2;
					}
					else if(Board[from.y][from.x]->GetName()=="King"&&to.x==5&&to.y==7&&Board[from.y][from.x]->GetPlayer()=="Black"&&!B_king_move&&!B_rock_right)   // Tbyeta le king black na7ya -> right rock
					{
						ChessPiece *P1=new ChessPiece();
						PiecePosition N;
						N.x=5;
						N.y=7;
						Board[from.y][from.x]->SetPosition(N);
						Board[7][5]=Board[from.y][from.x];
						Board[from.y][from.x]=P1;
						N.x=4 , N.y=7;
						ChessPiece *P2=new ChessPiece();
						Board[to.y][7]->SetPosition(N);
						Board[7][4]=Board[7][7];
						Board[7][7]=P2;
					}
					else if(Board[from.y][from.x]->GetName()=="King"&&to.x==1&&to.y==0&&Board[from.y][from.x]->GetPlayer()=="White"&&!W_king_move&&!W_rock_left)  // Tbyeta le king white na7ya -> left rock lw lesa king mat7rkshy :D
					{
						ChessPiece *P1=new ChessPiece();
						PiecePosition N;
						N.x=1;
						N.y=0;
						Board[from.y][from.x]->SetPosition(N);
						Board[0][1]=Board[from.y][from.x];
						Board[from.y][from.x]=P1;
						N.x=2 , N.y=0;
						ChessPiece *P2=new ChessPiece();
						Board[to.y][0]->SetPosition(N);
						Board[0][2]=Board[0][0];
						Board[0][0]=P2;
					}
					else if(Board[from.y][from.x]->GetName()=="King"&&to.x==5&&to.y==0&&Board[from.y][from.x]->GetPlayer()=="White"&&!W_king_move&&!W_rock_right)  // Tbyeta le king right na7ya -> right rock
					{
						ChessPiece *P1=new ChessPiece();
						PiecePosition N;
						N.x=5;
						N.y=0;
						Board[from.y][from.x]->SetPosition(N);
						Board[0][5]=Board[from.y][from.x];
						Board[from.y][from.x]=P1;
						N.x=4 , N.y=0;
						ChessPiece *P2=new ChessPiece();
						Board[to.y][7]->SetPosition(N);
						Board[0][4]=Board[0][7];
						Board[0][7]=P2;
					}
					///////////////////////////// End of tbyeta 
					else 
					{
						if(Board[from.y][from.x]->GetName()=="King"&&Board[from.y][from.x]->GetPlayer()=="Black") B_king_move=true;  // ignore tbyeta
						if(Board[from.y][from.x]->GetName()=="Rock"&&Board[from.y][from.x]->GetPlayer()=="Black"&&from.y==7&&from.x==0) B_rock_left=true;
						if(Board[from.y][from.x]->GetName()=="Rock"&&Board[from.y][from.x]->GetPlayer()=="Black"&&from.y==7&&from.x==7) B_rock_right=true;
						if(Board[from.y][from.x]->GetName()=="King"&&(B_king_move||B_rock_left)&&to.x==1&&to.y==7&&from.x==3&&from.y==7&&Board[from.y][from.x]->GetPlayer()=="Black")continue;
						if(Board[from.y][from.x]->GetName()=="King"&&(B_king_move||B_rock_right)&&to.x==5&&to.y==7&&from.x==3&&from.y==7&&Board[from.y][from.x]->GetPlayer()=="Black")continue;
						if(Board[from.y][from.x]->GetName()=="King"&&Board[from.y][from.x]->GetPlayer()=="White") W_king_move=true;
						if(Board[from.y][from.x]->GetName()=="Rock"&&Board[from.y][from.x]->GetPlayer()=="White"&&from.y==0&&from.x==0) W_rock_left=true;
						if(Board[from.y][from.x]->GetName()=="Rock"&&Board[from.y][from.x]->GetPlayer()=="White"&&from.y==0&&from.x==7) W_rock_right=true;
						if(Board[from.y][from.x]->GetName()=="King"&&(W_king_move||W_rock_left)&&to.x==1&&to.y==0&&from.x==3&&from.y==0&&Board[from.y][from.x]->GetPlayer()=="White")continue;
						if(Board[from.y][from.x]->GetName()=="King"&&(W_king_move||W_rock_right)&&to.x==5&&to.y==0&&from.x==3&&from.y==0&&Board[from.y][from.x]->GetPlayer()=="White")continue;


						if(Board[from.y][from.x]->GetPlayer()=="White"&&Board[to.y][to.x]->GetPlayer()=="Black"&&Board[to.y][to.x]->GetName()=="King")
						{
							White_Win(window);
							End=1;
							break;
						}
						if(Board[from.y][from.x]->GetPlayer()=="Black"&&Board[to.y][to.x]->GetPlayer()=="White"&&Board[to.y][to.x]->GetName()=="King")
						{
							Black_Win(window);
							End=1;
							break;
						}

			Board[from.y][from.x]->SetPosition(to);   // position of selected piece set to (to.y,to.x)
		Board[to.y][to.x]=Board[from.y][from.x];      // cell of board[to.y][to.x] become point to piece at Board[from.y][from.x]

		ChessPiece *p=new ChessPiece();   // creat empty piece to make the old position point to it
		p->SetPosition(from);
		Board[from.y][from.x]=p;        // from (old) position point to empty place
					}
		at_board->SetBoard(Board);      // member Board in obj at_board = Board
			if(player=="White")
		{
			for(int i =0 ; i<8 ; i++)         // Pawn promotion 
			{
				if( Board[7][i]->GetName()=="Pawn")
				{
					promote.push_back(1);
					draw_board(player);
					string mouse_E="PR";
					PiecePosition _to;
					mouse_button(_to,mouse_E);
					
					while(_to.y<300&&_to.y>450&&_to.x<700&&_to.x>1000)
					{
						draw_board(player);
						mouse_button(_to,mouse_E);
					}
						int s=_to.x-700;
 						if(s>=150&&s<225)
						{
							Rock* R = new Rock();
							R->SetPlayer("White");
							R->SetName("Rock");
							R->SetPosition(to);
							Board[to.y][to.x] =R;
						}
						else if(s>=75&&s<150)
						{
							knight* K = new knight();
							K->SetPlayer("White");
							K->SetName("Knight");
							K->SetPosition(to);
							Board[to.y][to.x] =K;
						}
						else if(s>=0&&s<75)
						{
							Bishop* B = new Bishop();
							B->SetPlayer("White");
							B->SetName("Bishop");
							B->SetPosition(to);
							Board[to.y][to.x] =B;
						}
						else if(s>=225)
						{
							Queen*	Q = new Queen();
							Q->SetPlayer("White");
							Q->SetName("Queen");
							Q->SetPosition(to);
							Board[to.y][to.x] =Q;
						}	
				}
			}
		}
		else      ////////////////// promote Black
		{
			for(int i =0 ; i<8 ; i++)
			{
				if(Board[0][i]->GetName()=="Pawn")
				{
					promote.push_back(1);
					draw_board(player);
					string mouse_E="PR";
					PiecePosition _to;
					mouse_button(_to,mouse_E);			
					while(_to.y<300&&_to.y>450&&_to.x<700&&_to.x>1000)
					{
						draw_board(player);
						mouse_button(_to,mouse_E);
					}
					int s=_to.x-700;
 					if(s>=150&&s<225)
					{
						Rock* R = new Rock();
						R->SetPlayer("Black");
						R->SetName("Rock");
						R->SetPosition(to);
						Board[to.y][to.x] =R;
					}
					else if(s>=75&&s<150)
					{
						knight* K = new knight();
						K->SetPlayer("Black");
						K->SetName("Knight");
						K->SetPosition(to);
						Board[to.y][to.x] =K;
					}
					else if(s>=0&&s<75)
					{
						Bishop* B = new Bishop();
						B->SetPlayer("Black");
						B->SetName("Bishop");
						B->SetPosition(to);
						Board[to.y][to.x] =B;
					}
					else if(s>=225)
					{
						Queen*	Q = new Queen();
						Q->SetPlayer("Black");
						Q->SetName("Queen");
						Q->SetPosition(to);
						Board[to.y][to.x] =Q;
					}
				}
			}
		}
		
		if(player=="White") player="Black";   // change player turn
		else player="White";
		         }
	         }
			 if(End) 
			break;
		Piece_moves.clear();
		////////////////
	}
}

void StartMenu()
{
	//RenderWindow window(VideoMode(1100,600), "CHESS");
	window.clear(Color::Black);
	//////////////////////////////////////
	
	Texture tex1 ;

	//Load a pic png File
 
	if(!tex1.loadFromFile("final1.png") ) cout << "error" << endl ;
    Sprite sprite1(tex1) ;	
    sprite1.setPosition(Vector2f(0 , 0)) ;
	/////////////////////////////////////
	SoundBuffer soundBuffer;
	Sound sound;
	if (!soundBuffer.loadFromFile("Music.wav"))cout << "Error" << endl; //Load a Sound File
	sound.setBuffer(soundBuffer);
	////////////////////////////////////
	MenuBase menu(150, 150);   //Base Menu
	MenuOptions Mop(150 , 150) ; // Option Menu
	MenuExit Mexit(50 , 50) ; //Exit Menu

	//choice between screens
	bool base=true ;
	bool op=false ;
	bool exit=false ;
	bool ssound=true ; // get sound on or off

	while (window.isOpen())
	{
		Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
           	// if selected Screen is Base Screen
				if(base)
				{ 
					//press escape ,, exit game !
					 if (event.key.code == Keyboard::Escape)
					{
						exit=true ;
						base=false ;
						op=false ;
						Mexit.GetGreen(0);
						menu.GetBlack(menu.getIndex()) ;
						menu.setIndex(0) ;
					}
					 //Moving Keyboard Up
					else if (event.key.code == Keyboard::Up)
						menu.MoveUP();
					 //Moving Keyboard Down
					else if (event.key.code == Keyboard::Down)
		             	menu.MoveDown();
		
					//if you pressed enter
					else if (event.key.code == Keyboard::Return)
					{
						//get choice
						//play game
						if(menu.getIndex()==0)
							{
								if(ssound)
								{
									sound.play() ;
									sound.setLoop(true) ;
								}
								ChessBoard* inti_board=Start();
								IN_board("White",inti_board);  // white play first
								if(End)
								{
									break;
								}
							}
						//get options menu
						else if(menu.getIndex()==1)
							{		
								base=false ;
								op=true ;
								exit=false ;
								Mop.GetGreen(0);
								menu.GetBlack(menu.getIndex()) ;
								menu.setIndex(0) ;
							}
						//quit game
						else if(menu.getIndex()==2)
							{
								exit=true ;
								base=true ;
								op=false ;
								Mexit.GetGreen(0);
								menu.GetBlack(menu.getIndex()) ;
								menu.setIndex(0) ;
							}
					}
				}
				// if selected Screen is Option Screen
				if(op)
				{
					//get choice
					//Moving Keyboard Up
					if (event.key.code == Keyboard::Up)	
						Mop.MoveUP() ;
					//Moving Keyboard Down
				else if (event.key.code == Keyboard::Down)
	                   Mop.MoveDown();
					//if you pressed enter
				else if (event.key.code == Keyboard::Return)
					{
						//sound on
						if(Mop.getIndex()==0)
							ssound=true ;
						//sound off
						else if(Mop.getIndex()==1)
							ssound=false ;

						//back to Base Meun
						else if(Mop.getIndex()==2)
						{
							
							base=true ;
							op=false ;
							exit=false ;
							menu.GetGreen(0) ;
							Mop.GetBlack(Mop.getIndex()) ;
							Mop.setIndex(0) ;
						}
				    }
				  }
				// if selected screen is exit screen
				if(exit)
				{
					//get choice
					//Moving Keyboard Right
					if (event.key.code == Keyboard::Right)
						Mexit.MoveRight() ;
					//Moving Keyboard Left
					else if (event.key.code == Keyboard::Left)		
						Mexit.MoveLeft() ;
					//if you pressed enter
				else if (event.key.code == Keyboard::Return)
				{
						// exit game !
						 if(Mexit.getIndex()==1)
						{
							
							window.close() ;
							base=false ;
							op=false ;
							exit=false ;
						}
						 //back to Base Menu
						else if(Mexit.getIndex()==2)
						{
							base=true ;
							op=false ;
							exit=false ;

							menu.GetGreen(0) ;
							Mexit.GetBlack(Mexit.getIndex()) ;

							Mexit.setIndex(1) ;
						}						
					 }
				}
			}
			if (event.type == Event::Closed)
				window.close();
		}	
		window.clear(Color(255, 255, 255, 255));
		window.draw(sprite1);
		//which is on ?!
		if(End) break;
		if(base&&!End)
			menu._Draw(window);
		if(op)
			Mop._Draw(window) ;
		if(exit)
			Mexit._Draw(window) ;
		window.display();
	}
}

};
