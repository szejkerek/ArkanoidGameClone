#include "Game.h"
#include <iostream>
Game::Game(){}

Game::Game(const float& _deltaTime)
{
	gold.SetPosition({ 450.f,450.f });
	gold1.SetPosition({ 550.f,550.f });
	gold2.SetPosition({ 650.f,650.f });
	deltaTime = _deltaTime;
	InitializePlayground();
	InitializeBall();
}

void Game::InitializePlayground()
{
	playground = sf::RectangleShape({ 750.f,885.f });
	playground.setFillColor(sf::Color::Black);
	playground.setOutlineThickness(15.f);
	playground.setOutlineColor(sf::Color::White);
	playground.setPosition({50,20});
}

void Game::InitializeBall()
{
	sf::Vector2f stratingPosition = { 200, 800 };
	sf::Vector2f startingDireciton = { -11.f , -3.39f };
	float startingSpeed = 150.f;
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
	target.draw(gold);
	target.draw(gold1);
	target.draw(gold2);
}

void Game::Update( float& dt)
{
	ball.Update(dt);
	
}

