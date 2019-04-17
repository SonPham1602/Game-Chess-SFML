#pragma once
//Nguoi code:
//Pham Ngoc Son
// 1612565
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
class WindowGame
{
private:
	sf::RenderWindow m_window;// cua so game
	sf::Vector2u m_windowSize;// kich thuong cua so
	std::string m_windowTitle;// ten cua so
	bool m_isFullScreen;// trang thai full man hinh
	bool m_isDone;// bien kiem tra het cua so window con hoat dong ko
public:
	WindowGame();
	~WindowGame();
	void Destroy();// tat cua so window
	void Create();// tao cua so window
	void SetUp(const  std::string &title,const sf::Vector2u &size);// set up ten cua so va sizw
	void BeginDraw();// bat dau ve
	void EndDraw();// ket thuc ve
	void Updata();// 
	bool IsDone();// ket thuc chua
	bool IsFullScreen();// co fulll man hinh ko
	void Draw(sf::Drawable &d);// ve hinh
	sf::Vector2u GetWindowSize();// tra ve size window game
	sf::RenderWindow *GetWindowGame();// lay window
};

