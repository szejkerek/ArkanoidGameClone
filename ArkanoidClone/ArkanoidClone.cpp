#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Ball.h"
#include "Utility.h"
#include "Profiler.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), "ArkanoidClone", sf::Style::Close);
	sf::Event e;
	sf::Clock clock;
	Profiler FPS;

	Ball ball({0,0},{4,2}, 50);
	float deltaTime; 
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				FPS.SaveProfile();
				window.close();
			}
		}

		window.clear();

		ball.Update(deltaTime);
		ball.Draw(window);

		window.display();

		FPS.Update();
	}
   
}
