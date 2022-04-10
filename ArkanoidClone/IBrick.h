#pragma once
#include "SFML/Graphics.hpp"
class IBrick : public sf::Drawable
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
	IBrick();

	//Methods
	virtual void OnCollisionEnter() = 0;
	void SetPosition(sf::Vector2f _position);
	void SetFillColor(sf::Color _color);
	virtual void SetTexture(sf::Texture _texture) = 0;
	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

