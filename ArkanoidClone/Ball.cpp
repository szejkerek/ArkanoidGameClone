#include "Ball.h"
#include "Utility.h"
#include <iostream>

Ball::Ball(const sf::Vector2f& _position, const sf::Vector2f& _direction, float _speed, Stage* _stage, Vaus* _vaus): stickedToVaus(true), currentStage(_stage), currentVaus(_vaus)
{
	gameObject.setRadius(PixelSizes::GetInstance().ballRadius);
	gameObject.setOrigin(GetRadius(), GetRadius());
	gameObject.setPosition(_position);
	gameObject.setFillColor(sf::Color::White);

	ballToVausOffset = {0,-21};
	StickBallToVaus(ballToVausOffset);

	position = _position;
	direction = _direction;
	speed = _speed;
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

sf::Vector3f CalculateCorrectionVector(sf::FloatRect& overlap, sf::Vector2f& collisionVector)
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

void Ball::UpdateVausCollision()
{
	sf::FloatRect overlap;
	sf::FloatRect ballBounds = gameObject.getTransform().transformRect(gameObject.getLocalBounds());

	for (auto part : currentVaus->parts)
	{
		if (part->gameObject.getGlobalBounds().intersects(ballBounds, overlap))
		{
			sf::Vector2f collisionVector = part->gameObject.getPosition() - GetPosition();
			sf::Vector2f normalToCenter = currentVaus->parts[0]->gameObject.getPosition() - GetPosition();
			sf::Vector3f correctionVector = CalculateCorrectionVector(overlap, collisionVector);
			sf::Vector2f normal(correctionVector.x, correctionVector.y);

			Move(normal * correctionVector.z);   //Move ball outside brick

			if (part->IsCustomReflectionImplemented() && normal.y != 1) //without downside reflections
			{
				ChangeDirection(part->GetDirection());
			}
			else
			{
				ChangeDirection(ReflectedVector(direction, normal));
			}

			if (correctionVector.z >= 3.5f) //Fixed clipping with wall
			{
				SetPosition({GetPosition().x, part->gameObject.getPosition().y + ballToVausOffset.y});
				correctionVector.z = 0;
			}
			break;
			
		}
	}
}

void Ball::SetPlaygroundConstrains(PositionConstrains _playgroundConstrains)
{
	playgroundConstrains = _playgroundConstrains;
}

void Ball::ChangeDirection(sf::Vector2f _direction)
{
	direction = _direction;
}

void Ball::StickBallToVaus(sf::Vector2f offsetFromVaus)
{
	ballToVausOffset = offsetFromVaus;
	stickedToVaus = true;
}

void Ball::UpdateCollistions()
{
	UpdateWallCollisions();
	UpdateBricksCollision();
	UpdateVausCollision();
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

void Ball::StickedBallLogic()
{
	SetPosition(currentVaus->parts[0]->gameObject.getPosition() + ballToVausOffset);
	//std::cout << GetPosition().x << std::endl;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		ChangeDirection(NormalizeVector({ 25,-25 })); //45 degrees to right
		stickedToVaus = false;
	}
}

sf::Vector2f Ball::GetDirection()
{
	return direction;
}

sf::Vector2f Ball::GetPosition()
{
	return position;
}

void Ball::SetPosition(const sf::Vector2f& newPosition)
{
	gameObject.setPosition(newPosition);
	position = newPosition;
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
	if (stickedToVaus)
	{
		StickedBallLogic();
	}
	else
	{
		UpdateCollistions();
		Move(dt);
	}
	
}
