#include "Game.h"
#define _WIN32_WINNT 0x0500 
#include <windows.h> 
void main()
{
	 HWND hWnd = GetConsoleWindow();  // Hide console 
    ShowWindow( hWnd, SW_HIDE );
	Game play;
	play.StartMenu();
}