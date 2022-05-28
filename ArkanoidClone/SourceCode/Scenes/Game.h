#pragma once
#include "Scene.h"
#include "../Entity/Ball.h"
#include "../Entity/Bricks.h"
#include "../Entity/Stage.h"
#include "../Entity/Background.h"
#include "../Entity/Vaus.h"
#include "../Entity/HealthManager.h"
#include "../Entity/HighScoreManager.h"
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
	void SelectStage(Stage* _stage/*, Background* background*/);
	void EndGame();

	//SFML Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update( float& dt);
};

