#pragma once
#include "SFML/Graphics.hpp"
#include "VausPart.h"
class Vaus: public sf::Drawable
{
	//GameObjects
	sf::RectangleShape hitbox;
	CentralPart* central;
	
	//Variables
	sf::Vector2f direction;
	sf::Vector2f position;
	float speed = 110.f;
	void Move(float& dt);

public:
	Vaus();
	~Vaus();

	//SFML methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);
};

