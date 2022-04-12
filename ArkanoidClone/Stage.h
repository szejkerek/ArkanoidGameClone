#pragma once
#include <iostream>
#include <string>
#include "IBrick.h"
#include "Bricks.h"
#include "SFML/Graphics.hpp"

class Stage: public sf::Drawable 
{
private:
	//Game Objects
	IBrick* bricks[13][21];

	//Variables
	sf::Vector2f playgroundPosition;
	char stageArray[13][21];
	bool playable = false;
	int stageNumber = 1;

	//Methods
	void FillStageArray(std::vector<char> stageVector);
	IBrick* ChooseBrick(char letter);
	bool LoadMapFromFileToArray();
	bool SetUpBlocks();

public:
	//Constructors & Destructors
	Stage() {}
	~Stage();
	Stage(int stageNumber, sf::Vector2f _playgroundPosition);

	//Methods 
	bool CalculateBricksPositions();
	bool PlaceBricks();
	void DrawBricks();

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

