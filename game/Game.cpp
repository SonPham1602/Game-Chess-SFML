#include "Game.h"
Game::Game()
{
	IntGame();
}
void Game::IntGame()
{
	movesBlack="";
	movesWhite="";
	DrawSpriteInGame=false;
	musicInGame.SetMusic("musics/musicMain.ogg");
	boardChess.SetImageBoard("images/chess_size1/BoardChess.png","images/chess_size1/SelectionPiece.png","images/chess_size1/SelectionPiece.png","images/chess_size1/Selection.png");
	boardChess.CreateBoardChess();
	mouseGame.SetLocation("images/mouse/mouse1.png");
	soundGame.SetSoundBuffer("musics/SoundChess1.wav");
	clickGame.SetSoundBuffer("musics/ClickChess2.wav");
	clickButton.SetSoundBuffer("musics/ClickChess.wav");
	IntImageBackground("images/chess_size1/BackGround4.png");
	t_MenuGame.loadFromFile("images/chess_size1/menugame.png");
	s_MenuGame.setTexture(t_MenuGame);
	t_ChangePawnBlack.loadFromFile("images/chess_size1/changepawnblack.png");
	t_ChangePawnWhite.loadFromFile("images/chess_size1/changepawnwhite.png");
	s_ChangePawnBlack.setTexture(t_ChangePawnBlack);
	s_ChangePawnWhite.setTexture(t_ChangePawnWhite);
	IntIconInGame();
	turnPlayer=TurnPlayer::P1Play;
	colorOfPlayer=ColorGame::White;
	stateDrawIcon=TypeIcon::NoDraw;
	stateChooseIcon=TypeIcon::NoWaitChoose;
	stateGame=StateMenu::WAIT;
	changePawn=TypeIcon::NoChangePawn;
	position="";
	enterWall=false;
}
void Game::CreateGame1()
{
	musicInGame.Play();
	musicInGame.SetRepeat();
	musicInGame.ChangeVolume(volumeGame.Music);
	clickGame.ChangeVolumeSound(volumeGame.Music);
	soundGame.ChangeVolumeSound(volumeGame.Sound);
	clickButton.ChangeVolumeSound(volumeGame.Music);
	windowGame.SetUp("Chess",GetSizeBackGround());
	sf::Image icon;
	icon.loadFromFile("images/icon/icon.png");
	windowGame.GetWindowGame()->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	Clock clock;
	double timer=0, delay=0.3;
	mouseGame.SetImage();
	boardChess.ShowConsole();
	windowGame.GetWindowGame()->setFramerateLimit(60);
	while(windowGame.IsDone())
	{
		//mouseGame.OutPutPosOfMouseInConsole();
		float time = clock.getElapsedTime().asSeconds();
		eventInputGame.SetWindow(&windowGame);
		eventInputGame.CheckEvent();
		windowGame.BeginDraw();
		windowGame.Draw(s_Background);
		boardChess.DrawBoard(&windowGame);
		// ve cac quan co
		for(int i=0;i<boardChess.BlackPieces->GetNumberofPiece();i++)// viet lai ham get size
		{
			boardChess.BlackPieces->Pieces[i]->SetPosition();
			windowGame.Draw(boardChess.BlackPieces->Pieces[i]->SpritePiece);

		}
		for(int i=0;i<boardChess.WhitePieces->GetNumberofPiece();i++)
		{
			boardChess.WhitePieces->Pieces[i]->SetPosition();
			windowGame.Draw(boardChess.WhitePieces->Pieces[i]->SpritePiece);

		}// ket thuc ve cac quan co
		if(stateChooseIcon==TypeIcon::NoWaitChoose)
		{
			SelectionPieceP1VsP2();
			if(DrawSpriteInGame==true)
			{
				SelectionMovePlace();
				boardChess.CheckMate();// coi lai vi tri 
				// kiem tra chieu truong
				if(typeid(*boardChess.GetSelectionPieceMove())==typeid(Pawn))
				{
					if(boardChess.GetSelectionPieceMove()->CheckChangePiece()==true)
					{
						changePawn=TypeIcon::ChangePawn;
					}
				}
				else if(typeid(*boardChess.GetSelectionPieceMove())==typeid(King))
				{

					if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
					{
						if(boardChess.BlackPieces->EnterWall(boardChess.GetSelectionPieceMove(),boardChess.Board))
						{
							enterWall=true;
						}
					}
					else if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::White)
					{
						if(boardChess.WhitePieces->EnterWall(boardChess.GetSelectionPieceMove(),boardChess.Board))
						{
							enterWall=true;
						}
					}
				}
			}
		}
		if(changePawn==TypeIcon::ChangePawn)
		{
			stateChooseIcon=TypeIcon::WaitChoose;
			DrawChooseChangePawn();
			if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(345,365),90,90))
			{
				mouseGame.ChangeImage("images/mouse/mouse2.png");
				if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					clickButton.Play();
					if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
					{
						boardChess.BlackPieces->ChangePawnPiece(boardChess.GetSelectionPieceMove(),"Rook");
					}
					else
					{
						boardChess.WhitePieces->ChangePawnPiece(boardChess.GetSelectionPieceMove(),"Rook");
					}
					changePawn=TypeIcon::NoChangePawn;
				}

			}
			else if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(435,365),90,90))
			{
				mouseGame.ChangeImage("images/mouse/mouse2.png");
				if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					clickButton.Play();
					if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
					{
						boardChess.BlackPieces->ChangePawnPiece(boardChess.GetSelectionPieceMove(),"Knight");
					}
					else
					{
						boardChess.WhitePieces->ChangePawnPiece(boardChess.GetSelectionPieceMove(),"Knight");
					}
					changePawn=TypeIcon::NoChangePawn;
				}

			}
			else if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(525,365),90,90))
			{
				mouseGame.ChangeImage("images/mouse/mouse2.png");
				if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					clickButton.Play();
					if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
					{
						boardChess.BlackPieces->ChangePawnPiece(boardChess.GetSelectionPieceMove(),"Queen");
					}
					else
					{
						boardChess.WhitePieces->ChangePawnPiece(boardChess.GetSelectionPieceMove(),"Queen");
					}
					changePawn=TypeIcon::NoChangePawn;
				}

			}
			else if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(615,365),90,90))
			{
				mouseGame.ChangeImage("images/mouse/mouse2.png");
				if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					clickButton.Play();
					if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
					{
						boardChess.BlackPieces->ChangePawnPiece(boardChess.GetSelectionPieceMove(),"Bishop");
					}
					else
					{
						boardChess.WhitePieces->ChangePawnPiece(boardChess.GetSelectionPieceMove(),"Bishop");
					}
					changePawn=TypeIcon::NoChangePawn;
				}

			}
			else
			{
				mouseGame.ChangeImage("images/mouse/mouse1.png");
			}
			stateChooseIcon=TypeIcon::NoWaitChoose;

		}
		//WinOrLose();
		DrawIconInGame();
		DrawTurnPlayer();
		OutPutMenuGame();
		boardChess.DrawPieceEat(&windowGame);
		boardChess.UpdataBoardChess();
		mouseGame.GetPositionOfMouse(*windowGame.GetWindowGame());
		mouseGame.DrawMouse(*windowGame.GetWindowGame());
		windowGame.EndDraw();
	}
}
void Game::CreateGame2()
{
	
		musicInGame.Play();
		musicInGame.SetRepeat();
		musicInGame.ChangeVolume(30);
		boardChess.CreateBoardChess();
		clickGame.ChangeVolumeSound(30);
		soundGame.ChangeVolumeSound(50);
		windowGame.SetUp("Chess",GetSizeBackGround());
		sf::Image icon;
		icon.loadFromFile("images/icon/icon.png");
		windowGame.GetWindowGame()->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		Clock clock;
		double timer=0, delay=0.3;
		mouseGame.SetImage();
		boardChess.ShowConsole();
		while(windowGame.IsDone())
		{
			windowGame.GetWindowGame()->setFramerateLimit(60);
			float time = clock.getElapsedTime().asSeconds();
			eventInputGame.SetWindow(&windowGame);
			eventInputGame.CheckEvent();
			windowGame.BeginDraw();
			windowGame.Draw(s_Background);
			boardChess.DrawBoard(&windowGame);
			for(int i=0;i<boardChess.BlackPieces->GetNumberofPiece();i++)// viet lai ham get size
			{
				boardChess.BlackPieces->Pieces[i]->SetPosition();
				windowGame.Draw(boardChess.BlackPieces->Pieces[i]->SpritePiece);

			}
			for(int i=0;i<boardChess.WhitePieces->GetNumberofPiece();i++)
			{
				boardChess.WhitePieces->Pieces[i]->SetPosition();
				windowGame.Draw(boardChess.WhitePieces->Pieces[i]->SpritePiece);

			}
			SelectionPieceP1vsCpu(colorOfPlayer);
			if(DrawSpriteInGame==true)
			{
				SelectionMovePlace();
			}
			DrawIconInGame();
			DrawTurnPlayer();
			OutPutMenuGame();
			boardChess.DrawPieceEat(&windowGame);
			boardChess.UpdataBoardChess();
			mouseGame.GetPositionOfMouse(*windowGame.GetWindowGame());
			mouseGame.DrawMouse(*windowGame.GetWindowGame());
			windowGame.EndDraw();
		}
}
WindowGame *Game::GetWindowGame()
{
	return &windowGame;
}

void Game::HandleInput()
{
	StateMenu temp=menuGame.InitiationMenu();
	if(temp==StateMenu::EXIT_GAME)
	{
		stateGame=StateMenu::EXIT_GAME;
	}
	else if(temp==StateMenu::PLAY_GAME)
	{
		stateGame=StateMenu::PLAY_GAME;
		modeGame=menuGame.GetModeGame();
		menuGame.SetVolumeGame(volumeGame);
		if(modeGame==ModeGame::P1vsP2)
		{
			CreateGame1();
		}
		if(modeGame==ModeGame::PvsCPU)
		{
			CreateGame2();
		}
		

	}
	else if(temp==StateMenu::OPTION_GAME)
	{
	
		
	}
}
void Game::SelectionPieceP1VsP2()
{
	if( turnPlayer==TurnPlayer::P2Play)
		for(int i=0;i<boardChess.BlackPieces->GetNumberofPiece();i++)
		{
			if(mouseGame.CheckGetGlobalBoundsMouse(boardChess.BlackPieces->Pieces[i]->SpritePiece))
			{
				boardChess.WhitePieces->UnSelectionPiece();
				boardChess.BlackPieces->UnSelectionPiece();
				boardChess.BlackPieces->Pieces[i]->SetSelectioin();
				boardChess.DrawSelectionPiece(&windowGame);
				if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					
					clickGame.Play();
					DrawSpriteInGame=true;
					boardChess.SetSelectionPiece(boardChess.BlackPieces->Pieces[i]);
					//cout<<"Black  ";
					boardChess.BlackPieces->Pieces[i]->ClearPossibleMoveLocation();
					boardChess.BlackPieces->Pieces[i]->GetPossibleMoveLocation(boardChess.Board);
					boardChess.BlackPieces->Pieces[i]->OutPutConsolePossibleMoveLocation();
					//cout<<"vi tri hien tai :"<<boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn()<<" ";
					cout<<boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow()<<endl;
					//boardChess.ShowConsole();
				}
			}
		}
		if(turnPlayer==TurnPlayer::P1Play)
			for(int i=0;i<boardChess.WhitePieces->GetNumberofPiece();i++)
			{
				if(mouseGame.CheckGetGlobalBoundsMouse(boardChess.WhitePieces->Pieces[i]->SpritePiece))
				{

					boardChess.BlackPieces->UnSelectionPiece();
					boardChess.WhitePieces->UnSelectionPiece();
					boardChess.WhitePieces->Pieces[i]->SetSelectioin();
					boardChess.DrawSelectionPiece(&windowGame);
					if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
					{
						clickGame.Play();
						DrawSpriteInGame=true;
						//cout<<"White  ";
						boardChess.SetSelectionPiece(boardChess.WhitePieces->Pieces[i]);
						//cout<<"vi tri hien tai :"<<boardChess.WhitePieces->Pieces[i]->GetPlaceCurrent().GetColumn()<<" ";
						cout<<boardChess.WhitePieces->Pieces[i]->GetPlaceCurrent().GetRow()<<endl;
						boardChess.WhitePieces->Pieces[i]->ClearPossibleMoveLocation();
						boardChess.WhitePieces->Pieces[i]->GetPossibleMoveLocation(boardChess.Board);
						boardChess.WhitePieces->Pieces[i]->OutPutConsolePossibleMoveLocation();
						//boardChess.ShowConsole();
					}
				}

			}
			boardChess.ShowPossibleMove(boardChess.GetSelectionPieceMove(),&windowGame,DrawSpriteInGame);
			if(DrawSpriteInGame==true )
			{
				boardChess.DrawSelectionPiece(&windowGame);
			}
			/*for(int i=0;i<boardChess.BlackPieces->GetNumberofPiece();i++)
			{
			if(boardChess.BlackPieces->Pieces[i]->SelectionPiece==true)
			{
			Texture t_choosePiece;
			t_choosePiece.loadFromFile("images/chess_size1/SelectionPiece2.png");
			Sprite s_choosePiece;
			s_choosePiece.setTexture(t_choosePiece);
			s_choosePiece.setPosition(Vector2f(boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn()*90+24,boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow()*90+24));
			windowGame.Draw(s_choosePiece);
			}
			}*/
			
}
void Game::SelectionMovePlace()
{
	string result;
	int check=boardChess.GetSelectionPieceMove()->CheckInVectorMoveLocation(&mouseGame);
	if(check!=-1)
	{
		OldPos=Vector2i(boardChess.GetSelectionPieceMove()->GetPlaceCurrent().GetColumn(),boardChess.GetSelectionPieceMove()->GetPlaceCurrent().GetRow());
		if(enterWall==true)
		{
			if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
			{
				if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(0,0)))
				{
					if(eventInputGame.typeInputMouse==TypeInPut::RIGHT_MOUSE)
					{
						soundGame.Play();
						boardChess.GetSelectionPieceMove()->MoveNewPlace(2,0);
						boardChess.BlackPieces->Pieces[boardChess.BlackPieces->SearchPieceInVector(boardChess.BlackPieces->CpuSelectionPiece(0,0))]->MoveNewPlace(3,0);
						DrawSpriteInGame=false;
						enterWall=false;
					}
				}
				else if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(7,0)))
				{

					if(eventInputGame.typeInputMouse==TypeInPut::RIGHT_MOUSE)
					{

						soundGame.Play();
						boardChess.GetSelectionPieceMove()->MoveNewPlace(6,0);
						boardChess.BlackPieces->Pieces[boardChess.BlackPieces->SearchPieceInVector(boardChess.BlackPieces->CpuSelectionPiece(7,0))]->MoveNewPlace(5,0);
						DrawSpriteInGame=false;
						enterWall=false;
					}
				}
			}
			else if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::White)
			{
				if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(0,7)))
				{
					if(eventInputGame.typeInputMouse==TypeInPut::RIGHT_MOUSE)
					{
						soundGame.Play();
						boardChess.GetSelectionPieceMove()->MoveNewPlace(2,7);
						boardChess.WhitePieces->Pieces[boardChess.WhitePieces->SearchPieceInVector(boardChess.WhitePieces->CpuSelectionPiece(0,7))]->MoveNewPlace(3,7);
						DrawSpriteInGame=false;
						enterWall=false;
					}
				}
				else if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(7,7)))
				{
					if(eventInputGame.typeInputMouse==TypeInPut::RIGHT_MOUSE)
					{
						soundGame.Play();
						boardChess.GetSelectionPieceMove()->MoveNewPlace(6,7);
						boardChess.WhitePieces->Pieces[boardChess.WhitePieces->SearchPieceInVector(boardChess.WhitePieces->CpuSelectionPiece(7,7))]->MoveNewPlace(5,7);
						DrawSpriteInGame=false;
						enterWall=false;
					}
				}
			}
			if(modeGame==ModeGame::P1vsP2 && enterWall ==false)
			{
				if(turnPlayer==TurnPlayer::P1Play)
				{
					turnPlayer=TurnPlayer::P2Play;
				}
				else
				{
					turnPlayer=TurnPlayer::P1Play;
				}
			}

		}
		else if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE && enterWall ==false)
		{
			
			DrawSpriteInGame=false;
			if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
			{
				for(int i=0;i<boardChess.WhitePieces->GetNumberofPiece();i++)
				{
					if(boardChess.WhitePieces->Pieces[i]->GetPlaceCurrent().GetColumn()==boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).x &&
						boardChess.WhitePieces->Pieces[i]->GetPlaceCurrent().GetRow()==boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).y)
					{
						boardChess.WhitePieces->UnSelectionEat();
						boardChess.SetEatPiece(boardChess.WhitePieces->Pieces[i]);
						boardChess.WhitePieces->ErasePiece();
					}
				}


			}
			if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::White)
			{
				for(int i=0;i<boardChess.BlackPieces->GetNumberofPiece();i++)
				{
					if(boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn()==boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).x &&
						boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow()==boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).y)
					{
						boardChess.BlackPieces->UnSelectionEat();
						boardChess.SetEatPiece(boardChess.BlackPieces->Pieces[i]);
						boardChess.BlackPieces->ErasePiece();
					}
				}
			}
			// animation di chuyen
			AnimationPieceMove(boardChess.GetSelectionPieceMove(),Vector2f(boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).x*90+24,boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).y*90+24),Vector2f(boardChess.GetSelectionPieceMove()->GetPlaceCurrent().GetColumn()*90+24,boardChess.GetSelectionPieceMove()->GetPlaceCurrent().GetRow()*90+24));
			soundGame.Play();
			boardChess.GetSelectionPieceMove()->MoveNewPlace(boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).x,boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).y);
			// cho quan trong 
			boardChess.GetSelectionPieceMove()->GetPossibleMoveLocation(boardChess.Board);
			
			cout<<boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).x<<"  "<<boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).y<<endl;
			if(modeGame==ModeGame::P1vsP2)
			{
				if(turnPlayer==TurnPlayer::P1Play)
				{
					turnPlayer=TurnPlayer::P2Play;
				}
				else
				{
					turnPlayer=TurnPlayer::P1Play;
				}
			}
			else
			{
				NewPos=Vector2i(boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).x,boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).y);
				cout<<"Cu:"<<OldPos.x<<":"<<OldPos.y<<endl;
				cout<<"Moi:"<<NewPos.x<<":"<<NewPos.y<<endl;
				position+=GetStringMove(OldPos)+GetStringMove(NewPos)+" ";
				result=cpuPlayer.getNextMove(position);
				OldPos=toCoord(result[0],result[1]);
				cout<<OldPos.x<<":"<<OldPos.y<<endl;
				NewPos=toCoord(result[2],result[3]);
				cout<<NewPos.x<<":"<<NewPos.y<<endl;
				if(colorOfPlayer==ColorGame::White)
				{
					boardChess.SetSelectionPiece(boardChess.BlackPieces->CpuSelectionPiece(OldPos.x,OldPos.y));
				if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
					{
						for(int i=0;i<boardChess.WhitePieces->GetNumberofPiece();i++)
						{
							if(boardChess.WhitePieces->Pieces[i]->GetPlaceCurrent().GetColumn()==NewPos.x &&
								boardChess.WhitePieces->Pieces[i]->GetPlaceCurrent().GetRow()==NewPos.y)
							{
								boardChess.WhitePieces->UnSelectionEat();
								boardChess.SetEatPiece(boardChess.WhitePieces->Pieces[i]);
								boardChess.WhitePieces->ErasePiece();
							}
						}
					}
					/*if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::White)
					{
					for(int i=0;i<boardChess.BlackPieces->GetNumberofPiece();i++)
					{
					if(boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn()==boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).x &&
					boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow()==boardChess.GetSelectionPieceMove()->GetPossibleMoveOfNumber(check).y)
					{
					cout<<"da an quan trang\n";
					boardChess.BlackPieces->UnSelectionEat();
					boardChess.SetEatPiece(boardChess.BlackPieces->Pieces[i]);
					boardChess.BlackPieces->ErasePiece();
					}
					}
					}*/
					AnimationPieceMove(boardChess.GetSelectionPieceMove(),Vector2f (NewPos.x*90+24,NewPos.y*90+24),Vector2f (OldPos.x*90+24,OldPos.y*90+24));
					soundGame.Play();
					boardChess.GetSelectionPieceMove()->MoveNewPlace(NewPos.x,NewPos.y);
				}
				position+=result+" ";
			}
		}
	}
}
void Game::SelectionPieceP1vsCpu(ColorGame c)
{
	if( c==ColorGame::Black)
	{
		for(int i=0;i<boardChess.BlackPieces->GetNumberofPiece();i++)
		{
			if(mouseGame.CheckGetGlobalBoundsMouse(boardChess.BlackPieces->Pieces[i]->SpritePiece))
			{
				boardChess.WhitePieces->UnSelectionPiece();
				boardChess.BlackPieces->UnSelectionPiece();
				boardChess.BlackPieces->Pieces[i]->SetSelectioin();
				boardChess.DrawSelectionPiece(&windowGame);
				if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					clickGame.Play();
					DrawSpriteInGame=true;
					boardChess.SetSelectionPiece(boardChess.BlackPieces->Pieces[i]);
					boardChess.BlackPieces->Pieces[i]->ClearPossibleMoveLocation();
					boardChess.BlackPieces->Pieces[i]->GetPossibleMoveLocation(boardChess.Board);
					boardChess.BlackPieces->Pieces[i]->OutPutConsolePossibleMoveLocation();
					cout<<boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetColumn()<<" ";
					cout<<boardChess.BlackPieces->Pieces[i]->GetPlaceCurrent().GetRow()<<endl;
					boardChess.ShowConsole();
				}

			}
		}
	}
	else if(c==ColorGame::White)
	{
		for(int i=0;i<boardChess.WhitePieces->GetNumberofPiece();i++)
		{
			if(mouseGame.CheckGetGlobalBoundsMouse(boardChess.WhitePieces->Pieces[i]->SpritePiece))
			{
				boardChess.BlackPieces->UnSelectionPiece();
				boardChess.WhitePieces->UnSelectionPiece();
				boardChess.WhitePieces->Pieces[i]->SetSelectioin();
				boardChess.DrawSelectionPiece(&windowGame);
				if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					clickGame.Play();
					DrawSpriteInGame=true;
					boardChess.SetSelectionPiece(boardChess.WhitePieces->Pieces[i]);
					cout<<boardChess.WhitePieces->Pieces[i]->GetPlaceCurrent().GetColumn()<<" ";
					cout<<boardChess.WhitePieces->Pieces[i]->GetPlaceCurrent().GetRow()<<endl;
					boardChess.WhitePieces->Pieces[i]->ClearPossibleMoveLocation();
					boardChess.WhitePieces->Pieces[i]->GetPossibleMoveLocation(boardChess.Board);
					boardChess.WhitePieces->Pieces[i]->OutPutConsolePossibleMoveLocation();
					boardChess.ShowConsole();
				}
			}
		}
	}
	boardChess.ShowPossibleMove(boardChess.GetSelectionPieceMove(),&windowGame,DrawSpriteInGame);
	if(DrawSpriteInGame==true)
	{
		boardChess.DrawSelectionPiece(&windowGame);
	}
}
string Game::GetStringMove(Vector2i p)
{
	string resultString;
	resultString+= char(p.x+97);
	resultString+= char(7-p.y+49);
	return resultString;
}
Vector2i Game::toCoord(char a,char b)
{
	int x = int(a)-97 ;
	int y = 7-int(b)+49;
	return Vector2i(x,y);
}
void Game::IntImageBackground(string l)
{
	t_Background.loadFromFile(l);
	s_Background.setTexture(t_Background);
}
Vector2u Game::GetSizeBackGround()
{
	return t_Background.getSize();
}
void Game::IntIconInGame()
{
	t_Undo.loadFromFile("images/icon/undo.png");
	t_Indo.loadFromFile("images/icon/indo.png");
	t_Option.loadFromFile("images/icon/option.png");
	s_Indo.setTexture(t_Indo);
	s_Undo.setTexture(t_Undo);
	s_Option.setTexture(t_Option);
	s_Option.setPosition(900,24);
	s_Undo.setPosition(900,550);
	s_Indo.setPosition(900,650);
}
void Game::DrawIconInGame()
{
	windowGame.Draw(s_Option);
	windowGame.Draw(s_Undo);
	windowGame.Draw(s_Indo);
}
TypeIcon Game::ProcessIcon()
{
	
	if(mouseGame.CheckGetGlobalBoundsMouse(s_Option))
	{
		mouseGame.ChangeImage("images/mouse/mouse2.png");
		if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
		{
			cout<<"icon option\n";
			stateDrawIcon=TypeIcon::Draw;
			clickButton.Play();
			return TypeIcon::OptionIcon;
		}
	}
	else if(mouseGame.CheckGetGlobalBoundsMouse(s_Undo))
	{
		mouseGame.ChangeImage("images/mouse/mouse2.png");
		if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
		{
			cout<<"icon undo\n";
			return TypeIcon::UndoIcon;
		}
	}
	else if(mouseGame.CheckGetGlobalBoundsMouse(s_Indo))
	{
		mouseGame.ChangeImage("images/mouse/mouse2.png");
		if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
		{
			cout<<"icon indo\n";
			return TypeIcon::IndoIcon;
		}
	}
	else 
	{
		mouseGame.ChangeImage("images/mouse/mouse1.png");
	}
}
void Game::OutPutMenuGame()
{
	
	if(ProcessIcon()==TypeIcon::OptionIcon && stateDrawIcon==TypeIcon::Draw)
	{
		stateChooseIcon=TypeIcon::WaitChoose;
		windowGame.Draw(s_MenuGame);
		if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(325,360),90,90))
		{

			mouseGame.ChangeImage("images/mouse/mouse2.png");
			//cout<<"Save\n";
		}
		else if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(465,360),90,90))
		{
			mouseGame.ChangeImage("images/mouse/mouse2.png");
			//cout<<"Muti Sound\n";
		
			if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
			{
				clickButton.Play();
				if(musicInGame.GetStateMusic()==stateMusic::PLAY)
				{
					musicInGame.Pause();
				}
				else
				{
					musicInGame.Play();
				}
			}
		}
		else if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(600,360),90,90))
		{
			mouseGame.ChangeImage("images/mouse/mouse2.png");
			if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
			{
				clickButton.Play();
				musicInGame.Stop();
				windowGame.Destroy();
			}
			//cout<<"Exit\n";
		}
		else if(mouseGame.CheckGetGlobalBoundsMouse(Vector2i(690,230),45,45))
		{
			mouseGame.ChangeImage("images/mouse/mouse2.png");
			if(eventInputGame.typeInputMouse==TypeInPut::LEFT_MOUSE)
			{
				clickButton.Play();
				stateDrawIcon=TypeIcon::NoDraw;
				stateChooseIcon=TypeIcon::NoWaitChoose;
			}
		}
		else
		{
			mouseGame.ChangeImage("images/mouse/mouse1.png");
		}
		mouseGame.OutPutPosOfMouseInConsole();
	}

}
void Game::DrawTurnPlayer()
{
	Texture t_Turn;
	Sprite s_Turn;
	Texture t_TurnBlack;
	Sprite s_TurnBlack;
	Texture t_TurnWhite;
	Sprite s_TurnWhite;
	t_Turn.loadFromFile("images/menu/turn.png");
	t_TurnBlack.loadFromFile("images/chess_size1/turnblack.png");
	t_TurnWhite.loadFromFile("images/chess_size1/turnwhite.png");
	s_Turn.setTexture(t_Turn);
	s_TurnBlack.setTexture(t_TurnBlack);
	s_TurnWhite.setTexture(t_TurnWhite);
	s_Turn.setPosition(880,120);
	s_TurnBlack.setPosition(900,200);
	s_TurnWhite.setPosition(900,200);
	if(turnPlayer==TurnPlayer::P1Play)
	{
		windowGame.Draw(s_TurnWhite);
		windowGame.Draw(s_Turn);
	}
	else
	{
		windowGame.Draw(s_TurnBlack);
		windowGame.Draw(s_Turn);
	}
}
StateMenu Game::GetStateGame()
{
	return stateGame;
}
void Game::DrawChooseChangePawn()
{
	if(changePawn==TypeIcon::ChangePawn)
	{
		if(boardChess.GetSelectionPieceMove()->GetColorPiece()==ColorGame::Black)
		{
			windowGame.Draw(s_ChangePawnBlack);
		}
		else
		{
			windowGame.Draw(s_ChangePawnWhite);
		}
	}


}
int Game::WinOrLose()
{
	if(boardChess.PieceWin()==ColorGame::Black)
	{
		cout<<"den thang\n";
	}
	else if(boardChess.PieceWin()==ColorGame::White)
	{
		cout<<"trang thang\n";
	}
	else
		return 0;
}
void Game::AnimationPieceMove(Piece *p,Vector2f newPos,Vector2f oldPos)
{
	Vector2f spaceMove=newPos-oldPos;

	for(int i=0;i<30;i++)
	{
		
		p->SpritePiece.move(spaceMove.x/30, spaceMove.y/30); 
		windowGame.Draw(s_Background);
		boardChess.DrawBoard(&windowGame);
		for(int i=0;i<boardChess.BlackPieces->GetNumberofPiece();i++)// viet lai ham get size
		{
			if(boardChess.BlackPieces->SearchPieceInVector(p)==-1)
			{
				boardChess.BlackPieces->Pieces[i]->SetPosition();
				windowGame.Draw(boardChess.BlackPieces->Pieces[i]->SpritePiece);
			}
			else
			{
				windowGame.Draw(boardChess.BlackPieces->Pieces[i]->SpritePiece);
			}
		}
		for(int i=0;i<boardChess.WhitePieces->GetNumberofPiece();i++)
		{
			if(boardChess.WhitePieces->SearchPieceInVector(p)==-1)
			{
				boardChess.WhitePieces->Pieces[i]->SetPosition();
				windowGame.Draw(boardChess.WhitePieces->Pieces[i]->SpritePiece);
			}
			else
			{
				windowGame.Draw(boardChess.WhitePieces->Pieces[i]->SpritePiece);
			}


		}// ket thuc ve cac quan co
		windowGame.Draw(p->SpritePiece);
		DrawIconInGame();
		DrawTurnPlayer();
		//OutPutMenuGame();
		boardChess.DrawPieceEat(&windowGame);
		mouseGame.GetPositionOfMouse(*windowGame.GetWindowGame());
		mouseGame.DrawMouse(*windowGame.GetWindowGame());
		windowGame.EndDraw();
	}
}
void Game::DrawCheckMate()
{

}