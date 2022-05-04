#pragma once
#include "../Scenes/Scene.h"
#include "../UI/Button.h"

class MenuScene : public Scene
{
	Button* levelSelectorBtn;

public:
	MenuScene(Program* _program);
	~MenuScene();
	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

