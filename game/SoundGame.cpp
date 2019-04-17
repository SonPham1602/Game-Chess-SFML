#include "SoundGame.h"
SoundGame::SoundGame()
{
	repeatSound=false;
	volumeSound=100;
}
SoundGame::~SoundGame()
{

}
void SoundGame::SetSoundBuffer(string l)
{
	if(buffer.loadFromFile(l)==false)
	{
		cout<<"loi khong tim thay file nhac\n";
	}
	else
	{
		sound_game.setBuffer(buffer);
	}
}
void SoundGame::Play()
{
	sound_game.play();
}
void SoundGame::Pause()
{
	sound_game.pause();
}
void SoundGame::Stop()
{
	sound_game.stop();
}
void SoundGame::SetRepeatSound()
{
	repeatSound=true;
	sound_game.setLoop(repeatSound);
}
void SoundGame::ChangeVolumeSound(int temp)
{
	sound_game.setVolume(temp);
}