#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scenes/Game.h"
#include "Scenes/SceneManager.h"
#include "Utility/Profiler.h"
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
	Profiler profiler; //REMOVE ON FINAL BUILD

	
	//Methods
	void InitializeWindow(unsigned int width, unsigned int height, std::string title);
	void CalculateDeltaTime();
	void UpdateEvents();
	void Update();
	void Render();

	
public:
	
	SceneManager* sceneManager;

	//Scenes
	Game* game;


	//Constructors
	Program();
	~Program();

	void Run();
};

