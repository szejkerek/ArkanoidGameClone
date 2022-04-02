#include "Program.h"

Program::Program()
{
	game = Game(deltaTime);
	InitializeWindow(screenWidth, screenHeight, windowTitle);
}

Program::~Program()
{
	delete window;
}

void Program::InitializeWindow(unsigned int width, unsigned int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window->setVerticalSyncEnabled(false);
}

void Program::CalculateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

void Program::UpdateEvents()
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


void Program::Update()
{
	UpdateEvents();
	CalculateDeltaTime();
	game.Update(deltaTime);
}

void Program::Render()
{
	window->clear(backgroundColor);
	//Draw items here
	window->draw(game);
	//
	window->display();
}

void Program::Run()
{
	//Main game loop
	while (window->isOpen())
	{
		Update();
		Render();
		profiler.Update();
	}
}
