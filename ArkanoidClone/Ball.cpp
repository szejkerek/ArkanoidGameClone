#include "Ball.h"

Ball::Ball(sf::Vector2f _position, sf::Vector2f _direction, float _speed)
{
	circle.setRadius(25);
	circle.setPosition(_position);
	circle.setFillColor(sf::Color::Magenta);
	position = _position;
	direction = _direction;
	speed = _speed;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(circle);
}

void Ball::Update(float dt)
{
	position += direction * speed * dt;
	circle.setPosition(position);
}
