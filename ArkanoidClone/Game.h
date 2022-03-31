#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Profiler.h"
class Game
{
private:
	//Window Settings
	const unsigned int screenWidth = 1200;
	const unsigned int screenHeight = 925;
	const std::string windowTitle = "ArkanoidClone";

	//SFML Variables 
	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Clock clock;
	float deltaTime;

	//Varibles
	Profiler profiler;
	Ball ball;
	Ball ball2;
	
	//Methods
	void InitializeWindow(unsigned int width, unsigned int height, std::string title);

public:
	//Variables

	//Constructors&Destructors
	Game();
	virtual ~Game();

	//Methods
	void CalculateDeltaTime();
	void UpdateEvents();
	void Update();
	void Render();
	void Run();

};

