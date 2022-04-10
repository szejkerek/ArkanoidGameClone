#pragma once
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Bricks.h"
#include "Stage.h"
#include "Playground.h"
class Game :public sf::Drawable
{
private:
	//Variables
	float deltaTime = 0;

	//GameObjects
	Playground playground;
	Ball ball;
	Stage stage1;

	//Methods
	void InitializeBall();

public:
	//Constructors & Destructors
	Game();
	Game(float& deltaTime);
	virtual ~Game();

	//Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update( float& dt);
};

