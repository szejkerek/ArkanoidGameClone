#pragma once
#include "Entity.h"

class IVausPart: public EntityRectangle 
{
public:
	IVausPart(GameScene* game, const sf::Vector2f& _positionOffset);

	virtual sf::Vector2f GetDirection();
	virtual bool IsCustomReflectionImplemented();
	virtual void SetPosition(const sf::Vector2f& position);
	virtual sf::Vector2f GetPositionOffset();
	virtual void PlayAnimation() {};
	virtual void Update(float& dt) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	int directionSign = 0;
	sf::Vector2f positionOffset;

	virtual sf::Vector2f GetReflectionVector() = 0;
	virtual void InitGameObject(const sf::Vector2f& startingPositon, const sf::Vector2f& size);
};

class BluePart : public IVausPart
{
public:
	BluePart(const sf::Vector2f& positionOffset);

	sf::Vector2f GetReflectionVector();
	void PlayAnimation();
	void Update(float& dt);

private:
	sf::IntRect textureRect;
	bool doAnimate = false;
	float timer;
	float defaultTimer = 0.09f;

	void NextTexture();
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
