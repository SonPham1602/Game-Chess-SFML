//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma  once
#include <SFML/Graphics.hpp>
#include "PieceSet.h"
#include "WindowGame.h"
#include <string>
class BoardChess// class ban co vua
{
private:
	Texture textureBoard;// hinh ban co
	Sprite spriteBoard;// hinh ban co
	Texture t_SelBlack;// hinh chon quan co
	Sprite s_SelBlack;// hinh chon quan co
	Texture t_SelWhite;// hinh chon quan co
	Sprite s_SelWhite;//hinh chon quan co
	PieceBoard ColorOfSquare(int c, int r);// tra ve mau sac theo vi tri ban co
	Piece *SelectionPieceMove;// quan co dc chon
	Piece *SelectionPieceEat;// quan co sap an
	Sprite s_PossibleMove;// hinh vi tri di duoc
	Texture t_PossibleMove;// hinh vi tri di duoc
	Vector2i PosOfBoard;// vi tri ban co
public:
	PieceBoard Board[8][8];// mang 2 chieu ban co 
	BoardChess();// khoi tao ban co
	~BoardChess();// huy ban co
	PieceSet *WhitePieces;// con tro quan trang
	PieceSet *BlackPieces;// con tro quan den
	void CreateBoardChess();// tao ban co
	void UpdataBoardChess();// up data ban co
	void ShowConsole();// hien thi ra console
	PieceBoard GetPieceBoard(int c, int r);//tra trang thai white or black or empty
	void SetImageBoard(std::string l,std::string b,std::string w,std::string s);// khoi tao hinh anh 
	void DrawBoard(WindowGame *w);// ve ban co  
	sf::Vector2u GetSizeImageBoard();// lay kich thuoc anh ban co
	void DrawSelectionPiece(WindowGame *w);// ve quan co duoc chon
	void SetSelectionPiece(Piece *p);// cai dat quan dc chon vao con tro
	void SetEatPiece(Piece *p);// cai dat quan co  an vao con tro
	void ShowPossibleMove(Piece *p,WindowGame *w,bool check);// hien thi nhung vi tri co the di 
	Piece *GetSelectionPieceMove();// lay gia tri con tro 
	Piece *GetSelectionPieceEat();// lay gia tri con tro
	void MovePieceToNewPlace(Piece * p,int c,int r);// di chuyen quan co
	void DrawPieceEat(WindowGame *w);// ve quan co da an dc
	ColorGame PieceWin();//
	void CheckMate();
};