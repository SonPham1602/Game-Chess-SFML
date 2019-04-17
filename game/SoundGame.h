//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma  once
#include <SFML/Audio.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class SoundGame// class am thanh 
{
private:
	SoundBuffer buffer;
	Sound sound_game;
	string locationSound;// dia chi file am thanh
	bool repeatSound;// bieng kiem tra lap lai
	int volumeSound;// am luong
public:
	SoundGame();// khoi tao
	~SoundGame();// huy am thanh
	void SetSoundBuffer(string l);// l la dai chi file nhac
	void SetRepeatSound();// cai dat lap lai
	void Play();// chay 
	void Pause();// dung 
	void Stop();// tat
	void ChangeVolumeSound(int temp);// thanh doi volume
};