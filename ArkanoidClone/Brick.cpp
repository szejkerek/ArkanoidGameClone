#include "Brick.h"

Brick::Brick(): hp(0), points(0), position({ 0.f,0.f })
{
	gameObject.setSize({ 70,30 }); //BLOCK SIZE
	gameObject.setPosition({0,0});
	gameObject.setFillColor(sf::Color::Color(12, 55, 123, 255));
	gameObject.setOutlineColor(sf::Color::White);
	gameObject.setOutlineThickness(1);
	hp = 0;
	points = 0;
}

void Brick::SetPosition(sf::Vector2f _position)
{
	gameObject.setPosition(_position);
	position = _position;
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
