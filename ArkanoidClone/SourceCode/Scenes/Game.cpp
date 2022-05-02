#include "Game.h"
#include "../Program.h"
#include <iostream>

GameScene::GameScene(Program* _program, float& _deltaTime) : program(_program), Scene(_program) { InitVariables(); }

void GameScene::InitializeBall()
{
	ball = new Ball(this);
	ball->SetPlaygroundConstrains(background->GetCollider());
}

void GameScene::InitVariables() //Preload level
{
	FreeMemory();
	background = new Background(this);
	currentStage = new Stage(1);
	vaus = new Vaus();
	healthManager = new HealthManager(this);
	InitializeBall();
}



void GameScene::FreeMemory()
{
	delete background;
	delete currentStage;
	delete ball;
	delete vaus;
	delete healthManager;
}

GameScene::~GameScene()
{
	FreeMemory();
}

void GameScene::StartGame()
{
	playable = true;	
	SelectStage(new Stage(1), new Background(this));
}

void GameScene::SelectStage(Stage* _stage, Background* _background)
{
	delete background;
	delete currentStage;
	background = _background;
	currentStage = _stage;
}

void GameScene::EndGame()
{
	playable = false;
	ballAirTime = 0;
	program->sceneManager->LoadScene(Scenes::Menu);
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!playable)
		return;

	target.draw(*background);
	target.draw(*currentStage);
	target.draw(*vaus);
	target.draw(*ball);
	target.draw(*healthManager);
}

void GameScene::Update( float& dt )
{
	if (!playable)
		return;
	
	ballAirTime += dt; //GameTime
	ball->Update(dt);	
	vaus->Update(dt);	
}

