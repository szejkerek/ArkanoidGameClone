#pragma once
#include "Entity.h"
#include "Utility.h"
class Playground: public EntityRectangle
{
	//Methods
	void InitGameObject();
public:
	Playground(Game* game);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

