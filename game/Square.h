#pragma once
//Nguoi code:
//Pham Ngoc Son
// 1612565
#include <iostream>
#include <string>
using namespace std;
class Square// o co
{
private: 
	int Column;// cot
	int Row;// dong
public:
	Square();// khoi tao
	~Square();// huy
	Square(int c, int r);// khoi tao 
	void ChangeSquare(int c, int r);// thay doi
	int GetColumn();// lay cot
	int GetRow();// lay dong
};
