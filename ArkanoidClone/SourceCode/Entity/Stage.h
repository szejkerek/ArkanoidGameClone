#pragma once
#include <iostream>
#include <string>
#include "Bricks.h"
#include "SFML/Graphics.hpp"

enum class StageType {
	original,
	custom
};

static constexpr int BRICK_ROWS = 25;
static constexpr int BRICK_COLUMNS = 13;

class Stage: public sf::Drawable 
{
private:
	int stageNumber;

	inline void LoadVectorFromFile(const std::string& filename, const StageType& stageType);
	inline void SetUpStage(const std::vector<char>& brickChars);
	inline IBrick* SetUpBrick(const int& row, const int& collumn, const char& brickChar);
	inline bool ValidateVector(const std::vector<char>& brickChars);

public:
	std::vector<IBrick*> playableBricks;	  //vector with just bricks

	//Constructors & Destructors
	Stage(const int& stageNumber);
	~Stage();

	//Methods 
	void CollisionDetected(IBrick* brickToDelete);

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};