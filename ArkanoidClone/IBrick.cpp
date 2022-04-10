#include "Bricks.h"

IBrick::IBrick(): hp(0), points(0), position({ 0.f,0.f })
{
	gameObject.setSize({ 55,28 }); //BLOCK SIZE
	gameObject.setPosition({0,0});
	hp = 0;
	points = 0;
}

void IBrick::SetPosition(sf::Vector2f _position)
{
	gameObject.setPosition(_position);
	position = _position;
}

void IBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
