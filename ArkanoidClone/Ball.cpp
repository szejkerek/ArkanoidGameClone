#include "Ball.h"
#include "Utility.h"

Ball::Ball(sf::Vector2f _position, sf::Vector2f _direction, float _speed, Stage* _stage): currentStage(_stage)
{
	gameObject.setRadius(PixelSizes::GetInstance().ballRadius);
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

	if (GetPoistion().x <= playgroundConstrains.maxLeft)
	{
		position.x = playgroundConstrains.maxLeft;
		ChangeDirection(MultipyVectors(direction, changeX));
	}
	else if (GetPoistion().y <= playgroundConstrains.maxUp)
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

void Ball::UpdateBrickCollision(IBrick* brick)
{
	sf::Vector2f changeX = { -1.f, 1.f };
	sf::Vector2f changeY = { 1.f, -1.f };

	sf::Vector2f ballPosition = GetPoistion();
	PositionConstrains brickConstrains = brick->GetConstrains();

	sf::Vector2f brickCeneter = brick->GetCenterPoint();

	
	if (ballPosition.x > brickConstrains.maxLeft && ballPosition.x < brickConstrains.maxRight) // Pionowy tunel
	{
		if (ballPosition.y < brickCeneter.y && ballPosition.y > brickConstrains.maxUp) //UpperHalf
		{
			std::cout << "Upper"<<std::endl;
			position.y = brickConstrains.maxUp;
			ChangeDirection(MultipyVectors(direction, changeY));

		}
		else if (ballPosition.y > brickCeneter.y && ballPosition.y < brickConstrains.maxDown) //BottomHalf
		{
			std::cout << "Bottom" << std::endl;
			position.y = brickConstrains.maxDown;
			ChangeDirection(MultipyVectors(direction, changeY));
		}
	}
	else if (ballPosition.y < brickConstrains.maxDown && ballPosition.y > brickConstrains.maxUp) // Poziomy tunel
	{
		if (ballPosition.x < brickCeneter.x && ballPosition.x > brickConstrains.maxLeft) //LeftHalf
		{
			std::cout << "Left" << std::endl;
			position.x = brickConstrains.maxLeft;
			ChangeDirection(MultipyVectors(direction, changeX));
		}
		else if (ballPosition.x > brickCeneter.x && ballPosition.x < brickConstrains.maxRight) //RightHalf
		{
			std::cout << "Right" << std::endl;
			position.x = brickConstrains.maxRight;
			ChangeDirection(MultipyVectors(direction, changeX));
		}
	}

	/*if (GetPoistion().x <= brick->GetConstrains().maxLeft)
	{
		position.x = playgroundConstrains.maxLeft;
		ChangeDirection(MultipyVectors(direction, changeX));
	}
	else if (GetPoistion().y <= brick->GetConstrains().maxUp)
	{
		position.y = playgroundConstrains.maxUp;
		ChangeDirection(MultipyVectors(direction, changeY));
	}
	else if (gameObject.getPosition().x >= brick->GetConstrains().maxRight)
	{
		position.x = playgroundConstrains.maxRight;
		ChangeDirection(MultipyVectors(direction, changeX));
	}
	else if (gameObject.getPosition().y >= brick->GetConstrains().maxDown)
	{
		position.y = playgroundConstrains.maxDown;
		ChangeDirection(MultipyVectors(direction, changeY));
	}*/
}

void Ball::UpdateBricksCollision()
{
	for (auto& brick: currentStage->playableBricks)
	{
		UpdateBrickCollision(brick);
	}
}

void Ball::Move(float& dt)
{
	position += direction * speed * dt;
	gameObject.setPosition(position);
}

sf::Vector2f Ball::GetDirection()
{
	return direction;
}

sf::Vector2f Ball::GetPoistion()
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
	UpdateCollistions();
	Move(dt);
}
