#include "HighScoreManager.h"
#include "../ArkanoidClone/SourceCode/Scenes/GameScene.h"
#include "../ArkanoidClone/SourceCode/Program.h"
#include <filesystem>
#include <fstream>
HighScoreManager::HighScoreManager(Program* _program): program(_program)
{
	pathToScore = std::filesystem::current_path().append("Resources/Stages/Highscores.txt");
	if (!std::filesystem::exists(pathToScore))
	{
		std::ofstream file;
		file.open(pathToScore);
		file.close();
	}
}

void HighScoreManager::LoadScores()
{
	LoadScoresFromFile();
	LoadScoresFromProgram();
}

void HighScoreManager::UpdateScore(Stage* currentStage, int currentScore)
{
	if (scoreMap[currentStage->stageName] < currentScore)
		scoreMap[currentStage->stageName] = currentScore;
}

void HighScoreManager::SaveScores()
{
	std::ofstream file(pathToScore);
	if (file)
	{
		for (auto pair : scoreMap)
		{
			file << pair.first << " " << pair.second << std::endl;
		}
	}
	file.close();
}

int HighScoreManager::GetCurrentHighscore(Stage* stage)
{
	return scoreMap[stage->stageName];
}

void HighScoreManager::LoadScoresFromFile()
{
	std::ifstream file(pathToScore);
	if (file)
	{
		std::string stageName, score;
		int i = 0;
		while (file >> stageName >> score)
		{
			scoreMap.insert(std::make_pair(stageName, std::stoi(score)));
		}
	}
	file.close();
}

void HighScoreManager::LoadScoresFromProgram()
{
	for (auto originalStep : program->levelSelectorOriginal->stages)
	{
		if(!scoreMap.contains(originalStep->stageName))
			scoreMap.insert(std::make_pair(originalStep->stageName, 0));
	}
	for (auto customStep : program->levelSelectorCustom->stages)
	{
		if (!scoreMap.contains(customStep->stageName))
			scoreMap.insert(std::make_pair(customStep->stageName, 0));
	}
}
