#pragma once
#include "Scene.h"
#include <vector>
#include "../Entity/Objects/Ball.h"
#include "../Entity/Objects/Bricks.h"
#include "../Entity/Managers/Stage.h"
#include "../Entity/Objects/Background.h"
#include "../Entity/Objects/EndScreen.h"
#include "../Entity/Objects/Vaus.h"
#include "../Entity/Managers/HealthManager.h"
#include "../Entity/Managers/PowerUpManager.h"
#include "../Entity/Managers/HighScoreManager.h"
#include "../ArkanoidClone/SourceCode/UI/TextElement.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
class GameScene : public Scene
{
public:
	Program* program;

	Background* background;
	sf::RectangleShape backgroundBehind;
	std::vector<Ball*> balls;
	std::vector<Ball*> ballsToDelete;
	Vaus* vaus;
	Stage* currentStage;
	HealthManager* healthManager;
	PowerUpManager* powerUpManager;
	EndScreen* endScreen;
	float ballAirTime = 0;

	GameScene(Program* _program, float& deltaTime);
	virtual ~GameScene();

	void AddPoints(const int& brickPoint, const int& multiplyier);
	void SelectStage(Stage* _stage);
	void StartGame();	
	void EndGame(bool win);
	void AddBall();
	void RemoveBall(Ball* ballToDelete);
	void RemoveBallNoDelete(Ball* ballToDelete);
	void Update( float& dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	int currentScore = 0;
	int currentHighscore = 0;
	bool playable;

	TextElement* highScoreLabel;
	TextElement* scoreLabel;
	TextElement* scoreCount;
	TextElement* highScoreCount;
	TextElement* highscoreNotification;

	void FreeMemory();
	void SetUpScoresText();
	void UpdateScores();

};

