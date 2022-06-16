#pragma once
#include "../Scenes/Scene.h"
#include "../ArkanoidClone/SourceCode/UI/Button.h"

class TutorialScene : public Scene
{
public:
	TutorialScene(Program* _program);
	~TutorialScene();

	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::RectangleShape backgroundBehind;
	sf::RectangleShape tutorialBehind;
	Button* backToMenuBtn;
};

