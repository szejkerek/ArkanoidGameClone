#pragma once
#include <iostream>

#include "Block.h"
#include "SFML/Graphics.hpp"
class Stage : sf::Drawable 
{
private:
	//Game Objects
	Block* blocks[13][21];
	//Variables
	std::string stageName;
	int stageNumber;
	//Methods


public:
	//Constructors & Destructors
	Stage(int _stageNumber);

	//LoadingStageFromFile
	void LoadMapFromFile();
	bool ValidateFilename();
	std::string GetFilename(int _stageNumber);

	//Methods 

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

