#include "VausPart.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
void IVausPart::InitGameObject(const sf::Vector2f& positionOffset, const sf::Vector2f& size)
{
	SetSize(size);
	SetOriginCenter();
	this->positionOffset = positionOffset;
}
IVausPart::IVausPart(GameScene* _game, const sf::Vector2f& _positionOffset) : EntityRectangle(_game,{ 0,0 }), positionOffset(_positionOffset)
{
	if (_positionOffset.x < 0)
		directionSign = -1;
	else if (_positionOffset.x > 0)
		directionSign = 1;
	else if (_positionOffset.x == 0)
		directionSign = 0;
}

sf::Vector2f IVausPart::GetDirection()
{
	return GetReflectionVector();
}

inline bool IVausPart::IsCustomReflectionImplemented()
{
	return (positionOffset.x == 0) ? false : true;
}

void IVausPart::SetPosition(const sf::Vector2f& position)
{
	gameObject.setPosition(position + GetPositionOffset());
}

sf::Vector2f IVausPart::GetPositionOffset()
{
	return positionOffset;
}

void IVausPart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

CentralPart::CentralPart(const sf::Vector2f& _positionOffset) : IVausPart(gameScene,_positionOffset)
{
	sf::Vector2f sizeOfPart = PixelSizes::GetInstance().iVausCentralSize;
	InitGameObject(_positionOffset, sizeOfPart);
}

GreyPart::GreyPart(const sf::Vector2f& _positionOffset) : IVausPart(gameScene, _positionOffset)
{
	sf::Vector2f sizeOfPart = PixelSizes::GetInstance().iVausGreySize;
	InitGameObject(_positionOffset, sizeOfPart);
}

RedPart::RedPart(const sf::Vector2f& _positionOffset) : IVausPart(gameScene, _positionOffset)
{
	sf::Vector2f sizeOfPart = PixelSizes::GetInstance().iVausRedSize;
	InitGameObject(_positionOffset, sizeOfPart);
}

BluePart::BluePart(const sf::Vector2f& _positionOffset) : IVausPart(gameScene, _positionOffset)
{
	sf::Vector2f sizeOfPart = PixelSizes::GetInstance().iVausBlueSize;
	InitGameObject(_positionOffset, sizeOfPart);
}

inline sf::Vector2f BluePart::GetReflectionVector()
{
	float x = 81 * static_cast<float>(directionSign);
	return NormalizeVector({ x, -49});
}

inline sf::Vector2f RedPart::GetReflectionVector()
{
	float x = 3 * static_cast<float>(directionSign);
	return NormalizeVector({ x, -3 });
}

inline sf::Vector2f GreyPart::GetReflectionVector()
{
	float x = 36 * static_cast<float>(directionSign);
	return NormalizeVector({ x, -84 });
}

sf::Vector2f CentralPart::GetReflectionVector()
{
	return {0,0};
}
