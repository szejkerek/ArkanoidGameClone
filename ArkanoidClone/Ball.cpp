#include "Ball.h"
#include "functions.h"
Ball::Ball()
{
	gameObject.setRadius(5);
	gameObject.setPosition(0,0);
	gameObject.setFillColor(sf::Color::White);
	position = { 0, 0 };
	direction = {-1,-1};
	speed = 1;
}

Ball::Ball(sf::Vector2f _position, sf::Vector2f _direction, float _speed)
{
	gameObject.setRadius(8);
	gameObject.setPosition(_position);
	gameObject.setFillColor(sf::Color::Magenta);
	position = _position;
	direction = _direction;
	speed = _speed;
}

void Ball::SetPlaygroundConstrains(sf::RectangleShape& _playground)
{
	maxLeft = _playground.getPosition().x;
	maxUp = _playground.getPosition().y;
	maxRight = _playground.getPosition().x + _playground.getSize().x;
	maxDown = _playground.getPosition().y + _playground.getSize().y;
}

void Ball::ChangeDirection(sf::Vector2f _direction)
{
	direction = _direction;
}

void Ball::UpdateCollistions()
{
	UpdateWallCollisions();
	UpdateBlockCollision();
}

void Ball::UpdateWallCollisions()
{
	sf::Vector2f changeX = { -1.f, 1.f };
	sf::Vector2f changeY = {	1.f, -1.f };

	if (GetPoistion().x <= maxLeft)
	{
		ChangeDirection(MultipyVectors(direction, changeX));
	}
	else if (GetPoistion().y <= maxUp)
	{
		ChangeDirection(MultipyVectors(direction, changeY));
	}
	else if (gameObject.getPosition().x + gameObject.getRadius() >= maxRight)
	{
		ChangeDirection(MultipyVectors(direction, changeX));
	}
	else if (gameObject.getPosition().y+ gameObject.getRadius() >= maxDown)
	{
		ChangeDirection(MultipyVectors(direction, changeY));
	}
	
}

void Ball::UpdateBlockCollision()
{
}

void Ball::Move(float& dt)
{
	position += direction * speed * dt;
	gameObject.setPosition(position);
}

sf::Vector2f Ball::GetDirection()
{
	return direction;
}

sf::Vector2f Ball::GetPoistion()
{
	return position;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

void Ball::Update(float& dt)
{
	UpdateCollistions();
	Move(dt);
	
}
