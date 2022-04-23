#include "Game.h"
#include <iostream>

Game::Game(float& _deltaTime):deltaTime(_deltaTime)
{
	InitializeStage();
	vaus = new Vaus();
	ball = InitializeBall({222,575}, NormalizeVector( { 81, 49 } ));
}

Ball* Game::InitializeBall(sf::Vector2f _stratingPosition, sf::Vector2f startingDireciton)
{
	float startingSpeed = 200.f;
	Ball* _ball = new Ball(_stratingPosition, startingDireciton, startingSpeed, stage1, vaus);
	_ball->SetPlaygroundConstrains(playground.GetPositionConstrains(*_ball));
	return _ball;
}

void Game::InitializeStage()
{
	stage1 = new Stage(1, playground.GetPosition());
}

Game::~Game()
{
	delete stage1;
	delete ball;
	delete vaus;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(playground);
	target.draw(*stage1);
	target.draw(*ball);
	target.draw(*vaus);
}

void Game::Update( float& dt)
{
	ball->Update(dt);	
	vaus->Update(dt);
}

