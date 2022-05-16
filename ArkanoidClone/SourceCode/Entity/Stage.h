#pragma once
#include <iostream>
#include <string>
#include "Bricks.h"
#include "../Utility/Resources.h"

class Program;

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
	std::string stageName = "null";
	bool loadedSuccesfuly = false;
	std::vector<IBrick*> loadedStage;	  //vector with just bricks
	Program* program;


	inline void SetUpStage(const std::vector<char>& brickChars);
	inline IBrick* SetUpBrick(const int& row, const int& collumn, const char& brickChar);
	inline void LoadStageFromFile(const int& _stageNumber, const std::string& filename, const StageType& stageType);
	inline bool ValidateVector(const std::vector<char>& brickChars);
	inline std::string GenerateStageName(const int& _stageNumber);

public:
	std::vector<IBrick*> playableBricks;	  //vector with just bricks

	//Constructors & Destructors
	Stage(const int& _stageNumber, Program* _program);
	Stage(const int& _stageNumber, const std::string& filename, const StageType& stageType, Program* _program);
	~Stage();

	//Methods 
	void CollisionDetected(IBrick* brickToDelete);
	bool LoadedSucessfuly();
	sf::Texture* GetPreview();
	std::string GetStageName();
	void WinStage();

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};