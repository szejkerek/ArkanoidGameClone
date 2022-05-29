#include "PowerUpManager.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

PowerUpManager::PowerUpManager(Program* _program) : program(_program), currentPowerUp(nullptr)
{
}

void PowerUpManager::PickRandomPowerUp(const sf::Vector2f& position)
{
	if (!blocked)
	{		
		srand(time(NULL));
		FreeMemory();
			
	/*	for (size_t i = 0; i < 10000; i++)
		{*/
			int firstRand = rand() % 100 + 1;
			int secondRand = rand() % (splitChance + healChance /*+ slowChance + stickChance + enlargeChance*/) + 1;

			if (firstRand <= 100)
			{
				if (secondRand <= healChance)
				{
					currentPowerUp = new AddHealth(program, position);
					std::cout << "Heal" << std::endl;

					//healC++;
				}
				else if (secondRand <= healChance + splitChance)
				{
					currentPowerUp = new SplitBall(program, position);
					std::cout << "Split" << std::endl;
					//splitC++;
				}
				else if (secondRand <= healChance + splitChance + slowChance)
				{
					//std::cout << "Slow" << std::endl;
					//slowC++;

				}
				else if (secondRand <= healChance + splitChance + slowChance + stickChance)
				{
					//std::cout << "Stick" << std::endl;
					//stickC++;
				}
				else if (secondRand <= healChance + splitChance + slowChance + stickChance + enlargeChance)
				{
					//std::cout << "Enlarge" << std::endl;
					//enlargeC++;
				}
				blocked = true;
			}
		//}
			
			


			//std::cout << "POWER UPS CHANCES" << std::endl;
			//std::cout << "healC: " << ((float)healC) / 10000 << "%" << std::endl;
			//std::cout << "splitC: " << ((float)splitC) / 10000 << "%" << std::endl;
			//std::cout << "slowC: " << ((float)slowC) / 10000 << "%" << std::endl;
			//std::cout << "enlargeC: " << ((float)enlargeC) / 10000 << "%" << std::endl;
			//std::cout << "stickC: " << ((float)stickC) / 10000 << "%" << std::endl;
			//std::cout << std::endl << std::endl << std::endl;
	}
			


	//healC = 0;
	//splitC = 0;
	//slowC = 0;
	//enlargeC = 0;
	//stickC = 0;
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
}

void PowerUpManager::FreeMemory()
{
	if(currentPowerUp != nullptr)
		delete currentPowerUp;

	currentPowerUp = nullptr;
	blocked = false;

}
