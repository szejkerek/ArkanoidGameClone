#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Profiler.h"
class Game
{
private:
	const unsigned int screenWidth = 1200;
	const unsigned int screenHeight = 925;
	const std::string windowTitle = "ArkanoidClone";
	Profiler profiler;
	Ball ball;
	//SFML Variables 
	sf::RenderWindow* window;
	sf::Event sfEvent;
	
	//Methods
	void InitializeWindow(unsigned int width, unsigned int height, std::string title);

public:
	//Variables

	//Constructors&Destructors
	Game();
	virtual ~Game();

	//Methods
	void UpdateEvents();
	void Update();
	void Render();
	void Run();

};

