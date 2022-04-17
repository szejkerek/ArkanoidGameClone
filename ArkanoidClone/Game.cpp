#include "Game.h"
#include <iostream>

Game::Game(float& _deltaTime)
{
	deltaTime = _deltaTime;
	InitializeStage();
	ball = InitializeBall({482,475}, {15, -15});
	ball1 = InitializeBall({ 600,358 }, { -10,20 });
	ball2 = InitializeBall({ 562,510 }, { 10,-20 });
	ball3 = InitializeBall({ 655,422 }, { -15, 15 });
}

Ball* Game::InitializeBall(sf::Vector2f _stratingPosition, sf::Vector2f startingDireciton)
{
	//sf::Vector2f stratingPosition = { 200, 800 };
	float startingSpeed = 0.25;
	Ball* _ball = new Ball(_stratingPosition, startingDireciton, startingSpeed, stage1);
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
	delete ball3;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(playground);
	target.draw(*stage1);
	target.draw(*ball);
	target.draw(*ball1);
	target.draw(*ball2);
	target.draw(*ball3);
}

void Game::Update( float& dt)
{
	stage1->FillPlayableSet(); // Add this to OnCollision 
	ball->Update(dt);	
	ball1->Update(dt);	
	ball2->Update(dt);	
	ball3->Update(dt);	
}

