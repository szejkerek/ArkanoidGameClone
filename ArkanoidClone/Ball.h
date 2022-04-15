#pragma once
#include <SFML/Graphics.hpp>
#include "Utility.h"
//#include "Stage.h"

class Ball : public sf::Drawable
{
private:
	//Game Objects
	//sf::Stage* currentStage;
	sf::CircleShape gameObject;
	sf::Vector2f direction;
	sf::Vector2f position;
	//Variables
	PositionConstrains playgroundConstrains;
	
	float speed;

public:
	//Constructors & Destructors
	Ball();
	Ball(sf::Vector2f startingPosition, sf::Vector2f initialDirection,float ballSpeed);
	void SetPlaygroundConstrains(PositionConstrains _playgroundConstrains);

	//Methods
	void ChangeDirection(sf::Vector2f newDirection);
	void UpdateCollistions();
	void UpdateWallCollisions();
	void UpdateBlockCollision();
	void Move(float& deltaTime);

	//Getters & Setters
	sf::Vector2f GetDirection();
	sf::Vector2f GetPoistion();
	float GetRadius();

	//SFML Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);

};

