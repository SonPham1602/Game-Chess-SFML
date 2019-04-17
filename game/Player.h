//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma  once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
enum  class SexPlayer
{
	
};
class Player {
private:
	string Name;
	int Old;
	string Address;
	int MarkElo;
	string Sex;
	int NumberOfWin;
	int NumberOfLose;
	string movePiece;
public:
	string GetName();
	int GetMarkElo();
	string GetAddress();
	string GetSex();
	Player();
	Player(string n,int o);// n la name, o la old
	~Player();
	int AddElo();
	int MinusElo();
	void AddorMinusNumberWinorLose();
	void addMovePiece(string move);
	void minusMovePiece();
};