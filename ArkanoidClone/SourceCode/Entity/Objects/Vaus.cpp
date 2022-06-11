#include "Vaus.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
#include "../ArkanoidClone/SourceCode/Utility/Resources.h"
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

	IVausPart* greyPartCentral = new CentralPart({ centerOffset,0 });
	greyPartCentral->SetTexture(ResourceManager::Get().GetTexture("Vaus_CG"));

	IVausPart* greyPartRight = new GreyPart({ greyOffset,0 });
	greyPartRight->SetTexture(ResourceManager::Get().GetTexture("Vaus_RG"));

	IVausPart* greyPartLeft = new GreyPart({ -greyOffset,0 });
	greyPartLeft->SetTexture(ResourceManager::Get().GetTexture("Vaus_LG"));

	IVausPart* redPartRight = new RedPart({ redOffset,0 });
	redPartRight->SetTexture(ResourceManager::Get().GetTexture("Vaus_RR"));

	IVausPart* redPartLeft = new RedPart({ -redOffset,0 });
	redPartLeft->SetTexture(ResourceManager::Get().GetTexture("Vaus_LR"));

	IVausPart* bluePartRight = new BluePart({ blueOffset,0 });
	bluePartRight->SetTexture(ResourceManager::Get().GetTexture("Vaus_RB"));

	IVausPart* bluePartLeft = new BluePart({ -blueOffset,0 });
	bluePartLeft->SetTexture(ResourceManager::Get().GetTexture("Vaus_LB"));

	parts.push_back(greyPartCentral);
	parts.push_back(greyPartRight);
	parts.push_back(greyPartLeft);
	parts.push_back(redPartRight);
	parts.push_back(redPartLeft);
	parts.push_back(bluePartRight);
	parts.push_back(bluePartLeft);
	 
	SetPosition(position);
}
Vaus::Vaus()
{
	position = PixelSizes::GetInstance().vausPosition;
	InitParts();
}

Vaus::~Vaus()
{
	for (int i = 0; i < parts.size(); i++)
	{
		if (parts[i] != nullptr)
			delete parts[i];
	}
}

void Vaus::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	for (int i = 0; i < parts.size(); i++)
	{
		if (parts[i] != nullptr)
			target.draw(*parts[i]);
	}		
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
