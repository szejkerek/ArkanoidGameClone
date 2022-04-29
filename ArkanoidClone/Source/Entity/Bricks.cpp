#include "Bricks.h"

IBrick::IBrick(Game* _game): points(0), EntityRectangle(_game,{0,0})
{
	SetSize(PixelSizes::GetInstance().brickSize); //BLOCK SIZE
}

sf::Vector2f IBrick::GetCenterPoint()
{
	float x = GetPosition().x + (GetSize().x / 2);
	float y = GetPosition().y + (GetSize().y / 2);
	return {x,y};
}


void IBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

GoldBrick::GoldBrick() : IBrick(gameScene)
{
	SetFillColor(sf::Color::Color(181, 166, 66, 255));
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

SilverBrick::SilverBrick(int stageNumber) : IBrick(gameScene), hp(CalculateHealth(stageNumber))
{
	SetFillColor(sf::Color::Color(196, 202, 206));
}

ColorBrick::ColorBrick(ColorsEnum color) : IBrick(gameScene)
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
