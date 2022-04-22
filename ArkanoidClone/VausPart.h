#pragma once
#include "SFML/Graphics.hpp"
enum class ReflectionTurnType 
{
	left,
	none,
	right
};

class IVausPart: public sf::Drawable
{
private:
	ReflectionTurnType reflectionType;

protected:
	//Variables
	int directionSign = 0;
	sf::Vector2f direction;
	//virtual void SetTexture(const sf::Texture& texture) = 0;
	virtual sf::Vector2f GetReflectionVector() = 0;
	virtual void InitGameObject(const sf::Vector2f& size, const sf::Color& color);

public:
	//GameObject
	sf::RectangleShape gameObject;

	//Constructors
	IVausPart(const ReflectionTurnType& type);

	//Methods
	virtual sf::Vector2f GetDirection();
	virtual bool IsCustomReflectionImplemented();
	virtual void SetPosition(const sf::Vector2f& position);

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class BluePart : public IVausPart
{
public:
	BluePart(const ReflectionTurnType& type);
	sf::Vector2f GetReflectionVector();
};

class RedPart : public IVausPart
{
public:
	RedPart(const ReflectionTurnType& type);
	sf::Vector2f GetReflectionVector();
};

class GreyPart : public IVausPart
{
public:
	GreyPart(const ReflectionTurnType& type);
	sf::Vector2f GetReflectionVector();
};

class CentralPart : public IVausPart
{
public:
	CentralPart(const ReflectionTurnType& type);
	sf::Vector2f GetReflectionVector();
};
