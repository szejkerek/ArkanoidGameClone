#include "Block.h"

Block::Block(sf::Vector2f position)
{
	gameObject.setSize({ 70,30 });
	gameObject.setPosition(position);
	gameObject.setFillColor(sf::Color::Color(12, 55, 123, 255));
	gameObject.setOutlineColor(sf::Color::White);
	gameObject.setOutlineThickness(1);
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
