#include "PowerUpManager.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "../ArkanoidClone/SourceCode/Program.h"

PowerUpManager::PowerUpManager(Program* _program) : program(_program), currentPowerUp(nullptr)
{
}

PowerUpManager::~PowerUpManager()
{
	FreeMemory();
}

void PowerUpManager::PickRandomPowerUp(const sf::Vector2f& position)
{


	if (!blocked)
	{		
		srand(time(NULL));
		FreeMemory();
			
			int firstRand = rand() % 100 + 1;
			int secondRand = rand() % (splitChance + healChance + slowChance/* + stickChance + enlargeChance*/) + 1;

			if (firstRand <= powerUpChance)
			{
				FreeMemory();
				if (secondRand <= healChance)
				{
					currentPowerUp = new AddHealth(program, position);
				}
				else if (secondRand <= healChance + splitChance)
				{
					currentPowerUp = new SplitBall(program, position);
				}
				else if (secondRand <= healChance + splitChance + slowChance)
				{
					currentPowerUp = new SlowDown(program, position);

				}
				else if (secondRand <= healChance + splitChance + slowChance + stickChance)
				{

				}
				else if (secondRand <= healChance + splitChance + slowChance + stickChance + enlargeChance)
				{

				}
				blocked = true;
			}
	}

}
			


	


void PowerUpManager::ChangeAllBallsSpeed(const float& newSpeed)
{
	
	for (size_t i = 0; i < program->game->balls.size(); i++)
	{
		program->game->balls[i]->ChangeBallSpeed(newSpeed);
	}
	BlockPowerUpsForTime(8.f);
}

void PowerUpManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(currentPowerUp != nullptr)
		target.draw(*currentPowerUp);
}

void PowerUpManager::Update(float& dt)
{
	if (currentPowerUp != nullptr)
		currentPowerUp->Update(dt);

	if (blockedForTime)
	{
		powerUpTimer -= dt;
		if (powerUpTimer <= 0)
		{
			powerUpTimer = 0;
			powerUpTimer = defaultPowerUpTimer;
			ChangeAllBallsSpeed(800);
			blockedForTime = false;
			blocked = false;
		}
	}
}

void PowerUpManager::FreeMemory()
{
	if(currentPowerUp != nullptr)
		delete currentPowerUp;

	currentPowerUp = nullptr;

	if (!blockedForTime)
		blocked = false;

}

void PowerUpManager::BlockPowerUpsForTime(const float& time)
{
	defaultPowerUpTimer = time;
	powerUpTimer = defaultPowerUpTimer;
	blockedForTime = true;
	blocked = true;
}
