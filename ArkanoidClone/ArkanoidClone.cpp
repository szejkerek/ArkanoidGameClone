#include <iostream>

#include "Utility.h"
#include <SFML/Graphics.hpp>

#include "Ball.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), "ArkanoidClone", sf::Style::Close);
	sf::Event e;
	sf::Clock clock;
	window.setFramerateLimit(60);

	Ball ball({0,0},{4,2}, 50);
	float deltaTime; 
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		std::cout << deltaTime << std::endl;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
		



		window.clear();

		ball.Update(deltaTime);
		ball.Draw(window);

		window.display();

	}
   
}
