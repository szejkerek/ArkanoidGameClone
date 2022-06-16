#include "Ball.h"
#include "../ArkanoidClone/SourceCode/Utility/Resources.h"
#include "../ArkanoidClone/SourceCode/Scenes/GameScene.h"
#include <iostream>

Ball::Ball(GameScene* _game): EntityCircle(_game, PixelSizes::GetInstance().ballRadius),speed(800.f), stickedToVaus (false)
{
	SetOriginCenter();
	gameObject.setTexture(ResourceManager::Get().GetTexture("ball"));
	ballToVausOffset = {0,-21};
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
		SetPosition(newPosition);
		ChangeDirection(newDirection);
	}
	else if (GetPosition().y <= top)
	{
		newPosition = { GetPosition().x, top };
		newDirection = MultipyVectors(direction, changeY);
		SetPosition(newPosition);
		ChangeDirection(newDirection);
	}
	else if (gameObject.getPosition().x >= right)
	{
		newPosition = { right, GetPosition().y };
		newDirection = MultipyVectors(direction, changeX);
		SetPosition(newPosition);
		ChangeDirection(newDirection);
	}
	else if (gameObject.getPosition().y >= down)
	{

		if (gameScene->balls.size() == 1)
		{
			gameScene->powerUpManager->FreeMemory();
			gameScene->healthManager->TakeHit();
			SetPosition({ -200, -200 });
			ChangeDirection({ 0,0 });
			StickBallToVaus();
		}
		else
		{
			gameScene->RemoveBallNoDelete(this);
			SetPosition({ -200, -200 });
			ChangeDirection({ 0,0 });
		}
		return;
	}
	else
	{
		return;
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

	for (auto& brick: gameScene->currentStage->playableBricks)
	{
		if (brick == nullptr)
			continue;

		if (brick->GetCollider().intersects(ballBounds, overlap))
		{
			UpdateBrickCollision(brick, overlap);//Calculate movement
			gameScene->currentStage->CollisionDetected(brick);//Handle internal brick logic
			break;
		}
	}
}

void Ball::UpdateVausCollision()
{
	sf::FloatRect overlap;
	sf::FloatRect ballBounds = gameObject.getTransform().transformRect(gameObject.getLocalBounds());

	for (auto part : gameScene->vaus->parts)
	{
		if (part->GetCollider().intersects(ballBounds, overlap))
		{
			sf::Vector2f collisionVector = part->GetPosition() - GetPosition();
			sf::Vector2f normalToCenter = gameScene->vaus->parts[0]->GetPosition() - GetPosition();
			sf::Vector3f correctionVector = CalculateCorrectionVector(overlap, collisionVector);
			sf::Vector2f normal(correctionVector.x, correctionVector.y);

			Move(normal * correctionVector.z);   //Move ball outside brick
			if (part->IsCustomReflectionImplemented() && normal.y != 1 /*&& GetPosition().y <= part->GetCollider().top + part->GetCollider().height / 4*/) //without downside reflections
			{
				ChangeDirection(part->GetDirection());
			}
			else
			{
				ChangeDirection(ReflectedVector(direction, normal));
			}

			if (correctionVector.z >= 3.5f) //Fixed clipping with wall
			{
				SetPosition({GetPosition().x, part->GetPosition().y + ballToVausOffset.y});
				correctionVector.z = 0;
			}

			Move(normal * correctionVector.z); //Move ball outside brick

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

	direction = NormalizeVector( _direction );
}

void Ball::StickBallToVaus()
{
	stickedToVaus = true;
	gameScene->ballAirTime = 0;
}

sf::Vector2f Ball::GetDirection()
{
	return direction;
}

void Ball::InitGameObject(const float& _speed)
{
	speed = _speed;
	StickBallToVaus();
}

void Ball::ChangeBallSpeed(const float& newSpeed)
{
	speed = newSpeed;
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
	SetPosition(gameScene->vaus->parts[0]->GetPosition() + ballToVausOffset);
	

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (gameScene->ballAirTime <= 0.2f)
			return;

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