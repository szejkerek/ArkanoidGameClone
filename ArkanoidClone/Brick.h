#pragma once
#include "SFML/Graphics.hpp"
class Brick : public sf::Drawable
{
private:
	//Game Objects
	sf::RectangleShape gameObject;
	//Variables
	int hp;
	int points;
	sf::Vector2f position;
	//Methods


public:
	//Constructors & Destructors
	Brick() {}
	Brick(sf::Vector2f position);

	//Methods
	virtual void OnCollisionEnter() = 0;
	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

