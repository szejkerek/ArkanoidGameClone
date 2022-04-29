#include "Game.h"
#include <iostream>

Game::Game(float& _deltaTime):deltaTime(_deltaTime)
{
	InitVariables(1);
}

void Game::InitializeBall(const sf::Vector2f& _stratingPosition, const sf::Vector2f& startingDireciton)
{
	ball = new Ball(this);
	ball->SetPlaygroundConstrains(playground->GetCollider());
}

void Game::InitVariables(int stageLvl)
{
	playground = new Playground(this);
	currentStage = new Stage(stageLvl, playground->GetPosition());
	vaus = new Vaus();
	healthManager = new HealthManager(this);
	InitializeBall({ 222,575 }, NormalizeVector({ 81, 49 }));
}

Game::~Game()
{
	delete playground;
	delete currentStage;
	delete ball;
	delete vaus;
	delete healthManager;
}

void Game::StartGame()
{
	playable = true;
}

void Game::EndGame()
{
	playable = false;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
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

	ball->Update(dt);	
	vaus->Update(dt);	
}

