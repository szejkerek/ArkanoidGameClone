#include "Playground.h"

void Playground::InitialazePlayground()
{
	gameObject = sf::RectangleShape({ 713.f,858.f });
	gameObject.setPosition({ 183,62 });
	gameObject.setFillColor(sf::Color::Black);
	gameObject.setOutlineThickness(30.f);
	gameObject.setOutlineColor(sf::Color::Color(0, 0, 255, 45));
}

Playground::Playground()
{
	InitialazePlayground();
}

PositionConstrains Playground::GetPositionConstrains(Ball& ball)
{
	playgroundConstrains.maxLeft = gameObject.getPosition().x;
	playgroundConstrains.maxUp = gameObject.getPosition().y;
	playgroundConstrains.maxRight = gameObject.getPosition().x + gameObject.getSize().x - 2 * ball.GetRadius();
	playgroundConstrains.maxDown = gameObject.getPosition().y + gameObject.getSize().y - 2 * ball.GetRadius();
	return playgroundConstrains;
}

void Playground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
