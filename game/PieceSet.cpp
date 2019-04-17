
#include "PieceSet.h"
void PieceSet::CreatePieces(ColorGame PieceSetColor)
{
	Pieces.clear();
	if(PieceSetColor==ColorGame::Black)
	{
		for(int i=0;i<8;i++)
		{
			Piece *piece;
			piece=new Pawn(i,1,ColorGame::Black);
			Pieces.push_back(piece);
		}
		for(int i=0;i<2;i++)
		{
			Piece *piece;
			if(i==0)
			{
				piece=new Rook(0,0,ColorGame::Black);
			}
			else
			{
				piece=new Rook(7,0,ColorGame::Black);
			}
			Pieces.push_back(piece);
		}
		for(int i=0;i<2;i++)
		{
			Piece *piece;
			if(i==0)
			{
				piece=new Knight(1,0,ColorGame::Black);
			}
			else
			{
				piece=new Knight(6,0,ColorGame::Black);
			}
			Pieces.push_back(piece);
		}
		for(int i=0;i<2;i++)
		{
			Piece *piece;
			if(i==0)
			{
				piece=new Bishop(2,0,ColorGame::Black);
			}
			else
			{
				piece=new Bishop(5,0,ColorGame::Black);
			}
			Pieces.push_back(piece);
		}
		Piece *piece;
		piece=new King(4,0,ColorGame::Black);
		kingPiece=piece;
		Pieces.push_back(piece);
		piece=new Queen(3,0,ColorGame::Black);
		Pieces.push_back(piece);
	}
	else if(PieceSetColor==ColorGame::White)
	{
		for(int i=0;i<8;i++)
		{
			Piece *piece;
			piece=new Pawn(i,6,ColorGame::White);
			Pieces.push_back(piece);
		}
		for(int i=0;i<2;i++)
		{
			Piece *piece;
			if(i==0)
			{
				piece=new Rook(0,7,ColorGame::White);
			}
			else
			{
				piece=new Rook(7,7,ColorGame::White);
			}
			Pieces.push_back(piece);
		}
		for(int i=0;i<2;i++)
		{
			Piece *piece;
			if(i==0)
			{
				piece=new Knight(1,7,ColorGame::White);
			}
			else
			{
				piece=new Knight(6,7,ColorGame::White);
			}
			Pieces.push_back(piece);
		}
		for(int i=0;i<2;i++)
		{
			Piece *piece;
			if(i==0)
			{
				piece=new Bishop(2,7,ColorGame::White);
			}
			else
			{
				piece=new Bishop(5,7,ColorGame::White);
			}
			Pieces.push_back(piece);
		}
		Piece *piece;
		piece=new King(4,7,ColorGame::White);
		kingPiece=piece;
		Pieces.push_back(piece);
		piece=new Queen(3,7,ColorGame::White);
		Pieces.push_back(piece);
	}
	cout<<Pieces.size()<<endl;
}
PieceSet::PieceSet()
{
	LosePiece=false;
}
PieceSet::~PieceSet()
{
	for(int i=0;i<GetNumberofPiece();i++)
	{
		delete Pieces[i];
	}
}
int PieceSet::GetNumberofPiece()
{
	return Pieces.size();
}
void PieceSet::UnSelectionPiece()
{
	for(int i=0;i<GetNumberofPiece();i++)
	{
		Pieces[i]->UnSelection();
	}
}
void PieceSet::UnSelectionEat()
{
	for(int i=0;i<GetNumberofPiece();i++)
	{
		Pieces[i]->UnSetEat();
	}
}
void PieceSet::ErasePiece()
{
	for(int i=0;i<GetNumberofPiece();i++)
	{
		if(Pieces[i]->SelectionErasePiece==true)
		{
			if(typeid(*Pieces[i])==typeid(Pawn))
			{
				if(Pieces[i]->GetColorPiece()==ColorGame::Black)
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/PawnBlackSmall.png");
				else
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/PawnWhiteSmall.png");
			}
			else if(typeid(*Pieces[i])==typeid(Rook))
			{
				if(Pieces[i]->GetColorPiece()==ColorGame::Black)
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/RookBlackSmall.png");
				else
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/RookWhiteSmall.png");
			}
			else if(typeid(*Pieces[i])==typeid(Knight))
			{
				if(Pieces[i]->GetColorPiece()==ColorGame::Black)
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/KnightBlackSmall.png");
				else
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/KnightWhiteSmall.png");
			}
			else if(typeid(*Pieces[i])==typeid(Queen))
			{
				if(Pieces[i]->GetColorPiece()==ColorGame::Black)
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/QueenBlackSmall.png");
				else
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/QueenWhiteSmall.png");
			}
			else if(typeid(*Pieces[i])==typeid(Bishop))
			{
				if(Pieces[i]->GetColorPiece()==ColorGame::Black)
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/BishopBlackSmall.png");
				else
					Pieces[i]->ChangeLocationFileTexture("images/chess_size1/pieces/BishopWhiteSmall.png");
			}
			if(typeid(*Pieces[i])==typeid(King))
			{
				LoseKing();
			}
			EatPieces.push_back(Pieces[i]);
			Pieces.erase(Pieces.begin()+i);
		}
	}
}
void PieceSet::ErasePieceFollowNumber(int n)
{
	Pieces.erase(Pieces.begin()+n);
}
Piece * PieceSet::CpuSelectionPiece(int c, int r)
{
	for(int i=0;i<GetNumberofPiece();i++)
	{
		if(c==Pieces[i]->GetPlaceCurrent().GetColumn() && r== Pieces[i]->GetPlaceCurrent().GetRow())
		{
			return Pieces[i];
		}
	}
}
int PieceSet::SearchPieceInVector(Piece *p)
{
	for(int i=0;i<GetNumberofPiece();i++)
	{
		if(p->GetPlaceCurrent().GetColumn()==Pieces[i]->GetPlaceCurrent().GetColumn()
			&& p->GetPlaceCurrent().GetRow()==Pieces[i]->GetPlaceCurrent().GetRow())
		{
			return i;
		}
	}
	return -1;
}
void PieceSet::ChangePawnPiece(Piece *p,std::string typePiece)
{
	Piece *replacePiece;
	Vector2i posReplacePiece;
	int Check=SearchPieceInVector(p);
	if(p->CheckChangePiece()==true)
	{
		if(Check!=-1)
		{
			posReplacePiece=Vector2i(Pieces[Check]->GetPlaceCurrent().GetColumn(),Pieces[Check]->GetPlaceCurrent().GetRow());
			
			// viet ham them quan co nao;
			if(typePiece=="Knight")
			{
				if(Pieces[Check]->GetColorPiece()==ColorGame::Black)
				{
					replacePiece=new Knight(posReplacePiece.x,posReplacePiece.y,ColorGame::Black);
				}
				else
				{
					replacePiece=new Knight(posReplacePiece.x,posReplacePiece.y,ColorGame::White);
				}
				
			}
			else if(typePiece=="Bishop")
			{
				if(Pieces[Check]->GetColorPiece()==ColorGame::Black)
				{
					replacePiece=new Bishop(posReplacePiece.x,posReplacePiece.y,ColorGame::Black);
				}
				else
				{
					replacePiece=new Bishop(posReplacePiece.x,posReplacePiece.y,ColorGame::White);
				}
				
			}
			else if(typePiece=="Rook")
			{
				if(Pieces[Check]->GetColorPiece()==ColorGame::Black)
				{
					replacePiece=new Rook(posReplacePiece.x,posReplacePiece.y,ColorGame::Black);
				}
				else
				{
					replacePiece=new Rook(posReplacePiece.x,posReplacePiece.y,ColorGame::White);
				}
				
			}
			else if(typePiece=="Queen")
			{
				if(Pieces[Check]->GetColorPiece()==ColorGame::Black)
				{
					replacePiece=new Queen(posReplacePiece.x,posReplacePiece.y,ColorGame::Black);
				}
				else
				{
					replacePiece=new Queen(posReplacePiece.x,posReplacePiece.y,ColorGame::White);
				}
			}
			ErasePieceFollowNumber(Check);
			Pieces.push_back(replacePiece);
		}
	}
}
bool PieceSet::EnterWall(Piece *p,PieceBoard b[][8])
{
	int numbercheck=0;
	int check=0;
	if(p->GetColorPiece()==ColorGame::Black)
	{
		if(p->GetPlaceCurrent().GetColumn()==4 && p->GetPlaceCurrent().GetRow()==0)
		{
			if(typeid(*CpuSelectionPiece(0,0))==typeid(Rook))
			{
				for(int i=1;i<=3;i++)
				{
					if(b[i][0]==PieceBoard::EmptyPieceBoard)
					{
						numbercheck++;
					}
				}
			}
			
			if(numbercheck==3)
			{
				p->AddPossibleMoveLocation(Vector2i(0,0));
				check++;
			}
			numbercheck =0;
			if(typeid(*CpuSelectionPiece(7,0))==typeid(Rook))
			{
				for(int i=5;i<=6;i++)
				{
					if(b[i][0]==PieceBoard::EmptyPieceBoard)
					{
						numbercheck++;
					}
				}
			}
			if(numbercheck==2)
			{
				p->AddPossibleMoveLocation(Vector2i(7,0));
				check++;
			}
		}
	}
	else if(p->GetColorPiece()==ColorGame::White)
	{
		if(p->GetPlaceCurrent().GetColumn()==4 && p->GetPlaceCurrent().GetRow()==7)
		{
			if(typeid(*CpuSelectionPiece(0,7))==typeid(Rook))
			{
				for(int i=1;i<=3;i++)
				{
					if(b[i][7]==PieceBoard::EmptyPieceBoard)
					{
						numbercheck++;
					}
				}
			}
			if(numbercheck==3)
			{
				p->AddPossibleMoveLocation(Vector2i(0,7));
				check++;
			}
			numbercheck =0;
			if(typeid(*CpuSelectionPiece(7,7))==typeid(Rook))
			{
				for(int i=5;i<=6;i++)
				{
					if(b[i][7]==PieceBoard::EmptyPieceBoard)
					{
						numbercheck++;
					}
				}
			}
			if(numbercheck==2)
			{
				p->AddPossibleMoveLocation(Vector2i(7,7));
				check++;
			}
		}
	}
	if(check>0)
		return true;
	else 
		return false;
}
ColorGame PieceSet::GetColorSet()
{
	return PieceSetColor;
}
void PieceSet::LoseKing()
{
	LosePiece=true;
}
Vector2i PieceSet::GetPossitionOfKing()
{
	return Vector2i(kingPiece->GetPlaceCurrent().GetColumn(),kingPiece->GetPlaceCurrent().GetRow());
}
