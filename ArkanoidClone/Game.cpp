#include "Game.h"

Game::Game()
{
	InitializeWindow(screenWidth, screenHeight, windowTitle);
	ball = Ball({ 0,0 }, { 4,2 }, 50);
	ball2 = Ball({ 1250,925 }, { -4,-2 }, 50);
}

Game::~Game()
{
	delete window;
}

void Game::InitializeWindow(unsigned int width, unsigned int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window->setVerticalSyncEnabled(false);
}

void Game::CalculateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
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
	CalculateDeltaTime();
	ball.Update(deltaTime);
	ball2.Update(deltaTime);
}

void Game::Render()
{
	window->clear(backgroundColor);
	//Draw items here
	ball.Draw(window);
	ball2.Draw(window);
	//
	window->display();
}

void Game::Run()
{
	//Main game loop
	while (window->isOpen())
	{
		Update();
		Render();
		profiler.Update();
	}
}
