#include "Game.h"
#include <iostream>

Game::Game(float& _deltaTime):deltaTime(_deltaTime)
{
	InitializeStage(1);
	vaus = new Vaus();
	healthManager = new HealthManager();
	ball = InitializeBall({222,575}, NormalizeVector( { 81, 49 } ));
}

Ball* Game::InitializeBall(const sf::Vector2f& _stratingPosition, const sf::Vector2f& startingDireciton)
{
	float startingSpeed = 750.f;
	Ball* _ball = new Ball(_stratingPosition, startingDireciton, startingSpeed, currentStage, vaus);
	_ball->SetPlaygroundConstrains(playground.GetPositionConstrains(*_ball));
	return _ball;
}

void Game::InitializeStage(int stageLvl)
{
	currentStage = new Stage(stageLvl, playground.GetPosition());
}

Game::~Game()
{
	delete currentStage;
	delete ball;
	delete vaus;
	delete healthManager;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(playground);
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

