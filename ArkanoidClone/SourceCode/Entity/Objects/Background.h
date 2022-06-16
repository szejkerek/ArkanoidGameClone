#pragma once
#include "Entity.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
class Background: public EntityRectangle
{
public:
	Background(GameScene* game);

	void PickBackground(int stageNumber);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	int stageNumber = 0;

	void InitGameObject();
};

