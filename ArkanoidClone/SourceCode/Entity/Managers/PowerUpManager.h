#pragma once
#include "SFML/Graphics.hpp"
#include "../Objects/PowerUp.h"

class Program;
class PowerUpManager : public sf::Drawable
{
public: 
	PowerUpManager(Program* _program);
	~PowerUpManager();

	void PickRandomPowerUp(const sf::Vector2f& position);
	void FreeMemory();

	void BlockPowerUpsForTime(const float& time);
	void BlockPowerUps();
	void UnblockPowerUps();

	void ChangeAllBallsSpeed(const float& newSpeed);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);
private:
	
	IPowerUp* currentPowerUp;
	bool blocked = false;
	bool blockedForTime = false;
	float defaultPowerUpTimer = 8.f;
	float powerUpTimer = 8.f;



	Program* program;

	int powerUpChance = 100;  // x%
	int healChance = 33; 
	int splitChance = 33;  
	int slowChance = 33;  
	int enlargeChance = 20;  
	int stickChance = 20;  
};

