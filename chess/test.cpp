//
////
//// Disclamer:
//// ----------
////
//// This code will work only if you selected window, graphics and audio.
////
//// Note that the "Run Script" build phase will copy the required frameworks
//// or dylibs to your application bundle so you can execute it on any OS X
//// computer.
////
//// Your resource files (images, sounds, fonts, ...) are also copied to your
//// application bundle. To get the path to these resource, use the helper
//// method resourcePath() from ResourcePath.hpp
////
//
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include<iostream>
//// Here is a small helper for you ! Have a look.
//
//
//int main(int, char const**)
//{
//	sf::Vector2f offset(28,28);
//	// Create the main window
//	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
//
//	// Set the Icon
//	sf::Image icon;
//	if (!icon.loadFromFile( "icon.png")) {
//		return EXIT_FAILURE;
//	}
//	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//
//	// Load a sprite to display
//	sf::Texture texture;
//	if (!texture.loadFromFile("cute_image.jpg")) {
//		return EXIT_FAILURE;
//	}
//	sf::Sprite sprite(texture);
//
//	// Create a graphical text to display
//	sf::Font font;
//	if (!font.loadFromFile(  "sansation.ttf")) {
//		return EXIT_FAILURE;
//	}
//
//	// Load a music to play
//	sf::Music music;
//	if (!music.openFromFile( "nice_music.ogg")) {
//		return EXIT_FAILURE;
//	}
//
//	// Play the music
//	music.play();
//
//	// Start the game loop
//	std::string str;
//	sf::Text text;
//	text.setFont(font);
//	sf::Texture t;
//	t.loadFromFile("t.png");
//	sf::Sprite s;
//	s.setTexture(t);
//	sf::Vector2f oldPos(0,0);
//	sf::Vector2f newPos(100,300);
//	while (window.isOpen())
//	{
//		// Process events
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			// Close window: exit
//			if (event.type == sf::Event::Closed) {
//				window.close();
//			}
//			
//			// Escape pressed: exit
//		
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
//				for(int k=0;k<100;k++)
//				{
//					
//					sf::Vector2f p = newPos - oldPos;
//					s.move(p.x/100, p.y/100); 
//					window.draw(sprite);
//					window.draw(s); 
//					window.display();
//				}
//			}
//			
//
//			// In event loop...
//			if (event.type == sf::Event::TextEntered)
//			{
//				// Handle ASCII characters only
//				if (event.text.unicode < 128 && event.text.unicode > 31)
//				{
//					str += static_cast<char>(event.text.unicode);
//					
//				}
//				if(event.text.unicode==8)
//				{
//					std::cout<<"xoa";
//					str.pop_back();
//				}
//				if(event.text.unicode==13)
//				{
//					str.push_back('\n');
//				}
//				text.setString(str);
//			}
//
//			// In main loop...
//			
//		}
//		text.setCharacterSize(50);
//		text.setColor(sf::Color::Red);
//		// Clear screen
//		
//		window.clear();
//		// Draw the sprite
//		window.draw(sprite);
//		window.draw(s); 
//		// Draw the string
//		window.draw(text);
//		// Update the window
//		window.display();
//	}
//
//	return EXIT_SUCCESS;
//}

#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	// Let's setup a window
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML View Transformation");

	// Create something simple to draw
	sf::Texture texture;
	texture.loadFromFile("t.png");
	sf::Sprite background(texture);

	sf::Vector2f oldPos;
	bool moving = false;

	float zoom = 1;

	// Retrieve the window's default view
	sf::View view = window.getDefaultView();

	while (window.isOpen()) {
		sf::Event event;
		sf::Vector2i pos=sf::Mouse::getPosition(window);
		int dx,dy;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				// Mouse button is pressed, get the position and set moving as active
				if (event.mouseButton.button == 0 && background.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)==true) {
					std::cout<<"co1";
					moving = true;
					dx=pos.x-background.getPosition().x;
					dy=pos.y-background.getPosition().y;
				}
				break;
			case  sf::Event::MouseButtonReleased:
				// Mouse button is released, no longer move
				if (event.mouseButton.button == 0 ) {
					std::cout<<"co2";
					moving = false;
				}
				break;
			}
		}
		if(moving)
			background.setPosition(pos.x-dx,0);
		// Draw our simple scene
		window.clear(sf::Color::White);
		window.draw(background);
		window.display();
	}
}