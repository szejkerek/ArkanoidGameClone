#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"
#include "Ball.h"
class Playground: public sf::Drawable
{
	//Variables
	sf::RectangleShape gameObject;
	PositionConstrains playgroundConstrains;

	//Methods
	void InitialazePlayground();

public:
	Playground();
	sf::Vector2f GetPosition();
	PositionConstrains GetPositionConstrains(Ball& ball);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

