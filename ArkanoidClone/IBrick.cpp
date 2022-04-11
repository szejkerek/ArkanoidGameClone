#include "Bricks.h"

IBrick::IBrick(): hp(0), points(0)
{
	SetSize(size); //BLOCK SIZE
	SetPosition({0,0});
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

void IBrick::SetFillColor(sf::Color _color)
{
	gameObject.setFillColor(_color);
}

void IBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
