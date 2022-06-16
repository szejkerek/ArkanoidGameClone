#pragma once
#include "../Objects/Entity.h"

class HealthManager: public EntityRectangle 
{
public:
	HealthManager(GameScene* _gameScene);

	void TakeHit();
	void RestoreFullHp();
	void HealOneHealth();
	bool IsDead();
	int GetCurrentHealth();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::vector<sf::RectangleShape> possiblePlacements;
	int health;
	int maxHealth;

	sf::Vector2f CalculateHealtPositon(int index);
	void InitializePlacements();
};

