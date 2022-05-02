#include "LevelSelectorScene.h"


void LevelSelectorScene::SetUpScene()
{
	backToMenuBtn = new Button(program);
	playBtn = new Button(program);
	nextStageBtn = new Button(program);
	previousStageBtn = new Button(program);
	customBtn = new Button(program);
	fastNextBtn = new Button(program);
	fastPreviousBtn = new Button(program);

	backToMenuBtn->PlaceOnScene({ 150,850 }, { 150,75 }, "Back", Scenes::Menu);
	playBtn->PlaceOnScene({ 550,850 }, { 150,75 }, "Play", Scenes::Game);
	nextStageBtn->PlaceOnScene({ 650,250 }, { 50,50 });
	previousStageBtn->PlaceOnScene({ 350,250 }, { 50,50 });

	nextStageBtn->SetOnClickFunction(std::bind(&LevelSelectorScene::IncrementIndex, this));
}


LevelSelectorScene::LevelSelectorScene(Program* _program) : Scene(_program)
{
	SetUpScene();
}

LevelSelectorScene::~LevelSelectorScene()
{
	delete backToMenuBtn;
	delete playBtn;
	delete customBtn;
	delete nextStageBtn;
	delete previousStageBtn;
	delete fastNextBtn;
	delete fastPreviousBtn;
}

void LevelSelectorScene::Update(float& dt)
{
	backToMenuBtn->Update(dt);
	playBtn->Update(dt);
	nextStageBtn->Update(dt);
	previousStageBtn->Update(dt);

	std::cout << currentIndex << std::endl;
}

void LevelSelectorScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*backToMenuBtn);
	target.draw(*playBtn);
	target.draw(*nextStageBtn);
	target.draw(*previousStageBtn);
}

void LevelSelectorScene::IncrementIndex()
{
	currentIndex++;
}
