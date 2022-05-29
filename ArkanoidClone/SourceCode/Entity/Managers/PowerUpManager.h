#pragma once
#include "SFML/Graphics.hpp"
#include "../Objects/PowerUp.h"

class Program;
class PowerUpManager : public sf::Drawable
{
public: 
	PowerUpManager(Program* _program);

	void PickRandomPowerUp(const sf::Vector2f& position);
	void FreeMemory();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);
private:
	
	IPowerUp* currentPowerUp;
	bool blocked = false;
	Program* program;

	int powerUpChance = 25;  // x%
	int healChance = 3; 
	int splitChance = 6;  
	int slowChance = 10;  
	int enlargeChance = 5;  
	int stickChance = 10;  
	

	//int healC = 0;
	//int splitC = 0;
	//int slowC = 0;
	//int enlargeC = 0;
	//int stickC = 0;
};

