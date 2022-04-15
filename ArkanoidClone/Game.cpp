#include "Game.h"
#include <iostream>

Game::Game(float& _deltaTime)
{
	deltaTime = _deltaTime;
	InitializeStage();
	ball = InitializeBall({12,32});
	ball1 = InitializeBall({ 18,52 });
	ball2 = InitializeBall({ -12,-11 });
}

Ball* Game::InitializeBall(sf::Vector2f startingDireciton)
{
	sf::Vector2f stratingPosition = { 200, 800 };
	float startingSpeed = 40.f;
	Ball* _ball = new Ball(stratingPosition, startingDireciton, startingSpeed, stage1);
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
	delete ball1;
	delete ball2;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(playground);
	target.draw(*stage1);
	target.draw(*ball);
	target.draw(*ball1);
	target.draw(*ball2);
}

void Game::Update( float& dt)
{
	stage1->FillPlayableSet(); // Add this to OnCollision 
	ball->Update(dt);	
	ball1->Update(dt);	
	ball2->Update(dt);	
}

