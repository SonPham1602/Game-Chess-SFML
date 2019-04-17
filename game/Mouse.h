//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma  once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class MouseGame// class chuot
{
private:
	sf::Sprite PictureOfMouse;// hinh
	sf::Texture TextureMose;// hinh
	std::string locationImage;// dia chhi
	sf::Vector2i PosOfMouse;// position of mouse in screen
public:
	MouseGame();// khoi tao
	~MouseGame();// huy 
	void SetLocation(std::string lc);// lc la dia chi 
	void SetImage();//cai dat hinh 
	void GetPositionOfMouse(sf::RenderWindow &wd);
	void DrawMouse(sf::RenderWindow& wd);// ve chuot
	bool CheckGetGlobalBoundsMouse(sf::Sprite image);// kiem tra 
	bool CheckGetGlobalBoundsMouse(sf::Vector2i temp);// kiem tra
	bool CheckGetGlobalBoundsMouse(sf::Vector2i temp,int x, int y);// kiem tra

	sf::Vector2f GetPositionVector();
	void ChangeImage(std::string lc);// thay doi hinh 
	void OutPutPosOfMouseInConsole();// xuat vi tri ra console
};