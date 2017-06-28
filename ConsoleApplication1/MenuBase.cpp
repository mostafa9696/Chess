#include "MenuBase.h"
#include <iostream>
using namespace std;

MenuBase::MenuBase(float width, float hight)
{
	font.loadFromFile("sansation.ttf");

	Menu[0].setFont(font);
	Menu[0].setString("Play");
	Menu[0].setColor(Color::Green);
	Menu[0].setStyle(Text::Italic);
	Menu[0].setPosition(Vector2f(width / 2, hight / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	Menu[1].setFont(font);
	Menu[1].setColor(Color::Cyan);
	Menu[1].setStyle(Text::Italic);
	Menu[1].setString("Options");
	Menu[1].setPosition(Vector2f(width / 2, hight / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	
	Menu[2].setFont(font);
	Menu[2].setColor(Color::Cyan);
	Menu[2].setStyle(Text::Italic);
	Menu[2].setString("Exit");
	Menu[2].setPosition(Vector2f(width / 2, hight / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	Index1 = 0;
}


int MenuBase::getIndex()
{
	return Index1 ;
}

void MenuBase::setIndex(int v) 
{
	Index1=v ;
}

void MenuBase::GetBlack(int index) 
{
	Menu[index].setColor(Color::Cyan);
}

void MenuBase::GetGreen(int index) 
{
   Menu[index].setColor(Color::Green);
}

void MenuBase::_Draw(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		string s = Menu[i].getString();
		window.draw(Menu[i]);
	}
}

void MenuBase::MoveUP()
{
	if (Index1 - 1 >= 0)
	{
		Menu[Index1].setColor(Color::Cyan);
		Index1--;
		Menu[Index1].setColor(Color::Green);
	}
}

void MenuBase::MoveDown()
{
	if (Index1 +1 < MAX_NUMBER_OF_ITEMS)
	{
		Menu[Index1].setColor(Color::Cyan);
		Index1++;
		Menu[Index1].setColor(Color::Green);
	}
}