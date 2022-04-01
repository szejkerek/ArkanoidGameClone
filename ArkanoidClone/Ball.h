#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable
{
private:
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Vector2f direction;
	float speed;

public:
	Ball() {}
	Ball(sf::Vector2f startingPosition, sf::Vector2f initialDirection,float ballSpeed);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float dt);

};

