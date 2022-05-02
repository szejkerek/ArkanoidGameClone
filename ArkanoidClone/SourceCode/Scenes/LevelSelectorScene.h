#pragma once
#include "Scene.h"
#include "../Entity/Stage.h"
#include "../UI/Button.h"

class LevelSelectorScene : public Scene
{
private:
	int currentIndex = 6;

	Button* backToMenuBtn;
	Button* playBtn;
	Button* customBtn;
	Button* nextStageBtn;
	Button* previousStageBtn;
	Button* fastNextBtn;
	Button* fastPreviousBtn;

	

	void SetUpScene();


public:
	void IncrementIndex();
	LevelSelectorScene(Program* _program);
	~LevelSelectorScene();

	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

