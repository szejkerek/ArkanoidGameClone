#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"
#include <iostream>
class IBrick : public sf::Drawable
{
public:
	sf::RectangleShape gameObject;
private:
protected:
	//Game Objects
	sf::Texture texture;

	//Variables
	sf::Vector2f size = PixelSizes::GetInstance().brickSize;
	int hp;
	int points;

	//Methods

public:
	
	//Constructors & Destructors
	IBrick();
	~IBrick() { std::cout << "Brick destructor" << std::endl; }

	//Methods
	void SetPosition(sf::Vector2f _position);
	void SetFillColor(sf::Color _color);
	void SetSize(sf::Vector2f _size);
	virtual void SetTexture(sf::Texture _texture) = 0;
	sf::Vector2f GetSize();
	sf::Vector2f GetPosition();
	PositionConstrains GetConstrains();
	sf::Vector2f GetCenterPoint();

	//Getters&Setters
	virtual void OnCollisionEnter() = 0;

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

