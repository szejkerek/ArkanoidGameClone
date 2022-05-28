#pragma once
#include "Scene.h"
#include "../Entity/Objects/Ball.h"
#include "../Entity/Objects/Bricks.h"
#include "../Entity/Managers/Stage.h"
#include "../Entity/Objects/Background.h"
#include "../Entity/Objects/Vaus.h"
#include "../Entity/Managers/HealthManager.h"
#include "../Entity/Managers/HighScoreManager.h"
#include "../ArkanoidClone/SourceCode/UI/TextElement.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
class GameScene : public Scene
{
private:
	int currentScore = 0;
	int currentHighscore = 0;
	bool playable;

	TextElement* highScoreLabel;
	TextElement* scoreLabel;
	TextElement* scoreCount;
	TextElement* highScoreCount;
	TextElement* highscoreNotification;

	//Methods
	void InitializeBall();
	void InitVariables();	
	void FreeMemory();

	void SetUpScoresText();
	void UpdateScores();

public:
	Program* program;

	//GameObjects
	Background* background;
	Ball* ball;
	Vaus* vaus;
	Stage* currentStage;
	HealthManager* healthManager;
	

	//Variables
	float ballAirTime = 0;

	//Constructors & Destructors
	GameScene(Program* _program, float& deltaTime);
	virtual ~GameScene();

	//Methods
	void StartGame();
	void AddPoints(const int& brickPoint);
	void SelectStage(Stage* _stage);
	void EndGame();

	//SFML Methods
	void Update( float& dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

