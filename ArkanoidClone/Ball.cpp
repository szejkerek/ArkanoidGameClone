#include "Ball.h"
#include "Utility.h"

Ball::Ball(sf::Vector2f _position, sf::Vector2f _direction, float _speed, Stage* _stage): currentStage(_stage)
{
	gameObject.setRadius(PixelSizes::GetInstance().ballRadius);
	gameObject.setOrigin(GetRadius(), GetRadius());
	gameObject.setPosition(_position);
	gameObject.setFillColor(sf::Color::White);
	position = _position;
	direction = _direction;
	speed = _speed;
}

void Ball::SetPlaygroundConstrains(PositionConstrains _playgroundConstrains)
{
	playgroundConstrains = _playgroundConstrains;
}


void Ball::ChangeDirection(sf::Vector2f _direction)
{
	direction = _direction;
}

void Ball::UpdateCollistions()
{
	UpdateWallCollisions();
	UpdateBricksCollision();
}

void Ball::UpdateWallCollisions()
{
	sf::Vector2f changeX = { -1.f, 1.f };
	sf::Vector2f changeY = { 1.f, -1.f };

	if (GetPosition().x <= playgroundConstrains.maxLeft)
	{
		position.x = playgroundConstrains.maxLeft;
		ChangeDirection(MultipyVectors(direction, changeX));
	}
	else if (GetPosition().y <= playgroundConstrains.maxUp)
	{
		position.y = playgroundConstrains.maxUp;
		ChangeDirection(MultipyVectors(direction, changeY));
	}
	else if (gameObject.getPosition().x >= playgroundConstrains.maxRight)
	{
		position.x = playgroundConstrains.maxRight;
		ChangeDirection(MultipyVectors(direction, changeX));
	}
	else if (gameObject.getPosition().y >= playgroundConstrains.maxDown)
	{
		position.y = playgroundConstrains.maxDown;
		ChangeDirection(MultipyVectors(direction, changeY));
	}
	
}

sf::Vector3f CalculateCorrectionVector(sf::FloatRect overlap, sf::Vector2f collisionVector)
{
	sf::Vector3f correctionVector(0, 0, 0); // x,y - from where ball collide  // z - depth of penetration
	if (overlap.width < overlap.height)
	{
		correctionVector.x = (collisionVector.x < 0) ? 1.f : -1.f;
		correctionVector.z = overlap.width;
	}
	else
	{
		correctionVector.y = (collisionVector.y < 0) ? 1.f : -1.f;
		correctionVector.z = overlap.height;
	}
	return correctionVector;
}

inline sf::Vector2f ReflectedVector(sf::Vector2f& currentDirection, sf::Vector2f& normal)
{
	return -2.f * DotProduct(currentDirection, normal) * normal + currentDirection;
}

void Ball::UpdateBrickCollision(IBrick* brick, sf::FloatRect& _overlap)
{
	sf::Vector2f collisionVector = brick->GetCenterPoint() - GetPosition();
	sf::Vector3f correctionVector = CalculateCorrectionVector(_overlap, collisionVector);

	sf::Vector2f normal(correctionVector.x, correctionVector.y);
	Move(normal * correctionVector.z);   //Move ball outside brick
	
	ChangeDirection(ReflectedVector(direction, normal));
}

void Ball::UpdateBricksCollision()
{
	sf::FloatRect overlap;
	sf::FloatRect ballBounds = gameObject.getTransform().transformRect(gameObject.getLocalBounds());

	for (auto& brick: currentStage->playableBricks)
	{
		if (brick->gameObject.getGlobalBounds().intersects(ballBounds, overlap))
		{
			UpdateBrickCollision(brick, overlap);//Calculate movement

			currentStage->CollisionDetected(brick);//Handle internal brick logic
			break;
		}
	}
}

void Ball::Move(float& dt)
{
	position += direction * speed * dt;
	gameObject.setPosition(position);
}

void Ball::Move(sf::Vector2f moveToVector)
{
	position += moveToVector;
	gameObject.setPosition(position);
}

sf::Vector2f Ball::GetDirection()
{
	return direction;
}

sf::Vector2f Ball::GetPosition()
{
	return position;
}

float Ball::GetRadius()
{
	return gameObject.getRadius();
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

void Ball::Update(float& dt)
{
	//std::cout << gameObject.getTransform().transformRect(gameObject.getLocalBounds()).left<<std::endl;
	//std::cout << gameObject.getGlobalBounds().width << std::endl;
	UpdateCollistions();
	Move(dt);
}
