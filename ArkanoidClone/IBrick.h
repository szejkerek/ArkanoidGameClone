#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"
class IBrick : public sf::Drawable
{
private:
protected:
	sf::RectangleShape gameObject;

	//Game Objects
	sf::Texture texture;

	//Variables
	sf::Vector2f size{58,22};
	int hp;
	int points;

	//Methods

public:
	//Constructors & Destructors
	IBrick();

	//Methods
	void SetPosition(sf::Vector2f _position);
	void SetFillColor(sf::Color _color);
	void SetSize(sf::Vector2f _size);
	virtual void SetTexture(sf::Texture _texture) = 0;
	sf::Vector2f GetSize();
	sf::Vector2f GetPosition();

	//Getters&Setters
	virtual void OnCollisionEnter() = 0;

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

