#pragma once
#include "SFML/Graphics.hpp"
#include "../ArkanoidClone/SourceCode/Entity/Stage.h"
#include <unordered_map>

class GameScene;
class HighScoreManager
{
public:
	HighScoreManager(GameScene* _gamescene);
	inline void LoadScores();
	inline void UpdateScore(Stage* currentStage, int currentScore);
	inline void SaveScores();

private:
	GameScene* gamescene;
	std::unordered_map<std::string , int> scores;
};

