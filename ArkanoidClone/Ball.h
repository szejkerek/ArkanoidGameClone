#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Vector2f direction;
	float speed;

public:
	Ball(sf::Vector2f startingPosition, sf::Vector2f initialDirection,float ballSpeed);
	void Draw(sf::RenderWindow& renderer);
	void Update(float dt);

};

