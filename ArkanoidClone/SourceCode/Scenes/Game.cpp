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
	vaus = new Vaus();
	healthManager = new HealthManager(this);
	InitializeBall();
}

void GameScene::FreeMemory()
{
	delete background;
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
	healthManager->RestoreFullHp();
	playable = true;	
}

void GameScene::AddPoints(const int& brickPoint)
{
	tempPoints += brickPoint;
}

void GameScene::SelectStage(Stage* _stage)
{
	currentStage = _stage;
}

void GameScene::EndGame()
{
	ball->StickBallToVaus();
	playable = false;
	ballAirTime = 0;
	tempPoints = 0;
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

