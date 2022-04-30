#pragma once
#include "Scene.h"
#include "../Entity/Ball.h"
#include "../Entity/Bricks.h"
#include "../Entity/Stage.h"
#include "../Entity/Playground.h"
#include "../Entity/Vaus.h"
#include "../Entity/HealthManager.h"
class Game : public Scene
{
private:

	bool playable;

	//Methods
	void InitializeBall();
	void InitVariables(int stageLvl);
	void FreeMemory();

public:
	Program* program;

	//GameObjects
	Playground* playground;
	Ball* ball;
	Vaus* vaus;
	Stage* currentStage;
	HealthManager* healthManager;

	//Variables
	float ballAirTime = 0;

	//Constructors & Destructors
	Game(Program* _program, float& deltaTime);
	virtual ~Game();

	//Methods
	void StartGame();
	void SelectStage(Stage* _stage);
	void EndGame();

	//SFML Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update( float& dt);
};

