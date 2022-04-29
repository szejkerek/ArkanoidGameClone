#include "Game.h"
#include <iostream>

Game::Game(Program* _program, float& _deltaTime) : deltaTime(_deltaTime), Scene(_program) { InitVariables(1); }

void Game::InitializeBall()
{
	ball = new Ball(this);
	ball->SetPlaygroundConstrains(playground->GetCollider());
}

void Game::InitVariables(int stageLvl)
{
	FreeMemory();
	playground = new Playground(this);
	currentStage = new Stage(stageLvl, playground->GetPosition());
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

void Game::EndGame()
{
	playable = false;
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
	{
		return;
	}

	ball->Update(dt);	
	vaus->Update(dt);	
}

