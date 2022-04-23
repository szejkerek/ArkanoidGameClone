#pragma once
#include <SFML/Graphics.hpp>
#include "Utility.h"
#include "Stage.h"
#include "Vaus.h"
class Ball : public sf::Drawable
{
private:
	//Game Objects
	Stage* currentStage;
	Vaus* currentVaus;
	sf::CircleShape gameObject;
	sf::Vector2f direction;
	sf::Vector2f position;
	//Variables
	PositionConstrains playgroundConstrains;
	
	float speed;
	//Methods
	void UpdateCollistions();

	void UpdateWallCollisions();
	void UpdateBricksCollision();
	void UpdateVausCollision();

	void UpdateBrickCollision(IBrick* brick ,sf::FloatRect& overlap);
	void Move(float& deltaTime);
	void Move(sf::Vector2f moveToVector);

public:
	//Constructors & Destructors
	Ball(sf::Vector2f& startingPosition, sf::Vector2f& initialDirection,float ballSpeed, Stage* _stage, Vaus* _vaus);
	void SetPlaygroundConstrains(PositionConstrains _playgroundConstrains);

	//Methods
	void ChangeDirection(sf::Vector2f newDirection);

	//Getters & Setters
	sf::Vector2f GetDirection();
	sf::Vector2f GetPosition();
	float GetRadius();

	//SFML Methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);

};

