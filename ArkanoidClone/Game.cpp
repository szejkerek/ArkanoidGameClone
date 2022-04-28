#include "Game.h"
#include <iostream>

Game::Game(float& _deltaTime):deltaTime(_deltaTime)
{
	InitVariables(1);
}

void Game::InitializeBall(const sf::Vector2f& _stratingPosition, const sf::Vector2f& startingDireciton)
{
	ball = new Ball(currentStage, vaus);
	ball->SetPlaygroundConstrains(playground->GetCollider());
}

void Game::InitVariables(int stageLvl)
{
	playground = new Playground();
	currentStage = new Stage(stageLvl, playground->GetPosition());
	vaus = new Vaus();
	healthManager = new HealthManager();
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

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*playground);
	target.draw(*currentStage);
	target.draw(*vaus);
	target.draw(*ball);
	target.draw(*healthManager);
}

void Game::Update( float& dt)
{
	ball->Update(dt);	
	vaus->Update(dt);
}

