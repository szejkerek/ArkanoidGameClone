#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scenes/GameScene.h"
#include "Scenes/MenuScene.h"
#include "Scenes/SceneManager.h"
#include "Utility/Profiler.h"
#include "Scenes/LevelSelectorScene.h"

#include "Utility/Resources.h"
class Program
{
private:
	const std::string windowTitle = "ArkanoidClone";

	//SFML Variables 
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
	//SFML Variables 
	sf::RenderWindow* window;

	//Scenes
	LevelSelectorOriginal* levelSelectorOriginal;
	LevelSelectorCustom* levelSelectorCustom;
	SceneManager* sceneManager;
	HighScoreManager* highScoreManager;
	GameScene* game;
	MenuScene* menu;

	//Constructors
	Program();
	~Program();

	void Run();
};

