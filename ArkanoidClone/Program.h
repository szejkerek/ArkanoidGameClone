#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Ball.h"
#include "Profiler.h"
class Program
{
private:
	const std::string windowTitle = "ArkanoidClone";

	//SFML Variables 
	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Color backgroundColor = sf::Color::Black;
	sf::Clock clock;
	float deltaTime;

	//Varibles
	Profiler profiler;
	
	//Game Objects
	Game game;

	
	//Methods
	void InitializeWindow(unsigned int width, unsigned int height, std::string title);

public:
	//Variables

	//Constructors&Destructors
	Program();
	virtual ~Program();

	//Methods
	void CalculateDeltaTime();
	void UpdateEvents();
	void Update();
	void Render();
	void Run();

};

