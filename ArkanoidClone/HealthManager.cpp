#include "HealthManager.h"
#include "Utility.h"
#include <iostream>

sf::Vector2f HealthManager::CalculateHealtPositon(int index)
{
	sf::Vector2f tempPosition = PixelSizes::GetInstance().healthPosition;
	sf::Vector2f healthSize = PixelSizes::GetInstance().healthSize;
	int healtSpacing = PixelSizes::GetInstance().healtSpacing;

	for (int i = 0; i < index; i++)
		tempPosition.x += healthSize.x + healtSpacing;

	return tempPosition;
}

void HealthManager::InitializePlacements()
{
	for (int i = 0; i < maxHealth; i++)
	{
		
		sf::RectangleShape temp = healthObject;
		temp.setPosition(CalculateHealtPositon(i));
		possiblePlacements.push_back(temp);
	}
}

HealthManager::HealthManager() : health(3), maxHealth(11)
{
	std::cout << PixelSizes::GetInstance().healthPosition.x << std::endl;
	std::cout << PixelSizes::GetInstance().healthPosition.y << std::endl;
	healthObject.setPosition(PixelSizes::GetInstance().healthPosition);
	healthObject.setSize(PixelSizes::GetInstance().healthSize);
	healthObject.setFillColor(sf::Color::Red);
	InitializePlacements();
}

void HealthManager::TakeHit()
{
	health--;

	if (health < 0)
		health = 0;

}

bool HealthManager::IsDead()
{
	return (health <= 0);	
}

void HealthManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < health; i++)
	{
		target.draw(possiblePlacements[i]);
	}
}
