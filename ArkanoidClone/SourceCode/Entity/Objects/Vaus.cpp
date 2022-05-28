#include "Vaus.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
float ValidatePosition(const sf::Vector2f& position) 
{
	float playgroundPosition = PixelSizes::GetInstance().backgroundPosition.x;
	float playgroundSize = PixelSizes::GetInstance().backgroundSize.x;
	float vausSize = PixelSizes::GetInstance().vausSize.x;

	if (position.x <= playgroundPosition + vausSize / 2)
	{
		return playgroundPosition + vausSize / 2;
	}
	else if (position.x  >= playgroundPosition + playgroundSize - vausSize / 2)
	{
		return playgroundPosition + playgroundSize - vausSize / 2;
	}
	else
	{
		return position.x;
	}
}

void Vaus::Move(float& dt)
{
	position += direction * speed * dt * UserSettings::GetInstance().sensitivity;
	position.x = ValidatePosition(position);

	SetPosition(position);
}
void Vaus::SetPosition(const sf::Vector2f& _position)
{
	for (auto part : parts)
		part->SetPosition(_position);
}

void Vaus::InitParts()
{
	float centerSize = PixelSizes::GetInstance().iVausCentralSize.x;
	float greySize = PixelSizes::GetInstance().iVausGreySize.x;
	float redSize = PixelSizes::GetInstance().iVausRedSize.x;
	float blueSize = PixelSizes::GetInstance().iVausBlueSize.x;

	float centerOffset = 0;
	float greyOffset = greySize / 2 + centerSize / 2;
	float redOffset = greySize + redSize / 2 + centerSize / 2;
	float blueOffset = greySize + redSize + blueSize / 2 + centerSize / 2;

	parts.push_back(new CentralPart({ centerOffset,0 }));
	parts.push_back(new GreyPart({ greyOffset,0 }));
	parts.push_back(new GreyPart({ -greyOffset,0 }));
	parts.push_back(new RedPart({ redOffset,0 }));
	parts.push_back(new RedPart({ -redOffset,0 }));
	parts.push_back(new BluePart({ blueOffset,0 }));
	parts.push_back(new BluePart({ -blueOffset,0 }));
	 
	SetPosition(position);
}
Vaus::Vaus()
{
	position = PixelSizes::GetInstance().vausPosition;
	InitParts();
}

Vaus::~Vaus()
{
	for (auto part : parts)
		delete part;
}

void Vaus::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto part : parts)
		target.draw(*part);
}

void Vaus::Update(float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		direction = { -1, 0 };
		Move(dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		direction = { 1, 0 };
		Move(dt);
	}
}
