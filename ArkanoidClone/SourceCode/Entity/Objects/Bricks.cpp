#include "Bricks.h"
#include "../ArkanoidClone/SourceCode/Utility/Resources.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"


IBrick::IBrick(bool destructible, GameScene* _game): points(0), EntityRectangle(_game,{0,0}), destructible(true)
{
	SetSize(PixelSizes::GetInstance().brickSize); //BLOCK SIZE
	SetTexture(ResourceManager::Get().GetTexture("brick"));
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
	SetPosition({ init.x + GetSize().x * collumn, init.y + GetSize().y * row });
}

void IBrick::SetPoints(const int& _points)
{
	points = _points;
}

int IBrick::GetPoints()
{
	return points;
}

int IBrick::GetHp()
{
	return 1;
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
	goldTexture = ResourceManager::Get().GetTexture("goldBricks");
	destructible = false;
	textureRect.width = GetSize().x;
	textureRect.height = GetSize().y;

	SetTexture(goldTexture);
	gameObject.setTextureRect(textureRect);
}

void GoldBrick::Animate()
{
	if (doAnimate)
		return;

	doAnimate = true;
	timer = defaultTimer;
	textureRect.left = 0;
}

void GoldBrick::PickNextTexture()
{
	if (textureRect.left >= textureRect.width * 11)
	{
		doAnimate = false;
		textureRect.left = 0;
	}
	else
	{
		textureRect.left += GetSize().x;
	}

		gameObject.setTextureRect(textureRect);
}

void GoldBrick::Update(float& dt)
{
	if (!doAnimate)
		return;

	timer -= dt;

	if (timer <= 0)
	{
		PickNextTexture();
		timer = defaultTimer;
	}
}
bool GoldBrick::OnCollisionEnter()
{
	Animate();
	return false; //Never gets destroyed
}


bool DecideIfBrickDestroyed(int hp)
{
	return (hp <= 0);
}

inline int CalculateHealth(int stageNumber)
{
	return static_cast<int>(2 + (stageNumber / 8)); //2hp at the beginning, then each 8lvls +1hp
}


SilverBrick::SilverBrick(int stageNumber) : IBrick(true, gameScene), hp(CalculateHealth(stageNumber))
{
	maxHp = hp;
	destructible = true;
	SetPoints(stageNumber * 50);

	textureRect.width = PixelSizes::GetInstance().brickSize.x;
	textureRect.height = PixelSizes::GetInstance().brickSize.y;

	SetTexture(ResourceManager::Get().GetTexture("silverBricks"));
	ApplyTexture(0);

}

void SilverBrick::PickBrokenTexutre()
{
	float f_maxHp = static_cast<float>(maxHp);
	float f_hp = static_cast<float>(hp);
	float destroyPercent = (f_hp / f_maxHp) * 100;

	if (destroyPercent == 100)
	{
		ApplyTexture(0);
	}
	else if (destroyPercent >= 83.2f)
	{
		ApplyTexture(1);
	}
	else if (destroyPercent >= 66.5f)
	{
		ApplyTexture(2);
	}
	else if (destroyPercent >= 50.f)
	{
		ApplyTexture(3);
	}
	else if (destroyPercent >= 33.2f)
	{
		ApplyTexture(4);
	}
	else if (destroyPercent >= 16.5f)
	{
		ApplyTexture(5);
	}
}

void SilverBrick::ApplyTexture(int textureIndex)
{
	if (textureIndex <= 0)
		textureIndex = 0;
	else if (textureIndex >= 5)
		textureIndex = 5;

	textureRect.left = GetSize().x * textureIndex;
	gameObject.setTextureRect(textureRect);
}

bool SilverBrick::OnCollisionEnter()
{
	hp--;
	PickBrokenTexutre();
	return DecideIfBrickDestroyed(hp);
}
bool ColorBrick::OnCollisionEnter()
{
	return true; //Always gets destroyed
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
		SetTexture(ResourceManager::Get().GetTexture("whiteBrick"));
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

BossBrick::BossBrick() : IBrick(true, gameScene), hp(64)
{
	sf::Vector2f s = PixelSizes::GetInstance().backgroundSize;
	sf::Vector2f p = PixelSizes::GetInstance().backgroundPosition;

	destructible = true;
	SetPoints(10000000);

	
	SetSize({ 400,400 });
	SetPosition({p.x + s.x/2 - GetSize().x/2, p.y + s.y / 2 - GetSize().y/2 });
	//SetFillColor(sf::Color::Red);
	gameObject.setTextureRect(sf::IntRect(0, 0, 400, 400));
	gameObject.setTexture(ResourceManager::Get().GetTexture("bossBrick"));
}

bool BossBrick::OnCollisionEnter()
{
	hp--;
	return DecideIfBrickDestroyed(hp);
}
