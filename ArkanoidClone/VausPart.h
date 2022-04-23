#pragma once
#include "SFML/Graphics.hpp"

class IVausPart: public sf::Drawable
{
protected:
	//Variables
	int directionSign = 0;
	//sf::Vector2f direction;
	sf::Vector2f positionOffset;

	//virtual void SetTexture(const sf::Texture& texture) = 0;
	virtual sf::Vector2f GetReflectionVector() = 0;
	virtual void InitGameObject(const sf::Vector2f& startingPositon, const sf::Vector2f& size, const sf::Color& color);

public:
	//GameObject
	sf::RectangleShape gameObject;

	//Constructors
	IVausPart(const sf::Vector2f& _positionOffset);

	//Methods
	virtual sf::Vector2f GetDirection();
	virtual bool IsCustomReflectionImplemented();
	virtual void SetPosition(const sf::Vector2f& position);
	virtual void SetAbsolutePosition(const sf::Vector2f& position);

	virtual sf::Vector2f GetPositionOffset();

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class BluePart : public IVausPart
{
public:
	BluePart(const sf::Vector2f& positionOffset);
	sf::Vector2f GetReflectionVector();
};

class RedPart : public IVausPart
{
public:
	RedPart(const sf::Vector2f& positionOffset);
	sf::Vector2f GetReflectionVector();
};

class GreyPart : public IVausPart
{
public:
	GreyPart(const sf::Vector2f& positionOffset);
	sf::Vector2f GetReflectionVector();
};

class CentralPart : public IVausPart
{
public:
	CentralPart(const sf::Vector2f& positionOffset);
	sf::Vector2f GetReflectionVector();
};
