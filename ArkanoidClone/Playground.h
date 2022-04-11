#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"
#include "Ball.h"
class Playground: public sf::Drawable
{
	sf::RectangleShape gameObject;

	PositionConstrains playgroundConstrains;

	void InitialazePlayground();

public:
	Playground();
	PositionConstrains GetPositionConstrains(Ball& ball);
	sf::Vector2f GetPosition();


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

