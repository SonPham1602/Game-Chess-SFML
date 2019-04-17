
//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include "Square.h"
#include "WindowGame.h"
#include "Mouse.h"
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
const int sizePiece=90;
const int lengthBoard=7;
const int widthBoard=7;
const int landMark=24;
enum class ColorGame
{
	Black,
	White
};
enum class PieceBoard
{
	WhitePieceBoard,
	BlackPieceBoard,
	EmptyPieceBoard,
	EnemyPieceBoard,
	SamePieceBoard
};
class Piece// class qan co
{
protected:
	Square PlaceCurrent;// vi tri hien tai
	ColorGame PieceColor;// mau sac
	vector<sf::Vector2i> PossibleLocation;// danh sach vi tri di duoc
public:
	bool SelectionPiece;// bien kiem tra quan co duoc chon
	bool SelectionErasePiece;// bien kiem tra quan co xoa
	Sprite SpritePiece;// hinh anh quan co
	Texture TexturePiece;// hinh anh quan co
	virtual void SetImage()=0;// cai dat anh 
	virtual void SetPosition()=0;// cai dat vi tri anh
	virtual Square GetPlaceCurrent()=0;// lay vi tri hien tai quan co
	virtual ColorGame GetColorPiece()=0;// lay mau sac quan co
	virtual void SetSelectioin()=0;// cai dat quan co dc chon
	virtual void UnSelection()=0;// huy cai dat quan co dc chon
	virtual void GetPossibleMoveLocation(PieceBoard b[][8])=0;// cai dat cac vi tri di chuyen dc
	void AddPossibleMoveLocation(Vector2i temp);// them vi tri vao mang vi tri di dc
	PieceBoard CheckPossibleMoveLocation(int c, int r,PieceBoard b[][8],ColorGame color);// kiem tra va add di chuyen
	void OutPutConsolePossibleMoveLocation();// xuat di tri ra console
	void ClearPossibleMoveLocation();// xoa vector di vi di dc
	void CheckAndAddPossibleMoveLocation(int c, int r,PieceBoard b[][8],ColorGame color);// kiem tra va add luon
	int GetSizePossibleMoveLocation();// lay size mang di chuyen
	Vector2i GetPossibleMoveOfNumber(int i);// // lay vi tri di duoc theo so
	virtual void MoveNewPlace(int c, int r)=0;// di chuyen quan co ra vi ri moi
	int CheckInVectorMoveLocation(MouseGame *m);// kiem tra chuot vs vi tri di chuyen dc
	void SetEat();// cai dat trang thai an
	void UnSetEat();// huy cai dat trang thai an
	bool CheckChangePiece();// kiem tra thay doi quan co
	void OutputPlaceCurrentConsole();// xuat vi tri hien tai ra console
	void ChangeLocationFileTexture(string l);// thay doi file hinh
};
class King:public Piece
{
public:
	King(int c, int r, ColorGame color);
	void SetImage();
	void SetPosition();
	Square GetPlaceCurrent();
	void SetSelectioin();
	void UnSelection();
	void GetPossibleMoveLocation(PieceBoard b[][8]); 
	ColorGame GetColorPiece();
	void MoveNewPlace(int c, int r);
};
class Queen:public Piece
{
public:
	Queen(int c, int r, ColorGame color);
	void SetImage();
	void SetPosition();
	Square GetPlaceCurrent();
	void SetSelectioin();
	void UnSelection();
	void GetPossibleMoveLocation(PieceBoard b[][8]);
	ColorGame GetColorPiece();
	void MoveNewPlace(int c, int r);
};
class Rook:public Piece
{
public:
	Rook(int c, int r, ColorGame color);
	void SetImage();
	void SetPosition();
	Square GetPlaceCurrent();
	void SetSelectioin();
	void UnSelection();
	void GetPossibleMoveLocation(PieceBoard b[][8]);
	ColorGame GetColorPiece();
	void MoveNewPlace(int c, int r);
};
class Knight:public Piece
{
public:
	Knight(int c, int r, ColorGame color);
	void SetImage();
	void SetPosition();
	Square GetPlaceCurrent();
	void SetSelectioin();
	void UnSelection();
	void GetPossibleMoveLocation(PieceBoard b[][8]);
	ColorGame GetColorPiece();
	void MoveNewPlace(int c, int r);
};

class Pawn:public Piece
{
private:
	bool FirstMove;// kiem tra buoc di chuyen dau tien
public:
	Pawn(int c, int r, ColorGame color);
	void SetImage();
	void SetPosition();
	Square GetPlaceCurrent();
	void SetSelectioin();
	void UnSelection();
	void GetPossibleMoveLocation(PieceBoard b[][8]);
	ColorGame GetColorPiece();
	bool GetFirstMove();
	void SetFirstMoveFalse();
	void MoveNewPlace(int c, int r);
};
class Bishop:public Piece
{
public:
	Bishop(int c, int r, ColorGame color);
	void SetImage();
	void SetPosition();
	Square GetPlaceCurrent();
	void SetSelectioin();
	void UnSelection();
	void GetPossibleMoveLocation(PieceBoard b[][8]);
	ColorGame GetColorPiece();
	void MoveNewPlace(int c, int r);
};
