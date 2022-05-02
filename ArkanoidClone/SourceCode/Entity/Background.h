#pragma once
#include "Entity.h"
#include "../Utility/Utility.h"
class Background: public EntityRectangle
{
	//Methods
	void InitGameObject();
public:
	Background(GameScene* game);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

