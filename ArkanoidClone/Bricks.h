#pragma once
#include "IBrick.h"
#include <iostream>
#include "Utility.h"
class GoldBrick: public IBrick 
{
public:
	GoldBrick();
	void OnCollisionEnter() { std::cout << "Bounce" << std::endl; }
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class SilverBrick : public IBrick
{
public:
	SilverBrick(int stageNumber);
	void OnCollisionEnter() { std::cout << "HP -1" << std::endl; }
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class ColorBrick : public IBrick
{
public:
	ColorBrick(ColorsEnum color);
	void OnCollisionEnter() { std::cout << "Destroyed" << std::endl; }
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};