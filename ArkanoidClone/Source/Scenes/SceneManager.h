#pragma once
#include "SFML/Graphics.hpp"
#include "Scene.h"
#

class Program;

enum class Scenes
{
	Menu,
	LevelSelector,
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
	~SceneManager();

	void LoadScene(const Scenes& sceneToLoad);
	void OpenPauseMenu();
	void ClosePauseMenu();

	void Update(float& dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

