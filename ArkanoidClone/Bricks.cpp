#include "Bricks.h"

GoldBrick::GoldBrick()
{
	SetFillColor(sf::Color::Color(181,166,66,255));
}

bool GoldBrick::OnCollisionEnter()
{
	return false; //Never gets destroyed
}

bool DecideIfBrickDestroyed(int hp)
{
	return (hp <= 0);
}

bool SilverBrick::OnCollisionEnter()
{
	hp--;
	return DecideIfBrickDestroyed(hp);
}
bool ColorBrick::OnCollisionEnter()
{
	return true; //Always gets destroyed
}

inline int CalculateHealth(int stageNumber)
{
	return 2 + (stageNumber >> 3); //2hp at the beginning, then each 8lvls +1hp
}

SilverBrick::SilverBrick(int stageNumber): hp(CalculateHealth(stageNumber))
{
	SetFillColor(sf::Color::Color(196,202,206));
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