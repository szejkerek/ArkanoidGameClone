#pragma once
#include "SFML/Graphics.hpp"
#include "../Objects/Entity.h"
#include <iostream>

class Program;
class IPowerUp : public EntityRectangle
{
public:
	IPowerUp(Program* _program, const sf::Vector2f& position);
	virtual void ApplyEffect() = 0;
	void Hide();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);
	
protected:
	Program* program;
	float speed = 250.f;
	void MoveDown(float& dt);
};

class AddHealth : public IPowerUp
{
public:
	AddHealth(Program* _program, const sf::Vector2f& position);
	void ApplyEffect() { std::cout << "ADD HEALTH" << std::endl; }
};

class SplitBall : public IPowerUp
{
public:
	SplitBall(Program* _program, const sf::Vector2f& position);
	void ApplyEffect() { std::cout << "SPLIT BALL" << std::endl; }
};