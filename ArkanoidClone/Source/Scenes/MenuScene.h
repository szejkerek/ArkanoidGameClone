#pragma once
#include "../Scenes/Scene.h"

class MenuScene : public Scene
{
	MenuScene();

	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

