//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma  once
#include "Piece.h"
class PieceSet// class chua 16 quan co
{
private:
	ColorGame PieceSetColor;// mau cac quan co
	Piece *kingPiece;
public:
	bool LosePiece;
	PieceSet();// khoi tao
	~PieceSet();// huy
	vector <Piece*> Pieces;// vector chua cac quan co
	vector<Piece*> EatPieces;// vector chua cac quan co an
	void CreatePieces(ColorGame PieceSetColor);// khoi tao cac quan co
	int GetNumberofPiece();// lay so luong quan co con
	void UnSelectionPiece();// bo trang thai chon cho tat ca quan co
	void ErasePiece();// xoa quan co
	void ErasePieceFollowNumber(int n);// xoa theo so 
	void ChangePawnPiece(Piece *p,std::string typePiece);// thay doi quan co, (thanh cap cho pawn)
	void UnSelectionEat();// bo trang thai an
	Piece *CpuSelectionPiece(int c, int r);// tra ve vi tri quan co, dung cho danh vs cpu
	int SearchPieceInVector(Piece *p);// tim kiem trong vector
	bool EnterWall(Piece *p,PieceBoard b[][8]);// nhap thanh cho vua
	ColorGame GetColorSet();// lay mau sac
	void LoseKing();
	Vector2i GetPossitionOfKing();// lay vi tri cua quan king 

};