#include "Ball.h"
#include "Utility.h"

Ball::Ball(sf::Vector2f _position, sf::Vector2f _direction, float _speed)
{
	circle.setRadius(25);
	circle.setPosition(_position);
	circle.setFillColor(sf::Color::Magenta);
	position = _position;
	direction = _direction;
	speed = _speed;
}

void Ball::Draw(sf::RenderWindow& renderer)
{
	renderer.draw(circle);
}

void Ball::Update(float dt)
{
	position += direction * speed * dt;
	circle.setPosition(position);
}
