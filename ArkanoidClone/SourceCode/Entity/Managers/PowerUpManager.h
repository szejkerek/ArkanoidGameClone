#pragma once
#include "SFML/Graphics.hpp"
#include "../Objects/PowerUp.h"

class Program;
class PowerUpManager : public sf::Drawable
{
public: 
	PowerUpManager(Program* _program);
	void PickRandomPowerUp(const sf::Vector2f& position);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);
private:
	float powerUpChance = 75;  // x%
	IPowerUp* currentPowerUp;
	bool blocked = false;
	Program* program;
	void FreeMemory();

};

