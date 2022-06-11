#include "MenuScene.h"
#include "../Program.h"

MenuScene::MenuScene(Program* _program) : Scene(_program), program(_program)
{
	sf::Vector2f window = static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution);


	levelSelectorBtn = new Button(program);
	levelSelectorBtn->PlaceOnScene({ window.x / 2, window.y / 2 }, ButtonType::RectangleBig,"Choose\n  Stage", 27 ,Scenes::LevelSelectorOriginal);

	tutorialSceneBtn = new Button(program);
	tutorialSceneBtn->PlaceOnScene({ window.x / 2, (window.y / 2) + 200 }, ButtonType::RectangleBig, "Tutorial", 27, Scenes::Tutorial);


	exitBtn = new Button(program);
	exitBtn->PlaceOnScene({ window.x / 2, (window.y / 2) + 400 }, ButtonType::RectangleBig, "Exit", 27);
	exitBtn->SetOnClickFunction(std::bind(&MenuScene::CloseWindow,this));

	backgroundBehind.setSize(static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution));
	backgroundBehind.setTexture(ResourceManager::Get().GetTexture("backgroundMenu"));
}

MenuScene::~MenuScene()
{
	delete levelSelectorBtn;
	delete tutorialSceneBtn;
}

void MenuScene::CloseWindow()
{
	program->CloseWindow();
}

void MenuScene::Update(float& dt)
{
	levelSelectorBtn->Update(dt);
	tutorialSceneBtn->Update(dt);
	exitBtn->Update(dt);
}

void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(backgroundBehind);
	target.draw(*levelSelectorBtn);
	target.draw(*tutorialSceneBtn);
	target.draw(*exitBtn);
}
