#pragma once
#include "Entity.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
class Background: public EntityRectangle
{
	//Methods
	int stageNumber = 0;
	void InitGameObject();
public:
	Background(GameScene* game);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void PickBackground(int stageNumber);
};

