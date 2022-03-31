#include "Game.h"

void Game::InitializeWindow(unsigned int width, unsigned int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

Game::Game()
{
	InitializeWindow(1200, 925, "ArkanoidClone");
}

Game::~Game()
{
	delete window;
}

void Game::UpdateEvents()
{
	
	while (window->pollEvent(this->sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
		{
			//FPS.SaveProfile();
			window->close();
		}
	}
	
}


void Game::Update()
{
	UpdateEvents();
	/*deltaTime = clock.restart().asSeconds();
	

	ball.Update(deltaTime);
	ball.Draw(window);

	

	FPS.Update();*/
}

void Game::Render()
{
	window->clear();



	window->display();
}

void Game::Run()
{
	while (window->isOpen())
	{
		Update();
		Render();
	}
}
