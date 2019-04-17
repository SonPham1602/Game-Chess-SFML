#include "MenuGame.h"
void MenuGame::RunMouseAndMusicAndSound()
{
	// khoi tao sound and music
	mu_Menu.SetMusic("musics/MenuMusic.wav");
	mu_Menu.SetRepeat();
	mu_Menu.Play();
	so_Menu.SetSoundBuffer("musics/ClickChess.wav");
	so_Menu.ChangeVolumeSound(30);
	//khoi tao chuot
	mo_Menu.SetLocation("images/mouse/mouse1.png");
	mo_Menu.SetImage();
}
StateMenu MenuGame::InitiationMenu()
{
	volume.Music=30;
	volume.Sound=70;
	m_stateGame=StateMenu::WAIT;
	modeGame=ModeGame::WAIT;
	e_window.SetWindow(&m_window);
	RunMouseAndMusicAndSound();
	// khoi tao hinh anh
	Texture WallPaper,Play,GameName,Option,Exit;
	WallPaper.loadFromFile("images/menu/WallPaper.jpg");
	Play.loadFromFile("images/menu/play.png");
	GameName.loadFromFile("images/menu/GameName.png");
	Option.loadFromFile("images/menu/Option.png");
	Exit.loadFromFile("images/menu/Exit.png");
	Vector2u sizeimage;
	sizeimage=WallPaper.getSize();
	Sprite s1(WallPaper),s2(Play),s3(GameName),s4(Option),s5(Exit);
	// set up cua so window
	m_window.SetUp("CHESS C++ & SFML by SonPham",sizeimage);
	sf::Image icon;
	icon.loadFromFile("images/icon/icon.png");
	m_window.GetWindowGame()->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	while(m_window.IsDone())
	{
		mo_Menu.GetPositionOfMouse(*m_window.GetWindowGame());
		e_window.CheckEvent();
		m_window.BeginDraw();
		m_window.Draw(s1);
		
			if(mo_Menu.CheckGetGlobalBoundsMouse(s2))
			{
				Texture temp;
				mo_Menu.ChangeImage("images/mouse/mouse2.png");
				temp.loadFromFile("images/menu/playbig.png");
				Sprite tempS(temp);
				tempS.setPosition((float)(WallPaper.getSize().x-temp.getSize().x)/2,(float)130);
				m_window.Draw(tempS);
				if(e_window.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					//m_window.Destroy();
					//mu_Menu.Pause();
					so_Menu.Play();
					Texture chooseMode;
					chooseMode.loadFromFile("images/menu/Choose Mode.png");
					Sprite s_chooseMode;
					s_chooseMode.setTexture(chooseMode);
					// tao man hinh moi 
					// muc dich: de chon mode game
					while(true)
					{
						mo_Menu.ChangeImage("images/mouse/mouse1.png");
						e_window.CheckEvent();
						mo_Menu.GetPositionOfMouse(*m_window.GetWindowGame());
						m_window.BeginDraw();
						m_window.Draw(s_chooseMode);
						Texture t_tickMode;
						t_tickMode.loadFromFile("images/menu/tick.png");
						Sprite s_tickMode;
						s_tickMode.setTexture(t_tickMode);
						// chon che do 2 ng
						if(mo_Menu.CheckGetGlobalBoundsMouse(sf::Vector2i(176,178),80,150))
						{
							mo_Menu.ChangeImage("images/mouse/mouse2.png");
							if(e_window.typeInputMouse==TypeInPut::LEFT_MOUSE)
							{
								e_window.typeInputMouse=TypeInPut::WAIT_MOUSE;
								so_Menu.Play();
								modeGame=ModeGame::P1vsP2;
								
							}
						}
						// chon che do vs cpu
						else if(mo_Menu.CheckGetGlobalBoundsMouse(sf::Vector2i(560,162),130,115))
						{
							mo_Menu.ChangeImage("images/mouse/mouse2.png");
							if(e_window.typeInputMouse==TypeInPut::LEFT_MOUSE)
							{
								e_window.typeInputMouse=TypeInPut::WAIT_MOUSE;
								so_Menu.Play();
								modeGame=ModeGame::PvsCPU;
							}
						}
						// bat dau play game
						if(mo_Menu.CheckGetGlobalBoundsMouse(sf::Vector2i(391,346),52,58))
						{
							mo_Menu.ChangeImage("images/mouse/mouse2.png");
							if(e_window.typeInputMouse==TypeInPut::LEFT_MOUSE&& modeGame!=ModeGame::WAIT)
							{
								e_window.typeInputMouse=TypeInPut::WAIT_MOUSE;
								so_Menu.Play();
								m_window.Destroy();
								mu_Menu.Stop();
								return StateMenu::PLAY_GAME;
							}
						}
						// quay lai menu chinh
						if(mo_Menu.CheckGetGlobalBoundsMouse(sf::Vector2i(770,18),45,52))
						{
							mo_Menu.ChangeImage("images/mouse/mouse2.png");
							if(e_window.typeInputMouse==TypeInPut::LEFT_MOUSE)
							{
								e_window.typeInputMouse=TypeInPut::WAIT_MOUSE;
								so_Menu.Play();
								break;
							}
						}
						// ve dau tick khi chon che do nao
						if(modeGame==ModeGame::P1vsP2)
						{
							s_tickMode.setPosition(190,300);
							m_window.Draw(s_tickMode);
						}
						else if(modeGame==ModeGame::PvsCPU)
						{
							s_tickMode.setPosition(600,300);
							m_window.Draw(s_tickMode);
						}
						// ket thuc ve
						//mo_Menu.OutPutPosOfMouseInConsole();
						mo_Menu.DrawMouse(*m_window.GetWindowGame());
						m_window.EndDraw();
					}
				}
			}
			else
			{
				mo_Menu.ChangeImage("images/mouse/mouse1.png");
				s2.setPosition((WallPaper.getSize().x-Play.getSize().x)/2,130);
				m_window.Draw(s2);
			}
			if(mo_Menu.CheckGetGlobalBoundsMouse(s4))
			{
				mo_Menu.ChangeImage("images/mouse/mouse2.png");
				Texture temp;
				temp.loadFromFile("images/menu/optionbig.png");
				Sprite tempS(temp);
				tempS.setPosition((float)(WallPaper.getSize().x-temp.getSize().x)/(float)2,220);
				m_window.Draw(tempS);
				if(e_window.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					so_Menu.Play();
					Texture t_optionmode;
					Sprite s_optionmode;
					t_optionmode.loadFromFile("images/menu/Option Choose.png");
					s_optionmode.setTexture(t_optionmode);
					Sprite s_changeVolume1,s_changeVolume2;
					Texture t_changeVolume;
					t_changeVolume.loadFromFile("images/menu/volume.png");
					s_changeVolume1.setTexture(t_changeVolume);
					s_changeVolume2.setTexture(t_changeVolume);
					s_changeVolume1.setPosition((volume.Music*2.15+300),168);
					s_changeVolume2.setPosition((volume.Sound*2.15+300),255);
					Vector2f newPos=s_changeVolume1.getPosition();
					bool moving_s1,moving_s2;
					bool moving=false;
					TypeInPut a;
					// ham drag and drop chua viet 
					while (true)
					{
						int dx,dy;
						sf::Event e;
						sf::Vector2i pos=sf::Mouse::getPosition(*m_window.GetWindowGame());
						while(m_window.GetWindowGame()->pollEvent(e))
						{
							a=TypeInPut::WAIT_MOUSE;
							//std::cout<<"mouse:"<<e.mouseMove.x<<":"<<e.mouseMove.y<<endl;
							switch (e.type) {
							case sf::Event::MouseButtonPressed:
								// Mouse button is pressed, get the position and set moving as active
								if (e.mouseButton.button == 0 && s_changeVolume1.getGlobalBounds().contains(mo_Menu.GetPositionVector().x,mo_Menu.GetPositionVector().y)==true) {
									moving = true;
									dx=pos.x-s_changeVolume1.getPosition().x;
									dy=pos.y-s_changeVolume1.getPosition().y;
									moving_s1=true;
								}
								else if(e.mouseButton.button == 0 && s_changeVolume2.getGlobalBounds().contains(mo_Menu.GetPositionVector().x,mo_Menu.GetPositionVector().y)==true)
								{
									moving = true;
									dx=pos.x-s_changeVolume2.getPosition().x;
									dy=pos.y-s_changeVolume2.getPosition().y;
									moving_s2 = true;
								}
								else if(e.mouseButton.button == 0 )
								{
									a=TypeInPut::LEFT_MOUSE;
								}
								break;
							case  sf::Event::MouseButtonReleased:
								// Mouse button is released, no longer move
								if (e.mouseButton.button == 0 ) {
									moving = false;
									moving_s1=false;
									moving_s2=false;
								}
								break;
							}
						}
						if(moving)
						{
							if(moving_s1 && pos.x-dx >=300 &&  pos.x-dx<=515)
							{
								s_changeVolume1.setPosition(pos.x-dx,s_changeVolume1.getPosition().y);
							}
							if(moving_s2 &&  pos.x-dx >=300 &&  pos.x-dx<=515)
							{
								s_changeVolume2.setPosition(pos.x-dx,s_changeVolume2.getPosition().y);
							}
						}
						
						mo_Menu.ChangeImage("images/mouse/mouse1.png");		
						if(mo_Menu.CheckGetGlobalBoundsMouse(sf::Vector2i(750,18),70,70))
						{
							mo_Menu.ChangeImage("images/mouse/mouse2.png");
							if(a==TypeInPut::LEFT_MOUSE)
							{
								a=TypeInPut::WAIT_MOUSE;
								so_Menu.Play();
								volume.Music=(s_changeVolume1.getPosition().x-300)/2.15;
								volume.Sound=(s_changeVolume2.getPosition().x-300)/2.15;
								break;
							}
						}
						mo_Menu.GetPositionOfMouse(*m_window.GetWindowGame());
						m_window.BeginDraw();
						m_window.Draw(s_optionmode);
						m_window.Draw(s_changeVolume1);
						m_window.Draw(s_changeVolume2);
						mo_Menu.DrawMouse(*m_window.GetWindowGame());
						m_window.EndDraw();
					}
				}
			}
			else
			{
				s4.setPosition((WallPaper.getSize().x-Option.getSize().x)/2,220);
				m_window.Draw(s4);
			}
			if (mo_Menu.CheckGetGlobalBoundsMouse(s5))
			{
				mo_Menu.ChangeImage("images/mouse/mouse2.png");
				Texture temp;
				temp.loadFromFile("images/menu/exitbig.png");
				Sprite tempS(temp);
				tempS.setPosition((WallPaper.getSize().x-temp.getSize().x)/2,320);
				m_window.Draw(tempS);
				if(e_window.typeInputMouse==TypeInPut::LEFT_MOUSE)
				{
					so_Menu.Play();
					mu_Menu.Stop();
					m_window.Destroy();

					return StateMenu::EXIT_GAME;
				}
			}
			else
			{
				s5.setPosition((WallPaper.getSize().x-Exit.getSize().x)/2,320);
				m_window.Draw(s5);
			}
		s3.setPosition(308,20);	
		m_window.Draw(s3);
		mo_Menu.DrawMouse(*m_window.GetWindowGame());
		m_window.EndDraw();
	}
	m_window.Destroy();
	return StateMenu::EXIT_GAME;
}
ModeGame MenuGame::GetModeGame()
{
	return modeGame;
}