#pragma once
#include "Scene.h"
#include "../Entity/Stage.h"
#include "../UI/Button.h"

class LevelSelectorScene : public Scene
{
private:
	int currentIndex = 0;
	void IncrementIndex();
	void DecrementIndex();
	void LoadGame();

	Button* backToMenuBtn;
	Button* playBtn;
	Button* customBtn;
	Button* nextStageBtn;
	Button* previousStageBtn;

	sf::RectangleShape preview;

	void SetUpScene();
	void SetFullPreview();
	void LoadOriginalStages();

	std::vector<Stage*> originalStages;


public:
	LevelSelectorScene(Program* _program);
	~LevelSelectorScene();

	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

