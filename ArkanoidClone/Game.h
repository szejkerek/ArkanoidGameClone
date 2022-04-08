#pragma once
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Brick.h"
#include "GoldBrick.h"
class Game :public sf::Drawable
{
private:
	//Variables
	float deltaTime = 0;

	//GameObjects
	sf::RectangleShape playground;
	Ball ball;
	GoldBrick gold;
	GoldBrick gold1;
	GoldBrick gold2;

	//Methods
	void InitializePlayground();
	void InitializeBall();

public:
	//Constructors & Destructors
	Game();
	Game(const float& deltaTime);
	virtual ~Game();

	//Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update( float& dt);
};

