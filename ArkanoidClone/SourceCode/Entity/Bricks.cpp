#include "Bricks.h"
#include "../Utility/Resources.h"

IBrick::IBrick(bool destructible, GameScene* _game): points(0), EntityRectangle(_game,{0,0}), destructible(true)
{
	SetSize(PixelSizes::GetInstance().brickSize); //BLOCK SIZE
	gameObject.setTexture(ResourceManager::Get().GetTexture("brick"));
}

sf::Vector2f IBrick::GetCenterPoint()
{
	float x = GetPosition().x + (GetSize().x / 2);
	float y = GetPosition().y + (GetSize().y / 2);
	return {x,y};
}

inline void IBrick::SetRelativePosition(int row, int collumn)
{
	sf::Vector2f init = PixelSizes::GetInstance().backgroundPosition;
	SetPosition({ init.x + GetSize().x * collumn, init.y + GetSize().y * row, });
}

inline bool IBrick::IsDestructible()
{
	return destructible;
}


void IBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

GoldBrick::GoldBrick() : IBrick(false, gameScene)
{
	destructible = false;
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

SilverBrick::SilverBrick(int stageNumber) : IBrick(true, gameScene), hp(CalculateHealth(stageNumber))
{
	destructible = true;
	SetFillColor(sf::Color::Color(196, 202, 206));
}

ColorBrick::ColorBrick(ColorsEnum color) : IBrick(true, gameScene)
{
	destructible = true;

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
