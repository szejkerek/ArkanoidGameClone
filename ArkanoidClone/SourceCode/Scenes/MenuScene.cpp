#include "MenuScene.h"
#include "../Program.h"

MenuScene::MenuScene(Program* _program) : Scene(_program)
{
	btn = new Button(program);
	btn->LoadSceneOnClick(Scenes::LevelSelectorOriginal);
}

MenuScene::~MenuScene()
{
	delete btn;
}

void MenuScene::Update(float& dt)
{
	btn->Update(dt);
}

void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*btn);
}
