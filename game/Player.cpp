#include "Player.h"
Player::Player()
{
	Name="";
	Old=0;
	Address="";
	MarkElo=0;
	NumberOfWin=0;
	NumberOfLose=0;
}
Player::Player(string n,int o)
{
	Name=n;
	Old=o;
}
Player::~Player()
{

}
string Player::GetName()
{
	return Name;
}
string Player::GetSex()
{
	return Sex;
}
void Player::addMovePiece(string move)
{
	movePiece.append(move);
}
void Player::minusMovePiece()
{
	for(int i=0;i<4;i++)
	movePiece.pop_back();	
}