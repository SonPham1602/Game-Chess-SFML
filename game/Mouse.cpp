#include "Mouse.h"
MouseGame::MouseGame()
{

}
MouseGame::~MouseGame()
{

}
void MouseGame::SetLocation(std::string lc)
{
	locationImage=lc;
}
void MouseGame::SetImage()
{
	if(TextureMose.loadFromFile(locationImage)==false)
	{
		std::cout<<"Loi mo file chuot\n";
	}
	else
	{
		PictureOfMouse.setTexture(TextureMose);
	}
}
void MouseGame::GetPositionOfMouse(sf::RenderWindow &wd)
{
	PosOfMouse=sf::Mouse::getPosition(wd);
	PictureOfMouse.setPosition(PosOfMouse.x,PosOfMouse.y);
}
void MouseGame::DrawMouse(sf::RenderWindow& wd)
{
	wd.draw(PictureOfMouse);
}
bool MouseGame::CheckGetGlobalBoundsMouse(sf::Sprite image)
{
	if(image.getGlobalBounds().contains(PosOfMouse.x,PosOfMouse.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void MouseGame::ChangeImage(std::string lc)
{
	SetLocation(lc);
	SetImage();
}
bool MouseGame::CheckGetGlobalBoundsMouse(sf::Vector2i temp)
{
	if(PosOfMouse.x>=temp.x*90+24 && PosOfMouse.x<=(temp.x+1)*90+24 && PosOfMouse.y>=temp.y*90+24 && PosOfMouse.y<=(temp.y+1)*90+24)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void MouseGame::OutPutPosOfMouseInConsole()
{
	std::cout<<PosOfMouse.x<<":"<<PosOfMouse.y<<std::endl;
}
bool MouseGame::CheckGetGlobalBoundsMouse(sf::Vector2i temp, int x, int y)
{
	if(PosOfMouse.x>=temp.x && PosOfMouse.x<=temp.x+x && PosOfMouse.y>=temp.y && PosOfMouse.y<=temp.y+y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
sf::Vector2f MouseGame::GetPositionVector()
{
	sf::Vector2f temp;
	temp.x=PosOfMouse.x;
	temp.y=PosOfMouse.y;
	return temp;
}