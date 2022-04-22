#include "Bricks.h"

IBrick::IBrick(): points(0)
{
	SetSize(size); //BLOCK SIZE
	SetPosition({0,0});
}

PositionConstrains IBrick::GetConstrains()
{
	PositionConstrains brickConstrains;
	brickConstrains.maxUp = GetPosition().y;
	brickConstrains.maxLeft = GetPosition().x;
	brickConstrains.maxDown = GetPosition().y + GetSize().y;
	brickConstrains.maxRight = GetPosition().x + GetSize().x;
	return brickConstrains;
}

sf::Vector2f IBrick::GetCenterPoint()
{
	float x = GetPosition().x + (GetSize().x / 2);
	float y = GetPosition().y + (GetSize().y / 2);
	return {x,y};
}

void IBrick::SetFillColor(sf::Color _color)
{
	gameObject.setFillColor(_color);
}


void IBrick::SetSize(sf::Vector2f _size)
{
	gameObject.setSize({ _size.x, _size.y });
}

sf::Vector2f IBrick::GetSize()
{
	return gameObject.getSize();
}

void IBrick::SetPosition(sf::Vector2f _position)
{
	gameObject.setPosition(_position);
}

inline sf::Vector2f IBrick::GetPosition()
{
	return gameObject.getPosition();
}


void IBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
