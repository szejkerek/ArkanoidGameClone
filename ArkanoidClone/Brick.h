#pragma once
#include "SFML/Graphics.hpp"
class Brick : public sf::Drawable
{
protected:
	//Game Objects
	sf::RectangleShape gameObject;
	sf::Texture texture;
	//Variables
	int hp;
	int points;
	sf::Vector2f position;
	//Methods


public:
	//Constructors & Destructors
	Brick();

	//Methods
	virtual void OnCollisionEnter() = 0;
	void SetPosition(sf::Vector2f _position);
	void SetFillColor(sf::Color _color);
	void SetTexture(sf::Texture _texture);
	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

