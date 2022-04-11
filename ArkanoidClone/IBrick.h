#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class IBrick : public sf::Drawable
{
private:
protected:
	sf::RectangleShape gameObject;
	//Game Objects
	sf::Texture texture;
	//Variables
	int hp;
	int points;
	//Methods

public:
	//Constructors & Destructors
	IBrick();

	//Methods
	virtual void OnCollisionEnter() = 0;
	void SetSize(sf::Vector2f _size);
	sf::Vector2f GetSize();
	void SetPosition(sf::Vector2f _position);
	sf::Vector2f GetPosition();
	void SetFillColor(sf::Color _color);
	virtual void SetTexture(sf::Texture _texture) = 0;
	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

