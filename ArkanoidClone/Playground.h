#pragma once
#include "Entity.h"
#include "Utility.h"
#include "Ball.h"
class Playground: public EntityRectangle
{
	//Methods
	void InitGameObject();
public:
	Playground();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

