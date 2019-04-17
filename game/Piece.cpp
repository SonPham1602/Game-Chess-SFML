#include "Piece.h"
King::King(int c, int r, ColorGame color)
{
	SelectionPiece=false;
	SelectionErasePiece=false;
	PlaceCurrent.ChangeSquare(c,r);
	PieceColor=color;
	SetImage();
}
Queen::Queen(int c, int r, ColorGame color)
{
	SelectionPiece=false;
	SelectionErasePiece=false;
	PlaceCurrent.ChangeSquare(c,r);
	PieceColor=color;
	SetImage();
}

Knight::Knight(int c, int r, ColorGame color)
{
	SelectionPiece=false;
	SelectionErasePiece=false;
	PlaceCurrent.ChangeSquare(c,r);
	PieceColor=color;
	SetImage();
}

Pawn::Pawn(int c, int r, ColorGame color)
{
	SelectionPiece=false;
	SelectionErasePiece=false;
	FirstMove=true;
	PlaceCurrent.ChangeSquare(c,r);
	PieceColor=color;
	SetImage();
}

Rook::Rook(int c, int r, ColorGame color)
{
	SelectionPiece=false;
	SelectionErasePiece=false;
	PlaceCurrent.ChangeSquare(c,r);
	PieceColor=color;
	SetImage();
}

Bishop::Bishop(int c, int r, ColorGame color)
{
	SelectionPiece=false;
	SelectionErasePiece=false;
	PlaceCurrent.ChangeSquare(c,r);
	PieceColor=color;
	SetImage();
}
void King::SetImage()
{

	if(PieceColor==ColorGame::White)
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/KingWhite.png");
	}
	else
	{
		cout<<"da mo file\n";
		TexturePiece.loadFromFile("images/chess_size1/pieces/KingBlack.png");
	}
	SpritePiece.setTexture(TexturePiece);
}
void Queen::SetImage()
{
	if(PieceColor==ColorGame::White)
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/QueenWhite.png");
	}
	else
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/QueenBlack.png");
	}
	SpritePiece.setTexture(TexturePiece);
}
void Knight::SetImage()
{
	if(PieceColor==ColorGame::White)
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/KnightWhite.png");
	}
	else
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/KnightBlack.png");
	}
	SpritePiece.setTexture(TexturePiece);
}
void Pawn::SetImage()
{
	if(PieceColor==ColorGame::White)
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/PawnWhite.png");
	}
	else
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/PawnBlack.png");
	}
	SpritePiece.setTexture(TexturePiece);
}

void Bishop::SetImage()
{
	if(PieceColor==ColorGame::White)
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/BishopWhite.png");
	}
	else
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/BishopBlack.png");
	}
	SpritePiece.setTexture(TexturePiece);
}

void Rook::SetImage()
{
	if(PieceColor==ColorGame::White)
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/RookWhite.png");
	}
	else
	{
		TexturePiece.loadFromFile("images/chess_size1/pieces/RookBlack.png");
	}
	SpritePiece.setTexture(TexturePiece);
}
void King::SetPosition()
{
	SpritePiece.setPosition(landMark +PlaceCurrent.GetColumn()*sizePiece,landMark +PlaceCurrent.GetRow()*sizePiece);
	//cout<<PlaceCurrent.GetColumn()*sizePiece<<":"<<PlaceCurrent.GetRow()*sizePiece<<endl;
}
void Queen::SetPosition()
{
	SpritePiece.setPosition(landMark +PlaceCurrent.GetColumn()*sizePiece,landMark +PlaceCurrent.GetRow()*sizePiece);

}

void Rook::SetPosition()
{
	SpritePiece.setPosition(landMark +PlaceCurrent.GetColumn()*sizePiece,landMark +PlaceCurrent.GetRow()*sizePiece);

}

void Bishop::SetPosition()
{
	SpritePiece.setPosition(landMark +PlaceCurrent.GetColumn()*sizePiece,landMark +PlaceCurrent.GetRow()*sizePiece);

}

void Pawn::SetPosition()
{
	SpritePiece.setPosition(landMark +PlaceCurrent.GetColumn()*sizePiece,landMark +PlaceCurrent.GetRow()*sizePiece);
}
void Knight::SetPosition()
{
	SpritePiece.setPosition(landMark +PlaceCurrent.GetColumn()*sizePiece,landMark +PlaceCurrent.GetRow()*sizePiece);
}
// CAC HAM LAY VI TRI HIEN TAI
Square King::GetPlaceCurrent()
{
	return PlaceCurrent;
}
Square Pawn::GetPlaceCurrent()
{
	return PlaceCurrent;
}
Square Queen::GetPlaceCurrent()
{
	return PlaceCurrent;
}
Square Rook::GetPlaceCurrent()
{
	return PlaceCurrent;
}
Square Bishop::GetPlaceCurrent()
{
	return PlaceCurrent;
}
Square Knight::GetPlaceCurrent()
{
	return PlaceCurrent;
}
// chon quan co
void King::SetSelectioin()
{
	SelectionPiece=true;
}
void Queen::SetSelectioin()
{
	SelectionPiece=true;
}
void Pawn::SetSelectioin()
{
	SelectionPiece=true;
}
void Knight::SetSelectioin()
{
	SelectionPiece=true;
}
void Rook::SetSelectioin()
{
	SelectionPiece=true;
}
void Bishop::SetSelectioin()
{
	SelectionPiece=true;
}
// bo chon quan co 
void King::UnSelection()
{
	SelectionPiece=false;
}
void Queen::UnSelection()
{
	SelectionPiece=false;
}
void Pawn::UnSelection()
{
	SelectionPiece=false;
}
void Knight::UnSelection()
{
	SelectionPiece=false;
}
void Rook::UnSelection()
{
	SelectionPiece=false;
}
void Bishop::UnSelection()
{
	SelectionPiece=false;
}
// lay vi tri co the di chuyen
void King::GetPossibleMoveLocation(PieceBoard b[][8])
{
	if(GetColorPiece()==ColorGame::White)
	{
		Vector2i temp(PlaceCurrent.GetColumn()-1,PlaceCurrent.GetRow()-1);
		if(temp.x>=0 && temp.y>=0)
		{
			for(int i=0;i<3;i++,temp.y++)
			{
				if(temp.y>=0 && temp.y<=widthBoard)
				{
					CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
				}
			}
		}
		temp=Vector2i(PlaceCurrent.GetColumn()+1,PlaceCurrent.GetRow()-1);
		if(temp.x<=lengthBoard && temp.y>=0)
		{
			for(int i=0;i<3;i++,temp.y++)
			{
				if(temp.y>=0 && temp.y<=widthBoard)
				{
					CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
				}
			}
		}
		temp=Vector2i(PlaceCurrent.GetColumn(),PlaceCurrent.GetRow()+1);
		if(temp.y<=lengthBoard)
		{
			CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
		}
		temp=Vector2i(PlaceCurrent.GetColumn(),PlaceCurrent.GetRow()-1);
		if(temp.y>=0)
		{
			CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
		}
	}
	else
	{
		Vector2i temp(PlaceCurrent.GetColumn()-1,PlaceCurrent.GetRow()+1);
		if(temp.x>=0 && temp.x<=lengthBoard)
		{
			for(int i=0;i<3;i++,temp.y--)
			{
				if(temp.y>=0 && temp.y<=widthBoard)
				{
					CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
				}
			}
		}
		temp=Vector2i(PlaceCurrent.GetColumn()+1,PlaceCurrent.GetRow()+1);
		if(temp.x>=0 && temp.x<=lengthBoard)
		{
			for(int i=0;i<3;i++,temp.y--)
			{
				if(temp.y>=0 && temp.y<=widthBoard)
				{
					CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
				}
			}
		}
		temp=Vector2i(PlaceCurrent.GetColumn(),PlaceCurrent.GetRow()+1);
		if(temp.y<=lengthBoard)
		{
			CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
		}
		temp=Vector2i(PlaceCurrent.GetColumn(),PlaceCurrent.GetRow()-1);
		if(temp.y>=0)
		{
			CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
		}
	}
}
void Queen::GetPossibleMoveLocation(PieceBoard b[][8])
{
	//x-1
	Vector2i temp(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow());
	while(temp.x>=0)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(-1,0);
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	//x+1
	temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow());
	while(temp.x<=lengthBoard)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(1,0); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	//y-1
	temp=Vector2i(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()-1);
	while(temp.y>=0)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(0,-1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	//y+1
	temp=Vector2i(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()+1);
	while(temp.y<=widthBoard)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(0,1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// x+1 ,y+1
	temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()+1);
	while(temp.y<=widthBoard && temp.x<=lengthBoard)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(1,1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// x-1,y-1
	temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()-1);
	while(temp.y>=0 && temp.x>=0)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(-1,-1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// x+1, y-1
	temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()-1);
	while(temp.y>=0 && temp.x<=lengthBoard)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(+1,-1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// x-1,y+1
	temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()+1);
	while(temp.y<=widthBoard && temp.x>=0)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(-1,+1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// ket thuc cac truong hop
}
void Pawn::GetPossibleMoveLocation(PieceBoard b[][8])
{
	if(GetColorPiece()==ColorGame::Black)
	{
		if(GetFirstMove()==true)
		{
			Vector2i temp(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()+1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EmptyPieceBoard)
			{
				AddPossibleMoveLocation(temp);
				temp=Vector2i(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()+2);
				if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EmptyPieceBoard)
				{
					AddPossibleMoveLocation(temp);
				}	
			}	
			temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()+1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EnemyPieceBoard && temp.x>=0)
			{
				AddPossibleMoveLocation(temp);
			}
			temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()+1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EnemyPieceBoard&& temp.x<=lengthBoard)
			{
				AddPossibleMoveLocation(temp);
			}
		}
		else
		{
			Vector2i temp(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()+1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EmptyPieceBoard)
			{
				AddPossibleMoveLocation(temp);
			}	
			temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()+1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EnemyPieceBoard && temp.x>=0)
			{
				AddPossibleMoveLocation(temp);
			}
			temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()+1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EnemyPieceBoard&& temp.x<=lengthBoard)
			{
				AddPossibleMoveLocation(temp);
			}
		}
	}
	else if(GetColorPiece()==ColorGame::White)
	{
		if(GetFirstMove()==true)
		{
			Vector2i temp(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()-1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EmptyPieceBoard)
			{
				AddPossibleMoveLocation(temp);
				temp=Vector2i(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()-2);
				if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EmptyPieceBoard)
				{
					AddPossibleMoveLocation(temp);
				}	
			}	
			temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()-1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EnemyPieceBoard)
			{
				AddPossibleMoveLocation(temp);
			}
			temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()-1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EnemyPieceBoard)
			{
				AddPossibleMoveLocation(temp);
			}
		}
		else
		{
			Vector2i temp(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()-1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EmptyPieceBoard)
			{
				AddPossibleMoveLocation(temp);
			}	
			temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()-1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EnemyPieceBoard)
			{
				AddPossibleMoveLocation(temp);
			}
			temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()-1);
			if(CheckPossibleMoveLocation(temp.x,temp.y,b,GetColorPiece())==PieceBoard::EnemyPieceBoard)
			{
				AddPossibleMoveLocation(temp);
			}
		}
	}
}
void Knight::GetPossibleMoveLocation(PieceBoard b[][8])
{
	// th1 x+1,y-2
	Vector2i temp(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()-2);
	if(temp.x<=lengthBoard && temp.y>=0)
	{
		CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
	}
	// th2 x+1 y+2
	 temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()+2);
	 if(temp.x<=lengthBoard && temp.y<=widthBoard)
	 {
		 CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
	 }
	// th3 x-1, y-2
	temp =Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()-2);
	if(temp.x>=0 && temp.y>=0)
	{
		CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
	}
	//th4 x-1,y+2
	temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()+2);
	if(temp.x>=0 && temp.y<=widthBoard)
	{
		CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
	}
	//th5 x+2,y+1
	temp=Vector2i(GetPlaceCurrent().GetColumn()+2,GetPlaceCurrent().GetRow()+1);
	if(temp.x<=lengthBoard && temp.y<=widthBoard)
	{
		CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
	}
	//th6 x+2,y-1
	temp=Vector2i(GetPlaceCurrent().GetColumn()+2,GetPlaceCurrent().GetRow()-1);
	if(temp.x<=lengthBoard && temp.y>=0)
	{
		CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
	}
	//th7 x-2,y+1
	temp=Vector2i(GetPlaceCurrent().GetColumn()-2,GetPlaceCurrent().GetRow()+1);
	if(temp.x>=0 && temp.y<=widthBoard)
	{
		CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
	}
	//th8 x-2,y-1
	temp=Vector2i(GetPlaceCurrent().GetColumn()-2,GetPlaceCurrent().GetRow()-1);
	if(temp.x>=0 && temp.y>=0)
	{
		CheckAndAddPossibleMoveLocation(temp.x,temp.y,b,PieceColor);
	}
	// ket thuc cac truong hop
}
void Rook::GetPossibleMoveLocation(PieceBoard b[][8])
{
	//x-1
	Vector2i temp(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow());
	while(temp.x>=0)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(-1,0);
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	//x+1
	temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow());
	while(temp.x<=widthBoard)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(1,0); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	//y-1
	temp=Vector2i(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()-1);
	while(temp.y>=0)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(0,-1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	//y+1
	temp=Vector2i(GetPlaceCurrent().GetColumn(),GetPlaceCurrent().GetRow()+1);
	while(temp.y<=widthBoard)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(0,1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
}
void Bishop::GetPossibleMoveLocation(PieceBoard b[][8])
{
	//x+1 ,y+1
	Vector2i temp(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()+1);
	while(temp.y<=widthBoard && temp.x<=lengthBoard)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(1,1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// x-1,y-1
	temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()-1);
	while(temp.y>=0 && temp.x>=0)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(-1,-1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// x+1, y-1
	temp=Vector2i(GetPlaceCurrent().GetColumn()+1,GetPlaceCurrent().GetRow()-1);
	while(temp.y>=0 && temp.x<=lengthBoard)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(+1,-1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// x-1,y+1
	temp=Vector2i(GetPlaceCurrent().GetColumn()-1,GetPlaceCurrent().GetRow()+1);
	while(temp.y<=widthBoard && temp.x>=0)
	{
		if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EmptyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			temp += Vector2i(-1,+1); 
		}
		else if(CheckPossibleMoveLocation(temp.x,temp.y,b,PieceColor)==PieceBoard::EnemyPieceBoard)
		{
			AddPossibleMoveLocation(temp);
			break;
		}
		else
		{
			break;
		}
	}
	// ket thuc
}
//color
ColorGame King::GetColorPiece()
{
	return PieceColor;
}
ColorGame Queen::GetColorPiece()
{
	return PieceColor;
}
ColorGame Pawn::GetColorPiece()
{
	return PieceColor;
}
ColorGame Knight::GetColorPiece()
{
	return PieceColor;
}
ColorGame Rook::GetColorPiece()
{
	return PieceColor;
}
ColorGame Bishop::GetColorPiece()
{
	return PieceColor;
}
void Piece::AddPossibleMoveLocation(Vector2i temp)
{
	PossibleLocation.push_back(temp);
}
bool Pawn::GetFirstMove()
{
	return FirstMove;
}
void Pawn::SetFirstMoveFalse()
{
	FirstMove=false;
}
PieceBoard Piece::CheckPossibleMoveLocation(int c, int r,PieceBoard b[][8],ColorGame color)
{
	if(color==ColorGame::Black)
	{
		if(b[c][r]==PieceBoard::EmptyPieceBoard)
		{
			return PieceBoard::EmptyPieceBoard;
		}
		else if(b[c][r]==PieceBoard::WhitePieceBoard)
		{
			return PieceBoard::EnemyPieceBoard;
		}
		else
		{
			return PieceBoard::SamePieceBoard;
		}
	}
	else
	{
		if (b[c][r]==PieceBoard::EmptyPieceBoard)
		{
			return PieceBoard::EmptyPieceBoard;
		}
		else if(b[c][r]==PieceBoard::BlackPieceBoard)
		{
			return PieceBoard::EnemyPieceBoard;
		}
		else
		{
			return PieceBoard::SamePieceBoard;
		}
	}
}
void Piece::OutPutConsolePossibleMoveLocation()
{
	for(int i=0;i<PossibleLocation.size();i++)
	{
		cout<<PossibleLocation[i].x<<" "<<PossibleLocation[i].y<<endl;
	}
}
void Piece::ClearPossibleMoveLocation()
{
	PossibleLocation.clear();
}
void Piece::CheckAndAddPossibleMoveLocation(int c, int r,PieceBoard b[][8],ColorGame color)
{
	if(CheckPossibleMoveLocation(c,r,b,color)==PieceBoard::EmptyPieceBoard ||CheckPossibleMoveLocation(c,r,b,color)==PieceBoard::EnemyPieceBoard)
	{
		AddPossibleMoveLocation(Vector2i(c,r));
	}
}
int Piece::GetSizePossibleMoveLocation()
{
	return PossibleLocation.size();
}
Vector2i Piece::GetPossibleMoveOfNumber(int i)
{
	return PossibleLocation[i];
}

int Piece::CheckInVectorMoveLocation(MouseGame *m)
{
	if(PossibleLocation.empty()==false)
	{
		for(int i=0;i<GetSizePossibleMoveLocation();i++)
		{
			if(m->CheckGetGlobalBoundsMouse(PossibleLocation[i]))
			{
				return i;
			}
		}
		return -1;
	}
	return -1;
}
void Piece::SetEat()
{
	SelectionErasePiece=true;
}
void Piece::UnSetEat()
{
	SelectionErasePiece=false;
}
// Di chuyem
void King::MoveNewPlace(int c, int r)
{
	PlaceCurrent.ChangeSquare(c,r);
}
void Queen::MoveNewPlace(int c, int r)
{
	PlaceCurrent.ChangeSquare(c,r);
}
void Pawn::MoveNewPlace(int c, int r)
{
	PlaceCurrent.ChangeSquare(c,r);
	SetFirstMoveFalse();
}
void Knight::MoveNewPlace(int c, int r)
{
	PlaceCurrent.ChangeSquare(c,r);
}
void Rook::MoveNewPlace(int c, int r)
{
	PlaceCurrent.ChangeSquare(c,r);
}
void Bishop::MoveNewPlace(int c, int r)
{
	PlaceCurrent.ChangeSquare(c,r);
}
bool Piece::CheckChangePiece()
{
	
		if(GetColorPiece()==ColorGame::Black)
		{
			if(GetPlaceCurrent().GetRow()==widthBoard)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if(GetColorPiece()==ColorGame::White)
		{
			if(GetPlaceCurrent().GetRow()==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	
}
void Piece::OutputPlaceCurrentConsole()
{
	cout<<"Vi tri hien tai: "<<GetPlaceCurrent().GetColumn()<<":"<<GetPlaceCurrent().GetRow()<<endl;
}
void Piece::ChangeLocationFileTexture(string l)
{
	TexturePiece.loadFromFile(l);
	SpritePiece.setTexture(TexturePiece);
}