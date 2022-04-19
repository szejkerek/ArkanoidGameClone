#pragma once
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Bricks.h"
#include "Stage.h"
#include "Playground.h"
#include "Vaus.h"
class Game :public sf::Drawable
{
private:
	//Variables
	float deltaTime = 0;

	//GameObjects
	Playground playground;
	Ball* ball;
	Vaus* vaus;

	Stage* stage1;

	//Methods
	Ball* InitializeBall(sf::Vector2f _stratingPosition, sf::Vector2f startingDireciton);
	void InitializeStage();

public:
	//Constructors & Destructors
	Game(float& deltaTime);
	virtual ~Game();

	//Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update( float& dt);
};

