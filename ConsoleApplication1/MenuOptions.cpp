#include "MenuOptions.h"
#include <iostream>
using namespace std;

MenuOptions::MenuOptions(float width , float hight)
{
	font.loadFromFile("sansation.ttf");

	Menu[0].setFont(font);
	Menu[0].setString("Sound on");
	Menu[0].setColor(Color::Green);
	Menu[0].setStyle(Text::Italic);
	Menu[0].setPosition(Vector2f(width / 2, hight / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	Menu[1].setFont(font);
	Menu[1].setColor(Color::Cyan);
	Menu[1].setStyle(Text::Italic);
	Menu[1].setString("Sound off");
	Menu[1].setPosition(Vector2f(width / 2, hight / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	Menu[2].setFont(font);
	Menu[2].setColor(Color::Cyan);
	Menu[2].setStyle(Text::Italic);
	Menu[2].setString("Back");
	Menu[2].setPosition(Vector2f(width / 2, hight / (MAX_NUMBER_OF_ITEMS + 1) * 8));



	Index2=0 ;
}

int MenuOptions::getIndex()
{
	return Index2 ;
}

void MenuOptions::setIndex(int v) 
{
	Index2=v ;
}

void MenuOptions::GetBlack(int index) 
{
	Menu[index].setColor(Color::Cyan);
}

void MenuOptions::GetGreen(int index) 
{
   Menu[index].setColor(Color::Green);
}


void MenuOptions::_Draw(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		string s = Menu[i].getString();
		window.draw(Menu[i]);
	}
}

void MenuOptions::MoveUP()
{
	if (Index2 - 1 >= 0)
	{
		Menu[Index2].setColor(Color::Cyan);
		Index2--;
		Menu[Index2].setColor(Color::Green);
	}
}

void MenuOptions::MoveDown()
{
	if (Index2 +1 < MAX_NUMBER_OF_ITEMS)
	{
		Menu[Index2].setColor(Color::Cyan);
		Index2++;
		Menu[Index2].setColor(Color::Green);
	}
}