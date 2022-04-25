#pragma once
#include <SFML/Graphics.hpp>

class HealthManager: public sf::Drawable
{
private:
	sf::RectangleShape healthObject;
	std::vector<sf::RectangleShape> possiblePlacements;

	int health;
	int maxHealth;

	sf::Vector2f CalculateHealtPositon(int index);
	void InitializePlacements();

public:
	HealthManager();
	void TakeHit();
	bool IsDead();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

