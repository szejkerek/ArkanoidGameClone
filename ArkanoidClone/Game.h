#pragma once
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Bricks.h"
#include "Stage.h"
#include "Playground.h"
#include "Vaus.h"
#include "HealthManager.h"
class Game :public sf::Drawable
{
private:
	//Variables
	float deltaTime = 0;

	//GameObjects
	Playground playground;

	Ball* ball;
	Vaus* vaus;
	Stage* currentStage;
	HealthManager healthManager;

	//Methods
	Ball* InitializeBall(const sf::Vector2f& _stratingPosition,const sf::Vector2f& startingDireciton);
	void InitializeStage(int stageLvl);

public:
	//Constructors & Destructors
	Game(float& deltaTime);
	virtual ~Game();

	//Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update( float& dt);
};

