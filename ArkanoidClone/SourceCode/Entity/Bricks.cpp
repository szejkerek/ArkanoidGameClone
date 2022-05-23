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

void IBrick::SetPoints(const int& _points)
{
	points = _points;
}

int IBrick::GetPoints()
{
	return points;
}

inline bool IBrick::IsDestructible()
{
	return destructible;
}


void IBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

GoldBrick::GoldBrick() : IBrick(false,gameScene)
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
	SetPoints(stageNumber * 50);

	SetFillColor(sf::Color::Color(196, 202, 206));
}

ColorBrick::ColorBrick(ColorsEnum color) : IBrick(true, gameScene)
{
	destructible = true;

	switch (color)
	{
	case ColorsEnum::blue:
		SetFillColor(sf::Color::Blue);
		SetPoints(100);

		break;
	case ColorsEnum::green:
		SetFillColor(sf::Color::Green);
		SetPoints(80);

		break;
	case ColorsEnum::orange:
		SetFillColor(sf::Color::Color(255, 165, 0, 255));
		SetPoints(60);

		break;
	case ColorsEnum::pink:
		SetFillColor(sf::Color::Magenta);
		SetPoints(110);

		break;
	case ColorsEnum::red:
		SetFillColor(sf::Color::Red);
		SetPoints(90);

		break;
	case ColorsEnum::white:
		SetFillColor(sf::Color::White);
		SetPoints(50);

		break;
	case ColorsEnum::turquoise:
		SetFillColor(sf::Color::Color(48, 213, 200, 255));
		SetPoints(70);

		break;
	case ColorsEnum::yelow:
		SetFillColor(sf::Color::Yellow);
		SetPoints(120);

		break;
	default:
		break;
	}
}
