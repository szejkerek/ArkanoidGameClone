#pragma once
#include <iostream>
#include <string>
#include "Brick.h"
#include "SFML/Graphics.hpp"

class Stage : sf::Drawable 
{
private:
	//Game Objects
	//Brick* blocks[13][21];
	int stageArray[13][21];
	//Variables
	int stageNumber = 1;
	//Methods
	void FillStageArray(std::vector<char> stageVector);

public:
	//Constructors & Destructors
	Stage() {}
	Stage(int stageNumber);

	//FileManagement
	void GenerateDefaultMapFile(std::string filename);
	void LoadMapFromFileToArray(int _stageNumber);

	//Methods 

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

