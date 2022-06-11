#pragma once
#include "../ArkanoidClone/SourceCode/Scenes/Scene.h"
#include "../ArkanoidClone/SourceCode/UI/Button.h"

class TutorialScene : public Scene
{
	sf::RectangleShape backgroundBehind;
	Button* backToMenuBtn;

public:
	TutorialScene(Program* _program);
	~TutorialScene();
	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

