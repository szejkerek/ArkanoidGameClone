#pragma once
#include "SFML/Graphics.hpp"
#include "Scene.h"

enum class Scenes
{
	none,
	Menu,
	LevelSelectorOriginal,
	Game,
	Tutorial
};

class Program;
class SceneManager : public sf::Drawable
{
public:
	SceneManager(Program* _program);

	void LoadScene(const Scenes& sceneToLoad);
	void Update(float& dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Program* program;
	Scene* currentScene;

};

