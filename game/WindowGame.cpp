#include "WindowGame.h"
WindowGame::WindowGame()
{
	m_isFullScreen=false;
	m_isDone=false;
}
void WindowGame::SetUp(const  std::string &title,const sf::Vector2u &size)
{
	m_windowTitle=title;
	m_windowSize=size;
	Create();
}
WindowGame::~WindowGame()
{
	Destroy();
}
void WindowGame::Create()
{
	auto style =(m_isFullScreen ? sf::Style::Fullscreen :sf::Style::Default);
	m_window.create(sf::VideoMode(m_windowSize.x,m_windowSize.y),m_windowTitle,style);
}
void WindowGame::Destroy()
{
	m_window.close();
}
void WindowGame::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}
void WindowGame::EndDraw()
{
	m_window.display();
} 
bool WindowGame::IsDone()
{
	return m_window.isOpen();
}
bool WindowGame::IsFullScreen()
{
	return m_isFullScreen;
}
sf::Vector2u WindowGame::GetWindowSize()
{
	return m_windowSize;
}
void WindowGame::Draw(sf::Drawable &d)
{
	m_window.draw(d);
}
sf::RenderWindow *WindowGame::GetWindowGame()
{
	return &m_window;
}