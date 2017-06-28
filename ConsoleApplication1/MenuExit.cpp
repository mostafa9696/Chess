#include "MenuExit.h"
#include <iostream>

using namespace std;


MenuExit::MenuExit(float width , float hight)
{
	font.loadFromFile("sansation.ttf");

	Menu[0].setFont(font);
	Menu[0].setString("Exit Game ?");
	Menu[0].setColor(Color::Black);
	Menu[0].setStyle(Text::Italic);
	Menu[0].setPosition(Vector2f(width / 2, hight / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	Menu[1].setFont(font);
	Menu[1].setColor(Color::Cyan);
	Menu[1].setStyle(Text::Italic);
	Menu[1].setString("Yes");
	Menu[1].setPosition(Vector2f(width / 2, hight / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	Menu[2].setFont(font);
	Menu[2].setColor(Color::Cyan);
	Menu[2].setStyle(Text::Italic);
	Menu[2].setString("No");
	Menu[2].setPosition(Vector2f(width*2 , hight / (MAX_NUMBER_OF_ITEMS + 1) * 4));



	Index3=1 ;
}

int MenuExit::getIndex()
{
	return Index3 ;
}

void MenuExit::setIndex(int v) 
{
	Index3=v ;
}

void MenuExit::GetBlack(int index) 
{
	Menu[index].setColor(Color::Cyan);
}

void MenuExit::GetGreen(int index) 
{
   Menu[index].setColor(Color::Green);
}


void MenuExit::_Draw(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		string s = Menu[i].getString();
		window.draw(Menu[i]);
	}
}

void MenuExit::MoveRight()
{
	if (Index3 +1 < MAX_NUMBER_OF_ITEMS)
	{
		Menu[Index3].setColor(Color::Cyan);
		Index3++;
		Menu[Index3].setColor(Color::Green);
	}
}


void MenuExit::MoveLeft()
{
	if (Index3 - 1 >= 1)
	{
		Menu[Index3].setColor(Color::Cyan);
		Index3--;
		Menu[Index3].setColor(Color::Green);
	}
}

