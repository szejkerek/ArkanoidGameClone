#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
private:
	//Variables
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

