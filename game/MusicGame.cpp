#include "MusicGame.h"
MusicGame::MusicGame()
{
	repeatMusic=false;
	volumeMusic=100;
	s_Music=stateMusic::STOP;
}
MusicGame::~MusicGame()
{

}
void MusicGame::SetMusic(string l)
{
	musicGame.openFromFile(l);
}
void MusicGame::Play()
{
	musicGame.play();
	s_Music=stateMusic::PLAY;
}
void MusicGame::Pause()
{
	s_Music=stateMusic::PAUSE;
	musicGame.pause();
}
void MusicGame::Stop()
{
	musicGame.stop();
	s_Music=stateMusic::STOP;
}
void MusicGame::SetRepeat()
{
	repeatMusic=true;
	musicGame.setLoop(repeatMusic);
}
void MusicGame::ChangeVolume(int temp)
{
	musicGame.setVolume(temp);
}
void MusicGame::Continue()
{
	if(s_Music==stateMusic::PAUSE)
	{
		musicGame.play();
	}
	s_Music=stateMusic::PLAY;
}
stateMusic MusicGame::GetStateMusic()
{
	return s_Music;
}