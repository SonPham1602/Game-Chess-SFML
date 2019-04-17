//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma  once
#include<SFML/Graphics.hpp>
#include<vector>
#include "Mouse.h"
#include "MusicGame.h"
#include "SoundGame.h"
#include "WindowGame.h"
#include "EventInput.h"
using namespace sf;
using namespace std;
enum class StateMenu
{
	WAIT,
	PLAY_GAME,
	OPTION_GAME,
	EXIT_GAME
};
enum class ModeGame// class enum che do game
{
	P1vsP2,
	PvsCPU,
	WAIT
};
struct Volume 
{
	int Sound;
	int Music;
};
class MenuGame
{
private:
	Volume volume;
	MouseGame mo_Menu;
	MusicGame mu_Menu;
	SoundGame so_Menu;
	StateMenu m_stateGame;
	WindowGame m_window;
	EventInputGame e_window;
	ModeGame modeGame;
public:
	void RunMouseAndMusicAndSound();// khoi tao nhac, hinh chuot
	StateMenu  InitiationMenu();
	ModeGame GetModeGame();// tra ve che do game da chon
	void PlayMenu();
	void DragAndDrop(Sprite &s,bool &moving,Vector2i pos)
	{
		int dx,dy;
		sf::Event e;
		
		while(m_window.GetWindowGame()->pollEvent(e))
		{
			//std::cout<<"mouse:"<<e.mouseMove.x<<":"<<e.mouseMove.y<<endl;
			switch (e.type) {
			case sf::Event::MouseButtonPressed:
				// Mouse button is pressed, get the position and set moving as active
				if (e.mouseButton.button == 0 && s.getGlobalBounds().contains(mo_Menu.GetPositionVector().x,mo_Menu.GetPositionVector().y)==true) {
					std::cout<<"co";
					moving = true;
					dx=pos.x-s.getPosition().x;
					dy=pos.y-s.getPosition().y;
				}
				break;
			case  sf::Event::MouseButtonReleased:
				// Mouse button is released, no longer move
				if (e.mouseButton.button == 0 ) {
					moving = false;
				}
				break;
			}
		}
		if(moving)
		{
			std::cout<<pos.x-dx;
			s.setPosition(pos.x-dx,s.getPosition().y);		
		}
	}
	void SetVolumeGame(Volume &v)
	{
		v.Music=volume.Music;
		v.Sound=volume.Sound;
	}
};