#include "Vaus.h"
#include "Utility.h"
#include <iostream>

float ValidatePosition(const sf::Vector2f& position) 
{
	float playgroundPosition = PixelSizes::GetInstance().playgroundPosition.x;
	float playgroundSize = PixelSizes::GetInstance().playgroundSize.x;
	float vausSize = PixelSizes::GetInstance().vausSize.x;

	if (position.x <= playgroundPosition)
	{
		return playgroundPosition;
	}
	else if (position.x  >= playgroundPosition + playgroundSize - vausSize)
	{
		return playgroundPosition + playgroundSize - vausSize;
	}
	else
	{
		return position.x;
	}
}

void Vaus::Move(float& dt)
{
	position += direction * speed * dt * UserSettings::GetInstance().sensitivity;
	position.x = ValidatePosition(position);
	hitbox.setPosition(position);
}
Vaus::Vaus()
{
	hitbox.setSize(PixelSizes::GetInstance().vausSize);
	position = PixelSizes::GetInstance().vausPosition;
	hitbox.setPosition(position);
	hitbox.setOutlineColor(sf::Color::Yellow);
	hitbox.setFillColor(sf::Color::Color(0,0,0,0));
	hitbox.setOutlineThickness(1.f);
}

void Vaus::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(hitbox);
}

void Vaus::Update(float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		direction = { -1, 0 };
		Move(dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		direction = { 1, 0 };
		Move(dt);
	}

	
}
