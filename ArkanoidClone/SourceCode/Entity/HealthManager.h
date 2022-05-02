#pragma once
#include "Entity.h"

class HealthManager: public EntityRectangle 
{
private:
	std::vector<sf::RectangleShape> possiblePlacements;

	int health;
	int maxHealth;

	sf::Vector2f CalculateHealtPositon(int index);
	void InitializePlacements();

public:
	HealthManager(GameScene* _gameScene);
	void TakeHit();
	bool IsDead();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

