#pragma once
#include <iostream>
#include <string>
#include "IBrick.h"
#include "Bricks.h"
#include "SFML/Graphics.hpp"

#define BRICK_ROWS 25
#define BRICK_COLUMNS 13

class Stage: public sf::Drawable 
{
private:
	//Game Objects
	IBrick* bricks[BRICK_COLUMNS][BRICK_ROWS];
	std::vector<IBrick*> playableBricks;

	//Variables	
	sf::Vector2f playgroundPosition;
	char stageArray[BRICK_COLUMNS][BRICK_ROWS];
	bool playable = false;
	int stageNumber;

	//Methods
	void FillStageArray(std::vector<char> stageVector);
	IBrick* ChooseBrick(char letter);
	bool LoadMapFromFileToArray();
	bool SetUpBlocks();

	bool CalculateBricksPositions();
	//bool PlaceBricks();
	
public:
	//Constructors & Destructors
	Stage(int stageNumber, sf::Vector2f _playgroundPosition);
	~Stage();

	//Methods 
	void UpdatePlayableBricks();

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

