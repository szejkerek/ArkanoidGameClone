#include "Playground.h"
#include "Utility.h"

void Playground::InitGameObject()
{
	SetPosition(PixelSizes::GetInstance().playgroundPosition);
	SetSize(PixelSizes::GetInstance().playgroundSize);
	SetFillColor(sf::Color::Color(10,10,10));
}

Playground::Playground():EntityRectangle(PixelSizes::GetInstance().playgroundPosition)
{
	InitGameObject();
}

void Playground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
