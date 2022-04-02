#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable
{
private:
	//Game Objects
	sf::CircleShape gameObject;
	sf::Vector2f direction;
	sf::Vector2f position;
	//Variables
	float maxLeft, maxRight, maxUp, maxDown; //Wall constrains
	float speed;

public:
	//Constructors & Destructors
	Ball();
	Ball(sf::Vector2f startingPosition, sf::Vector2f initialDirection,float ballSpeed);
	void SetPlaygroundConstrains(sf::RectangleShape& playground);

	//Methods
	void ChangeDirection(sf::Vector2f newDirection);
	void UpdateCollistions();
	void UpdateWallCollisions();
	void UpdateBlockCollision();
	void Move(float& deltaTime);

	//Getters & Setters
	sf::Vector2f GetDirection();
	sf::Vector2f GetPoistion();

	//SFML Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);

};

