#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>


using namespace sf;

using namespace std ;

#define MAX_NUMBER_OF_ITEMS 3

class MenuExit
{
public:
	public:
	MenuExit(float width , float hight);

	void _Draw(RenderWindow &window) ;
	void MoveRight() ;
	void MoveLeft() ;
	int getIndex() ;
	void setIndex(int v) ;
	void GetBlack(int index) ;
	void GetGreen(int index) ;

private:

	int Index3 ;
	Font font;
	Text Menu[MAX_NUMBER_OF_ITEMS];


};


