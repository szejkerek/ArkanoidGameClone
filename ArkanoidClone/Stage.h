#pragma once
#include <iostream>
#include <string>
#include "IBrick.h"
#include "Bricks.h"
#include "SFML/Graphics.hpp"

class Stage : sf::Drawable 
{
private:
	//Game Objects
	IBrick* blocks[13][21];
	char stageArray[13][21];
	//Variables
	bool playable = false;
	int stageNumber = 1;
	//Methods
	void FillStageArray(std::vector<char> stageVector);
	IBrick* ChooseBrick(char letter);

public:
	//Constructors & Destructors
	Stage() {}
	Stage(int stageNumber);

	//FileManagement
	bool LoadMapFromFileToArray();
	bool SetUpBlocks();

	//Methods 

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

