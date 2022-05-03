#pragma once
#include "Scene.h"
#include "../Entity/Stage.h"
#include "../UI/Button.h"

class LevelSelectorScene : public Scene
{
protected:
	int currentIndex = 0;
	void IncrementIndex();
	void DecrementIndex();
	void LoadGame();

	Button* backToMenuBtn;
	Button* playBtn;
	Button* nextStageBtn;
	Button* previousStageBtn;

	sf::RectangleShape preview;

	void SetUpScene();
	void SetFullPreview();

	std::vector<Stage*> stages;


public:
	virtual void LoadStages() = 0;
	LevelSelectorScene(Program* _program);
	~LevelSelectorScene();

	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class LevelSelectorOriginal : public LevelSelectorScene
{
public:
	LevelSelectorOriginal(Program* _program) : LevelSelectorScene(_program) { LoadStages(); SetFullPreview();}
	virtual void LoadStages();
};

class LevelSelectorCustom : public LevelSelectorScene
{
public:
	LevelSelectorCustom(Program* _program) : LevelSelectorScene(_program) { /*LoadStages();*/ }
	virtual void LoadStages();
};
