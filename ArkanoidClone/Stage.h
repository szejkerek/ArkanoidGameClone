#pragma once
#include <iostream>
#include <string>
#include <set>
#include "IBrick.h"
#include "Bricks.h"
#include "SFML/Graphics.hpp"

#define BRICK_ROWS 25
#define BRICK_COLUMNS 13

class Stage: public sf::Drawable 
{
public:
	//Game Objects
	std::set<IBrick*> playableBricks;	  //vector with just bricks
private:
	//Game Objects
	IBrick* bricks[BRICK_COLUMNS][BRICK_ROWS]; //array with bricks and nullptr
	//std::vector<IBrick*> playableBricks;	  //vector with just bricks

	//Variables	
	sf::Vector2f playgroundPosition;
	char stageArray[BRICK_COLUMNS][BRICK_ROWS];
	bool playable = false;
	int stageNumber;

	//Methods
	IBrick* ChooseBrick(char letter);
	void FillStageArray(std::vector<char> stageVector);
	bool LoadMapFromFileToArray();
	bool SetUpBlocks();

	bool CalculateBricksPositions();
	
public:
	//Constructors & Destructors
	Stage(int stageNumber, sf::Vector2f _playgroundPosition);
	~Stage();

	//Methods 
	void FillPlayableSet();

	//Getters&Setters

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

