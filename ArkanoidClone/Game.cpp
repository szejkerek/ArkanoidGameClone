#include "Game.h"
#include <iostream>
Game::Game(){}

Game::Game(float& _deltaTime)
{
	deltaTime = _deltaTime;
	InitializeBall();
	InitializeStage();
}

void Game::InitializeBall()
{
	sf::Vector2f stratingPosition = { 200, 800 };
	sf::Vector2f startingDireciton = { -11.f , -3.39f };
	float startingSpeed = 100.f;
	ball = Ball(stratingPosition, startingDireciton, startingSpeed);
	ball.SetPlaygroundConstrains(playground.GetPositionConstrains(ball));	
}

void Game::InitializeStage()
{
	stage1 = Stage(1, playground.GetPosition());
}


Game::~Game()
{

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(playground);
	target.draw(stage1);
	target.draw(ball);
}

void Game::Update( float& dt)
{
	ball.Update(dt);	
}

