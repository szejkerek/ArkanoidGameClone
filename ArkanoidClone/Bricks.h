#pragma once
#include "IBrick.h"
#include "Utility.h"
class GoldBrick: public IBrick 
{
public:
	GoldBrick();
	void OnCollisionEnter() {}
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class SilverBrick : public IBrick
{
public:
	SilverBrick(int stageNumber);
	void OnCollisionEnter() {}
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class ColorBrick : public IBrick
{
public:
	ColorBrick(ColorsEnum color);
	void OnCollisionEnter() {}
	void SetTexture(sf::Texture _texture) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};