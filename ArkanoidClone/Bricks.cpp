#include "Bricks.h"

GoldBrick::GoldBrick()
{

}


SilverBrick::SilverBrick(int stageNumber)
{

}


ColorBrick::ColorBrick(ColorsEnum color)
{

	switch (color)
	{
	case ColorsEnum::blue:
		SetFillColor(sf::Color::Blue);
		break;
	case ColorsEnum::green:
		SetFillColor(sf::Color::Green);
		break;
	case ColorsEnum::orange:
		SetFillColor(sf::Color::Color(255, 165, 0, 255));
		break;
	case ColorsEnum::pink:
		SetFillColor(sf::Color::Magenta);
		break;
	case ColorsEnum::red:
		SetFillColor(sf::Color::Red);
		break;
	case ColorsEnum::white:
		SetFillColor(sf::Color::White);
		break;
	case ColorsEnum::turquoise:
		SetFillColor(sf::Color::Color(48, 213, 200, 255));
		break;
	case ColorsEnum::yelow:
		SetFillColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
}

void ColorBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

void GoldBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

void SilverBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}