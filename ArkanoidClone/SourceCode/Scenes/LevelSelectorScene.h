#pragma once
#include "Scene.h"
#include "../ArkanoidClone/SourceCode/Entity/Managers/Stage.h"
#include "../UI/Button.h"
#include "../UI/TextElement.h"

class LevelSelectorScene : public Scene
{
public:
	std::vector<Stage*> stages;

	LevelSelectorScene(Program* _program);
	~LevelSelectorScene();

	virtual void LoadStages() = 0;
	virtual void ResetIndex();
	virtual int GetIndex();
	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::RectangleShape preview;
	sf::RectangleShape backgroundBehind;
	int currentIndex = 0;
	int levelsCount = 0;

	Button* backToMenuBtn;
	Button* playBtn;
	Button* nextStageBtn;
	Button* previousStageBtn;

	TextElement* indexText;
	TextElement* stageTypeText;

	void SetUpScene();
	void ChoosePreviewImage();
	void CreateButtnos();
	void LayoutButtons();
	void LayoutText();
	void FreeMemory();
	void IncrementIndex();
	void DecrementIndex();
	void LoadGame();
};

class LevelSelectorOriginal : public LevelSelectorScene
{
public:
	LevelSelectorOriginal(Program* _program);

	virtual void LoadStages();
};
