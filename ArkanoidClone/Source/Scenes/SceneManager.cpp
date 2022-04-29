#include "SceneManager.h"
#include "../Program.h"

SceneManager::SceneManager(Program* _program) : program(_program), currentScene(nullptr)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(const Scenes& sceneToLoad)
{
	switch (sceneToLoad)
	{
	case Scenes::Game:
	{
		currentScene = program->game;
		program->game->StartGame();
	}
		break;

	default:
		break;
	}
}

void SceneManager::Update(float& dt)
{
	if(currentScene != nullptr)
		currentScene->Update(dt);
}

void SceneManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (currentScene != nullptr)
		target.draw(*currentScene);
}
