#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"

class IBrick : public sf::Drawable
{
public:
	sf::RectangleShape gameObject;
protected:
	//Game Objects
	sf::Texture texture;

	//Variables
	sf::Vector2f size = PixelSizes::GetInstance().brickSize;
	int points;

public:
	
	//Constructors & Destructors
	IBrick();
	~IBrick() {}

	//Methods
	void SetPosition(sf::Vector2f _position);
	void SetFillColor(sf::Color _color);
	void SetSize(sf::Vector2f _size);
	virtual void SetTexture(sf::Texture _texture) {};
	sf::Vector2f GetSize();
	sf::Vector2f GetPosition();
	PositionConstrains GetConstrains();
	sf::Vector2f GetCenterPoint();

	//Getters&Setters
	virtual bool OnCollisionEnter() = 0;  //Returns true when brick is to be destroyed

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class GoldBrick : public IBrick
{
public:
	GoldBrick();
	bool OnCollisionEnter(); //Can never be destroyed
};

class SilverBrick : public IBrick
{
private:
	int hp;
public:
	SilverBrick(int stageNumber);
	bool OnCollisionEnter();
};

class ColorBrick : public IBrick
{
public:
	ColorBrick(ColorsEnum color);
	bool OnCollisionEnter();
};