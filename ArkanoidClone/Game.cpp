#include "Game.h"
#include <iostream>
Game::Game(){}

Game::Game(const float& _deltaTime)
{
	deltaTime = _deltaTime;
	InitializePlayground();
	InitializeBall();
	
}

void Game::InitializePlayground()
{
	playground = sf::RectangleShape({ 750.f,900.f });
	playground.setFillColor(sf::Color::Black);
	playground.setOutlineThickness(25.f);
	playground.setOutlineColor(sf::Color::White);
	playground.setPosition({100,0});
}

void Game::InitializeBall()
{
	sf::Vector2f stratingPosition = { 200, 800 };
	sf::Vector2f startingDireciton = { -5 , -2 };
	float startingSpeed = 35.f;
	ball = Ball(stratingPosition, startingDireciton, startingSpeed);
	ball.SetPlaygroundConstrains(playground);
}


Game::~Game()
{

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(playground);
	target.draw(ball);
}

void Game::Update( float& dt)
{
	ball.Update(dt);
}

