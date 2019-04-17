
#include<windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<ctime>
#include "BoardChess.h"
#include "SoundGame.h"
#include "MusicGame.h"
#include "Mouse.h"
#include "Game.h"
using namespace sf;
using namespace std;
void TurnOffConsole()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);
}
void main()
{
	ShowCursor(false);
	TurnOffConsole();
	Game g;
	while (g.GetStateGame()!=StateMenu::EXIT_GAME)
	{
	g.IntGame();
	g.HandleInput();
	}
	
}
