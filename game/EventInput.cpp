#include "EventInput.h"
void EventInputGame::SetWindow(WindowGame *w)
{
	m_window=w;
	typeInputMouse=TypeInPut::WAIT_MOUSE;
}
void EventInputGame::CheckEvent()
{
	while (m_window->GetWindowGame()->pollEvent(m_Event))
	{
		
		if(m_Event.type == sf::Event::Closed)
		{
			m_window->Destroy();
		}
		if(m_Event.type == sf::Event::Resized)
		{

		}
		if(m_Event.type == sf::Event::GainedFocus)
		{

		}
		if(m_Event.type == sf::Event::LostFocus)
		{

		}
		if(m_Event.type == sf::Event::MouseMoved)
		{
			
		}
		typeInputMouse=TypeInPut::WAIT_MOUSE;
		if(m_Event.type==sf::Event::MouseButtonPressed)
		{
			if(m_Event.key.code==sf::Mouse::Left)
			{
				typeInputMouse=TypeInPut::LEFT_MOUSE;
			}
			else if(m_Event.key.code==sf::Mouse::Right)
			{
				typeInputMouse=TypeInPut::RIGHT_MOUSE;
			}
		}
		
	}
}
void EventInputGame::CheckEvent(sf::Sprite &s)
{
	bool moving=false;
	int dx,dy;

	while(m_window->GetWindowGame()->pollEvent(m_Event))
	{
		typeInputMouse=TypeInPut::WAIT_MOUSE;
		if(m_Event.type==sf::Event::MouseButtonPressed)
		{
			if(m_Event.key.code==sf::Mouse::Left)
			{
				
				if(s.getGlobalBounds().contains(sf::Mouse::getPosition(*m_window->GetWindowGame()).x,sf::Mouse::getPosition(*m_window->GetWindowGame()).y))
				{
					moving=true;
					std::cout<<sf::Mouse::getPosition(*m_window->GetWindowGame()).x;
					std::cout<<":";
					std::cout<<sf::Mouse::getPosition(*m_window->GetWindowGame()).y<<std::endl;

					dx=sf::Mouse::getPosition(*m_window->GetWindowGame()).x-s.getPosition().x;
					dy=sf::Mouse::getPosition(*m_window->GetWindowGame()).y-s.getPosition().y;
				}
				else
					typeInputMouse=TypeInPut::LEFT_MOUSE;

			}
		}
		if(m_Event.type==sf::Event::MouseButtonReleased)
		{
			if(m_Event.key.code==sf::Mouse::Left)
			{
				moving=false;
			}
		}
	}
	if(moving)
	{
		s.setPosition(sf::Mouse::getPosition(*m_window->GetWindowGame()).x-dx,s.getPosition().y);
		std::cout<<sf::Mouse::getPosition(*m_window->GetWindowGame()).x;
		
	}
	

}
sf::Event EventInputGame::GetEvent()
{
	return m_Event;
}