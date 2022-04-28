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

GoldBrick::GoldBrick()
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

SilverBrick::SilverBrick(int stageNumber) : hp(CalculateHealth(stageNumber))
{
	SetFillColor(sf::Color::Color(196, 202, 206));
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
