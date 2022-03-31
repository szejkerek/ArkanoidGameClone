#include "Game.h"

void Game::InitializeWindow(unsigned int width, unsigned int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

Game::Game()
{
	InitializeWindow(screenWidth, screenHeight, windowTitle);
	ball = Ball({ 0,0 }, { 4,2 }, 50);
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
			profiler.SaveProfile();
			window->close();
		}
	}
	
}


void Game::Update()
{
	UpdateEvents();

	ball.Update(0.00016f);
	/*deltaTime = clock.restart().asSeconds();
	

	ball.Update(deltaTime);
	ball.Draw(window);

	

	FPS.Update();*/
}

void Game::Render()
{
	window->clear();

	ball.Draw(window);


	window->display();
}

void Game::Run()
{
	while (window->isOpen())
	{
		Update();
		Render();
		profiler.Update();
	}
}
