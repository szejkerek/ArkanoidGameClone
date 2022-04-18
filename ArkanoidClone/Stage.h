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
public:
	//Game Objects
	std::vector<IBrick*> playableBricks;	  //vector with just bricks
private:
	//Game Objects
	IBrick* bricks[BRICK_COLUMNS][BRICK_ROWS]; //array with bricks and nullptr

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
	void CollisionDetected(IBrick* brickToDelete);

	//Getters&Setters

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

