//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma  once
#include "WindowGame.h"
#include <SFML/Graphics.hpp>
enum class TypeInPut
{
	LEFT_MOUSE,
	RIGHT_MOUSE,
	WAIT_MOUSE
};
class EventInputGame// bat su kien trong game 
{
private:
	sf::Event m_Event;	
	WindowGame *m_window;
public:
	TypeInPut typeInputMouse;
	void SetWindow(WindowGame *w);// set window vao event
	void CheckEvent();// kiem tra su kien la j 
	sf::Event GetEvent();// lay su kien
	void CheckEvent(sf::Sprite &s);
};