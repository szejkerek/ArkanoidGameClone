#include "../Objects/PowerUp.h"
#include "../ArkanoidClone/SourceCode/Program.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"

IPowerUp::IPowerUp(Program* _program, const sf::Vector2f& position) : program(_program), EntityRectangle(_program->game, PixelSizes::GetInstance().powerUpSize)
{
	sf::Vector2f brickSize = PixelSizes::GetInstance().brickSize;
	SetOriginCenter();
	SetPosition({ position.x - 1.5f + brickSize.x / 2,  position.y - 1.5f + brickSize.y / 2 });
	bottomCollider = program->game->background->GetCollider().top + program->game->background->GetCollider().height - GetSize().y/2;
}

void IPowerUp::Hide()
{
	gameObject.setTexture(nullptr);
	gameObject.setFillColor(sf::Color(0, 0, 0, 0));
}

void IPowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

void IPowerUp::Update(float& dt)
{
	MoveDown(dt);
	CheckForCollisions();

}

void IPowerUp::MoveDown(float& dt)
{
	SetPosition({ GetPosition().x, GetPosition().y + speed * dt });
}

void IPowerUp::CheckForCollisions()
{
	PowerUpManager* tempManager = program->game->powerUpManager;
	if (GetPosition().y >= bottomCollider)
	{
		tempManager->FreeMemory();
		return;
	}
	
	for (auto part : (program->game->vaus->parts))
	{
		if (GetCollider().intersects(part->GetCollider()) && effectApplied == false)
		{
			ApplyEffect();
			effectApplied = true;
			tempManager->FreeMemory();
			return;
		}
	}
}

AddHealth::AddHealth(Program* _program, const sf::Vector2f& position) : IPowerUp(_program, position)
{
}

void AddHealth::ApplyEffect()
{
	program->game->healthManager->HealOneHealth();
}

SplitBall::SplitBall(Program* _program, const sf::Vector2f& position) : IPowerUp(_program, position)
{
}
