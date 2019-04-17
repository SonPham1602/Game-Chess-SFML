#pragma  once
//Nguoi code:
//Pham Ngoc Son
// 1612565
#include "BoardChess.h"
#include "WindowGame.h"
#include "MenuGame.h"
#include "MusicGame.h"
#include "Mouse.h"
#include "SoundGame.h"
#include "Player.h"
#include "EventInput.h"
#include "Connector.h"
#include <fstream>
using namespace sf;

enum class TurnPlayer// class enum luot nguoi choi
{
	P1Play,P2Play
};
enum class TypeIcon// class enum loai icon, va trang thai
{
	Draw,
	OptionIcon,
	UndoIcon,
	IndoIcon,
	NoDraw,
	WaitChoose,
	NoWaitChoose,
	ChangePawn,
	NoChangePawn,
};
class Game// class game chess 
{
private:
	string position;// chuoi di chuyen vs cpu
	CpuPlayer cpuPlayer;// engine game vs may tinh
	TypeIcon changePawn;// bien kiem tra thang cap quan tot
	bool enterWall;// bien kiem tra nhap thanh
	StateMenu stateGame;// trang thai game
	TypeIcon stateChooseIcon;//trang thai chon icon
	TypeIcon stateDrawIcon;// trang thai ve icon
	TurnPlayer turnPlayer;// luot choi 
	TurnPlayer beginPlayer;// nguoi bat dau choi
	MenuGame menuGame;// menu game
	MouseGame mouseGame;// chuot game
	SoundGame soundGame;// am thanh
	SoundGame clickGame;// am thanh click chon
	SoundGame clickButton;// anh thanh click vao nut
	MusicGame musicMenu;// nhac menu
	MusicGame musicInGame;// nahc trong game
	ModeGame modeGame;// che do choi vs nguoi hoac cpu
	WindowGame windowGame;// win dow
	Player player1;// nguoi choi 1
	Player player2;// nguoi choi 2
	BoardChess boardChess;// ban co
	EventInputGame eventInputGame;// su kien game
	bool DrawSpriteInGame;// bien kiem tra ve nuoc di chuyen dc
	ColorGame colorOfPlayer;// che do quan cua che do vs cpu
	Vector2i NewPos;// vi tri moi , dung co danh vs may
	Vector2i OldPos;// vi tri cu , dung cho danh vs may
	// cac hinh anh trong game
	sf::Texture t_Background;
	sf::Sprite s_Background;
	sf::Texture t_Undo;
	sf::Sprite s_Undo;
	sf::Texture t_Indo;
	sf::Sprite s_Indo;
	sf::Texture t_Option;
	sf::Sprite s_Option;
	sf::Texture t_MenuGame;
	sf::Sprite s_MenuGame;
	sf::Texture t_ChangePawnBlack;
	sf::Sprite s_ChangePawnBlack;
	sf::Texture t_ChangePawnWhite;
	sf::Sprite s_ChangePawnWhite;
	// luoc di cua quan co
	string movesBlack;
	string movesWhite;
	//am thanh game
	Volume volumeGame;
public:
	Game();// khoi tao game
	void IntImageBackground(string l);// khoi tao dia chi cua background
	void IntIconInGame();// khoi icon
	Vector2u GetSizeBackGround();// lay kich thuoc background
	void IntGame();// khoi  tao game
	void CreateGame1();// chay game p1 vs p2
	void CreateGame2();// chay game cpu vs p
	void HandleInput();// xi ly menu
	void SelectionPieceP1VsP2();// nhan phim vs nguoi
	void SelectionPieceP1vsCpu(ColorGame c);// nhan phim choi vs may
	void SelectionMovePlace();// chon quan co di chuyen hoac an
	WindowGame *GetWindowGame();// lay cua so window
	// xu ly chuoi di chuyen
	string GetStringMove(Vector2i p);// xuat ra chuoi di chuyen
	Vector2i toCoord(char a,char b);// xuat ra  so cua buoc di chuyen
	//
	void DrawIconInGame();// ve icon
	TypeIcon ProcessIcon();// lay trang thai su ly icon 
	void OutPutMenuGame();// xuat menu phu
	void DrawTurnPlayer();// ve luot nguoi choi
	StateMenu GetStateGame();// lay trang thai game
	void DrawChooseChangePawn();// de chon quan thang cap
	int WinOrLose();// de biet ai win 
	void AnimationPieceMove(Piece *p,Vector2f newPos,Vector2f oldPos);
	void DrawCheckMate();
};