#pragma once
#include "SFML/Graphics.hpp"
#include "../ArkanoidClone/SourceCode/Entity/Stage.h"
#include <unordered_map>

class Program;
class HighScoreManager
{
public:
	HighScoreManager(Program* _program);
	void LoadScores();
	void UpdateScore(Stage* currentStage, int currentScore);
	void SaveScores();

private:
	Program* program;
	std::filesystem::path pathToScore;
	std::unordered_map<std::string , int> scoreMap;

	void LoadScoresFromFile();
	void LoadScoresFromProgram();
};

