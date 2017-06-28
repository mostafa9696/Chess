#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;

using namespace std ;
#define MAX_NUMBER_OF_ITEMS 3

class MenuBase
{
public:
	MenuBase(float width,float height);

	void _Draw(RenderWindow &window);
	void MoveUP();
	void MoveDown();
	int getIndex() ;
	void setIndex(int v) ;
	void GetBlack(int index) ;
	void GetGreen(int index) ;

	//void Enter(RenderWindow &window);
	//void Play();

private:
	int Index1 ;
	Font font;
	Text Menu[MAX_NUMBER_OF_ITEMS];
};
