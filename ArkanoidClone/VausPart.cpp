#include "VausPart.h"
#include "Utility.h"
void IVausPart::InitGameObject(const sf::Vector2f& size, const sf::Color& color)
{
	gameObject.setSize(size);
	gameObject.setFillColor(color);
	gameObject.setOrigin(size.x / 2, size.y / 2);
}
IVausPart::IVausPart(const ReflectionTurnType& type) : reflectionType(type)
{
	if (type == ReflectionTurnType::left)
		directionSign = -1;
	else if (type == ReflectionTurnType::right)
		directionSign = 1;
}

sf::Vector2f IVausPart::GetDirection()
{
	return GetReflectionVector();
}

inline bool IVausPart::IsCustomReflectionImplemented()
{
	return (reflectionType == ReflectionTurnType::none) ? false : true;
}

void IVausPart::SetPosition(const sf::Vector2f& position)
{
	gameObject.setPosition(position);
}

void IVausPart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

CentralPart::CentralPart(const ReflectionTurnType& type) : IVausPart(type)
{
	InitGameObject({ 23,28 }, sf::Color::Color(72, 72, 72));
}

GreyPart::GreyPart(const ReflectionTurnType& type) : IVausPart(type)
{
	InitGameObject({ 17,28 }, sf::Color::Color(107, 107, 107));
}

RedPart::RedPart(const ReflectionTurnType& type) : IVausPart(type)
{
	InitGameObject({ 17,28 }, sf::Color::Red);
}

BluePart::BluePart(const ReflectionTurnType& type) : IVausPart(type)
{
	InitGameObject({ 10,28 }, sf::Color::Blue);
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
	//Should never be called
	return {0,0};
}
