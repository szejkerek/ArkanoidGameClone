#include "MenuScene.h"
#include "../Program.h"

MenuScene::MenuScene(Program* _program) : Scene(_program)
{
	sf::Vector2f window = static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution);
	levelSelectorBtn = new Button(program);
	levelSelectorBtn->PlaceOnScene({ window.x / 2, window.y / 2 }, ButtonType::RectangleBig,"Choose Stage",Scenes::LevelSelectorOriginal);
}

MenuScene::~MenuScene()
{
	delete levelSelectorBtn;
}

void MenuScene::Update(float& dt)
{
	levelSelectorBtn->Update(dt);
}

void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*levelSelectorBtn);
}
