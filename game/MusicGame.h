#pragma  once
#include <SFML/Audio.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
enum class stateMusic
{
	PAUSE,
	PLAY,
	STOP,
};

class MusicGame// class nhac trong game
{
private:
	Music musicGame;// nhac
	string locationSound;// dia chi
	bool repeatMusic;// lap lai
	int volumeMusic;// am luong
	stateMusic s_Music;// trang thai
public:
	MusicGame();// khoi tao
	~MusicGame();// huy
	void SetMusic(string l);// l la dai chi file nhac
	void SetRepeat();// cai dat lap lai
	void Play();// chay
	void Pause();// tam dung
	void Stop();// dung
	void ChangeVolume(int temp);// thay doi am luong
	void Continue();// tiep tuc
	stateMusic GetStateMusic();// lay trang thai 
};