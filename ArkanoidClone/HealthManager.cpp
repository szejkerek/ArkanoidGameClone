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
		sf::RectangleShape temp = gameObject;
		temp.setPosition(CalculateHealtPositon(i));
		possiblePlacements.push_back(temp);
	}
}

HealthManager::HealthManager() : health(3), maxHealth(11), EntityRectangle(PixelSizes::GetInstance().healthSize)
{
	SetPosition(PixelSizes::GetInstance().healthPosition);
	SetFillColor(sf::Color::Red);
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
