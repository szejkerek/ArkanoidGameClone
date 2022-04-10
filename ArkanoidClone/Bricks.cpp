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
		gameObject.setFillColor(sf::Color::Blue);
		break;
	case ColorsEnum::green:
		gameObject.setFillColor(sf::Color::Green);
		break;
	case ColorsEnum::orange:
		gameObject.setFillColor(sf::Color::Color(255, 165, 0, 255));
		break;
	case ColorsEnum::pink:
		gameObject.setFillColor(sf::Color::Magenta);
		break;
	case ColorsEnum::red:
		gameObject.setFillColor(sf::Color::Red);
		break;
	case ColorsEnum::white:
		gameObject.setFillColor(sf::Color::White);
		break;
	case ColorsEnum::turquoise:
		gameObject.setFillColor(sf::Color::Color(48, 213, 200, 255));
		break;
	case ColorsEnum::yelow:
		gameObject.setFillColor(sf::Color::Yellow);
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