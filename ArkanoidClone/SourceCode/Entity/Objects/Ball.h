#pragma once
#include "Entity.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
#include "Bricks.h"
class Ball : public EntityCircle
{
public:
	Ball(GameScene* game);

	void SetPlaygroundConstrains(const sf::FloatRect& _playgroundConstrains);
	void ChangeDirection(sf::Vector2f newDirection);
	void StickBallToVaus();
	sf::Vector2f GetDirection();
	void InitGameObject(const float& _speed);
	void ChangeBallSpeed(const float& newSpeed);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);

private:

	sf::FloatRect playgroundCollider;
	sf::Vector2f ballToVausOffset;
	sf::Vector2f direction;
	bool stickedToVaus;
	float speed;

	void UpdateCollistions();
	void UpdateWallCollisions();
	void UpdateBricksCollision();
	void UpdateVausCollision();
	void UpdateBrickCollision(IBrick* brick ,sf::FloatRect& overlap);
	void Move(float& deltaTime);
	void Move(sf::Vector2f moveToVector);
	void StickedBallLogic();


};

