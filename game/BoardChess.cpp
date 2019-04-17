#include "BoardChess.h"
const int sizeimage=90;
void BoardChess::CreateBoardChess()
{
	BlackPieces=new PieceSet;
	BlackPieces->CreatePieces(ColorGame::Black);
	WhitePieces=new PieceSet;
	WhitePieces->CreatePieces(ColorGame::White);
	SelectionPieceMove=NULL;
	SelectionPieceEat=NULL;
}
BoardChess::BoardChess()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(i==0 || i==1)
			{
				Board[j][i]=PieceBoard::BlackPieceBoard;
			}
			else if(i==6 || i==7)
			{
				Board[j][i]=PieceBoard::WhitePieceBoard;
			}
			else
			{
				Board[j][i]=PieceBoard::EmptyPieceBoard;
			}
		}
	}
}
BoardChess::~BoardChess()
{
	delete WhitePieces;
	delete BlackPieces;
	
}
void BoardChess::UpdataBoardChess()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			Board[j][i]=PieceBoard::EmptyPieceBoard;
		}
	}
	for(int i=0;i<BlackPieces->GetNumberofPiece();i++)
	{
		Board[BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn()][BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow()]=PieceBoard::BlackPieceBoard;
	}
	for(int i=0;i<WhitePieces->GetNumberofPiece();i++)
	{
		Board[WhitePieces->Pieces[i]->GetPlaceCurrent().GetColumn()][WhitePieces->Pieces[i]->GetPlaceCurrent().GetRow()]=PieceBoard::WhitePieceBoard;
	}
	
}
void BoardChess::ShowConsole()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(Board[j][i]==PieceBoard::BlackPieceBoard)
			{
				cout<<"B ";
			}
			else if(Board[j][i]==PieceBoard::WhitePieceBoard)
			{
				cout<<"W ";
			}
			else
			{
				cout<<"E ";
			}
		}
		cout<<"\n";
	}
}
PieceBoard BoardChess::GetPieceBoard(int c, int r)
{
	return Board[c][r];
}
void BoardChess::SetImageBoard(std::string l,std::string b,std::string w,std::string s)
{
	textureBoard.loadFromFile(l);
	spriteBoard.setTexture(textureBoard);
	t_SelBlack.loadFromFile(b);
	s_SelBlack.setTexture(t_SelBlack);
	t_SelWhite.loadFromFile(w);
	s_SelWhite.setTexture(t_SelWhite);
	t_PossibleMove.loadFromFile(s);
	s_PossibleMove.setTexture(t_PossibleMove);
}
void BoardChess::DrawBoard(WindowGame *w)
{
	spriteBoard.setPosition(landMark,landMark );
	w->Draw(spriteBoard);
}
sf::Vector2u BoardChess::GetSizeImageBoard()
{
	return textureBoard.getSize();
}
PieceBoard BoardChess::ColorOfSquare(int c, int r)
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(i==r && j==c)
			{
				if((j%2==0 && i%2==0)||(j%2!=0 && i%2!=0))
				{
					return PieceBoard::WhitePieceBoard;
				}
				else
				{
					return PieceBoard::BlackPieceBoard;
				}
			}
		
		}
	}
}
void BoardChess::DrawSelectionPiece(WindowGame*w)
{
	for(int i=0;i<BlackPieces->GetNumberofPiece();i++)
	{
		if(BlackPieces->Pieces[i]->SelectionPiece==true)
		{
			if(ColorOfSquare(BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn(),BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow())==PieceBoard::WhitePieceBoard)
			{
				s_SelWhite.setPosition(landMark +sizeimage*BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn(),landMark +sizeimage*BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow());
				w->Draw(s_SelWhite);
			}
			else
			{
				s_SelBlack.setPosition(landMark +sizeimage*BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn(),landMark +sizeimage*BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow());
				w->Draw(s_SelBlack);
			}
		}
	}
	for(int i=0;i<WhitePieces->GetNumberofPiece();i++)
	{
		if(WhitePieces->Pieces[i]->SelectionPiece==true)
		{
			if(ColorOfSquare(WhitePieces->Pieces[i]->GetPlaceCurrent().GetColumn(),WhitePieces->Pieces[i]->GetPlaceCurrent().GetRow())==PieceBoard::WhitePieceBoard)
			{
				s_SelWhite.setPosition(landMark +sizeimage*WhitePieces->Pieces[i]->GetPlaceCurrent().GetColumn(),landMark +sizeimage*WhitePieces->Pieces[i]->GetPlaceCurrent().GetRow());
				w->Draw(s_SelWhite);
			}
			else
			{
				s_SelBlack.setPosition(landMark +sizeimage*WhitePieces->Pieces[i]->GetPlaceCurrent().GetColumn(),landMark +sizeimage*WhitePieces->Pieces[i]->GetPlaceCurrent().GetRow());
				w->Draw(s_SelBlack);
			}
		}
	}
}
void BoardChess::SetSelectionPiece(Piece *p)
{
	SelectionPieceMove=p;
}
void BoardChess::SetEatPiece(Piece *p)
{
	SelectionPieceEat=p;
	SelectionPieceEat->SetEat();
}
void BoardChess::ShowPossibleMove(Piece *p,WindowGame *w,bool check)
{
	if(check==true)
	{
		for(int i=0;i<p->GetSizePossibleMoveLocation();i++)
		{
			s_PossibleMove.setPosition(Vector2f(landMark +p->GetPossibleMoveOfNumber(i).x*sizeimage,landMark +p->GetPossibleMoveOfNumber(i).y*sizeimage));
			w->Draw(s_PossibleMove);
		}
	}

}
Piece*BoardChess::GetSelectionPieceMove()
{
	return SelectionPieceMove;
}
Piece*BoardChess::GetSelectionPieceEat()
{
	return SelectionPieceEat;
}
void BoardChess::MovePieceToNewPlace(Piece * p,int c,int r)
{
	p->MoveNewPlace(c,r);
}
void BoardChess::DrawPieceEat(WindowGame *w)
{
	for(int i=0;i<BlackPieces->EatPieces.size();i++)
	{
		if(i>=8)
		{
			BlackPieces->EatPieces[i]->SpritePiece.setPosition(775+45,768-45*(i-8)-45-24);
		}
		else
		{
			BlackPieces->EatPieces[i]->SpritePiece.setPosition(775,768-45*i-45-24);
		}
		
		w->Draw(BlackPieces->EatPieces[i]->SpritePiece);
		
	}
	for(int i=0;i<WhitePieces->EatPieces.size();i++)
	{
		if(i>=8)
		{
			WhitePieces->EatPieces[i]->SpritePiece.setPosition(775+45,(i-8)*45+24);
		}
		else
		{
				WhitePieces->EatPieces[i]->SpritePiece.setPosition(775,45*i+24);
		}
	
		w->Draw(WhitePieces->EatPieces[i]->SpritePiece);
	}
	
}
ColorGame BoardChess::PieceWin()
{
	CheckMate();
	if(BlackPieces->LosePiece==true)
		return ColorGame::White;
	else if(WhitePieces->LosePiece==true)
		return ColorGame::Black;
}
void BoardChess::CheckMate()
{
	for(int i=0;i<WhitePieces->GetNumberofPiece();i++)
	{
		for(int j=0;j<WhitePieces->Pieces[i]->GetSizePossibleMoveLocation();j++)
		{
			if(WhitePieces->Pieces[i]->GetPossibleMoveOfNumber(j)==BlackPieces->GetPossitionOfKing())
			{
				
				cout<<"trang dang bi chieu\n";
			}
		}
		
	}
	for(int i=0;i<BlackPieces->GetNumberofPiece();i++)
	{
		for(int j=0;j<BlackPieces->Pieces[i]->GetSizePossibleMoveLocation();j++)
		{
			if(BlackPieces->Pieces[i]->GetPossibleMoveOfNumber(j)==WhitePieces->GetPossitionOfKing())
			{
				cout<<"den dang bi chieu\n";
			
			}
		}

	}
}