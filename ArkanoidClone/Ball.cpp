#include "Ball.h"
#include "Utility.h"
#include <iostream>

Ball::Ball(Stage* _stage, Vaus* _vaus): EntityCircle(PixelSizes::GetInstance().ballRadius),speed(400.f) ,stickedToVaus(true), currentStage(_stage), currentVaus(_vaus)
{
	SetOriginCenter();
	SetFillColor(sf::Color::White);
	ballToVausOffset = {0,-21};
	StickBallToVaus(ballToVausOffset);
}

void Ball::UpdateWallCollisions()
{
	sf::Vector2f changeX = { -1.f, 1.f };
	sf::Vector2f changeY = { 1.f, -1.f };
	float top = playgroundCollider.top + GetRadius();
	float right = playgroundCollider.left + playgroundCollider.width - GetRadius();
	float down = playgroundCollider.top + playgroundCollider.height - GetRadius();
	float left = playgroundCollider.left + GetRadius();

	sf::Vector2f newPosition;
	sf::Vector2f newDirection;

	if (GetPosition().x <= left)
	{
		newPosition = { left , GetPosition().y};
		newDirection = MultipyVectors(direction, changeX);
	}
	else if (GetPosition().y <= top)
	{
		newPosition = { GetPosition().x, top };
		newDirection = MultipyVectors(direction, changeY);
	}
	else if (gameObject.getPosition().x >= right)
	{
		newPosition = { right, GetPosition().y };
		newDirection = MultipyVectors(direction, changeX);
	}
	else if (gameObject.getPosition().y >= down)
	{
		newPosition = { GetPosition().x, down };
		newDirection = MultipyVectors(direction, changeY);
	}
	else
	{
		return;
	}

	SetPosition(newPosition);
	ChangeDirection(newDirection);

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
		if (brick->GetCollider().intersects(ballBounds, overlap))
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

void Ball::SetPlaygroundConstrains(const sf::FloatRect& _playgroundConstrains)
{
	playgroundCollider = _playgroundConstrains;
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

void Ball::InitGameObject(const float& _speed)
{
	speed = _speed;
	StickBallToVaus(ballToVausOffset);
}

void Ball::UpdateCollistions()
{
	UpdateWallCollisions();
	UpdateBricksCollision();
	UpdateVausCollision();
}

void Ball::Move(float& dt)
{
	SetPosition(GetPosition() + (direction * speed * dt));
}

void Ball::Move(sf::Vector2f moveToVector)
{
	SetPosition(GetPosition() + moveToVector);
}

void Ball::StickedBallLogic()
{
	SetPosition(currentVaus->parts[0]->gameObject.getPosition() + ballToVausOffset);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		ChangeDirection(NormalizeVector({ 25,-25 })); //45 degrees to right
		stickedToVaus = false;
	}
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

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}