#pragma once
#include "Brick.h"
class GoldBrick: public Brick 
{
public:
	void OnCollisionEnter() {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

