#pragma once
#include "IBrick.h"
#include <iostream>
#include "Utility.h"
#include "Stage.h"
class GoldBrick: public IBrick 
{
public:
	GoldBrick();
	bool OnCollisionEnter(); //Can never be destroyed
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class SilverBrick : public IBrick
{
private:
	int hp;
public:
	SilverBrick(int stageNumber);
	bool OnCollisionEnter();
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class ColorBrick : public IBrick
{
public:
	ColorBrick(ColorsEnum color);
	bool OnCollisionEnter();
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};