#pragma once
#include "SFML/Graphics.hpp"
#include "Scene.h"
#

class Program;

enum class Scenes
{
	none,
	Menu,
	LevelSelectorOriginal,
	LevelSelectorCustom,
	Game,
	Settings,
	LevelCreator
};

class SceneManager : public sf::Drawable
{
private:
	Program* program;
	Scene* currentScene;

public:
	SceneManager(Program* _program);

	void LoadScene(const Scenes& sceneToLoad);
	//void OpenPauseMenu();
	//void ClosePauseMenu();

	void Update(float& dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

