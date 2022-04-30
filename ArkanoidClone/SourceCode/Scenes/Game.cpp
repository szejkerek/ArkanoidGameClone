#include "Game.h"
#include "../Program.h"
#include <iostream>

Game::Game(Program* _program, float& _deltaTime) : program(_program), Scene(_program) { InitVariables(1); }

void Game::InitializeBall()
{
	ball = new Ball(this);
	ball->SetPlaygroundConstrains(playground->GetCollider());
}

void Game::InitVariables(int stageLvl)
{
	FreeMemory();
	playground = new Playground(this);
	currentStage = new Stage(1);
	vaus = new Vaus();
	healthManager = new HealthManager(this);
	InitializeBall();
}

void Game::FreeMemory()
{
	delete playground;
	delete currentStage;
	delete ball;
	delete vaus;
	delete healthManager;
}

Game::~Game()
{
	FreeMemory();
}

void Game::StartGame()
{
	playable = true;	
	InitVariables(1);
}

void Game::SelectStage(Stage* _stage)
{
	currentStage = _stage;
}

void Game::EndGame()
{
	playable = false;
	ballAirTime = 0;
	program->sceneManager->LoadScene(Scenes::Menu);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!playable)
		return;

	target.draw(*playground);
	target.draw(*currentStage);
	target.draw(*vaus);
	target.draw(*ball);
	target.draw(*healthManager);
}

void Game::Update( float& dt )
{
	if (!playable)
		return;
	
	ballAirTime += dt; //GameTime
	ball->Update(dt);	
	vaus->Update(dt);	
}

