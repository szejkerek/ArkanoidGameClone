#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"
#include "Ball.h"
class Playground: public sf::Drawable
{
	sf::RectangleShape gameObject;
	sf::RectangleShape outlineLeft;
	sf::RectangleShape outlineTop;
	sf::RectangleShape outlineRight;

	PositionConstrains playgroundConstrains;

	void InitialazePlayground();
	void InitialazeOutLine();

public:
	Playground();
	PositionConstrains GetPositionConstrains(Ball& ball);


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

