
#ifdef _window_
#define  _window_
#include <iostream>
#include<string>
#include <SFML/Graphics.hpp>
class Window
{
private:
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isFullScreen;
	bool m_isDone;
	void Destroy();
	void Create();
	void SetUp(const std::string &title,const sf::Vector2u &size);
public:
	Window();
	~Window();
	Window(const std::string &title, const sf::Vector2u &size);

	void BeginDraw();
	void EndDraw();
	void Updata();
	bool IsDone();
	bool IsFullScreen();
	void Draw(sf::Drawable &l_drawable);
};
void Window::SetUp(const string &title,const Vector2u &size)
{
	m_windowTitle=title;
	m_windowSize=size;
	m_isDone=false;
	m_isFullScreen=false;
	Create();
}
void Window::Create()
{
	auto style =(m_isFullScreen ? Style::Fullscreen : Style::Default);
	m_window.create({m_windowSize.x,m_windowSize.y,32},m_windowTitle,style);
}
void Window::Destroy()
{
	m_window.close();
}
Window::Window()
{

}
#endif