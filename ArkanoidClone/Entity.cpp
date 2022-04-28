#include "Entity.h"

EntityRectangle::EntityRectangle(const sf::Vector2f& size)
{
	InitGameObject();
	SetSize(size);
}

inline void EntityRectangle::InitGameObject()
{
	gameObject.setSize({ 10.f,10.f });
	gameObject.setPosition(0, 0);
	gameObject.setFillColor(sf::Color::Color(0, 0, 0, 0));
	gameObject.setOutlineColor(sf::Color::Color(155,135,12));
	gameObject.setOutlineThickness(1.f);
}

inline void EntityRectangle::SetPosition(const sf::Vector2f& position)
{
	gameObject.setPosition(position);
}

inline void EntityRectangle::SetSize(const sf::Vector2f& size)
{
	gameObject.setSize(size);
}

inline void EntityRectangle::SetFillColor(const sf::Color& color)
{
	gameObject.setFillColor(color);
}

inline void EntityRectangle::SetOriginCenter()
{
	gameObject.setOrigin(GetSize().x / 2, GetSize().y / 2);
}

inline void EntityRectangle::SetOutlineThickness(const float& size)
{
	gameObject.setOutlineThickness(size);
}

inline void EntityRectangle::SetOutlineColor(const sf::Color& color)
{
	gameObject.setOutlineColor(color);
}

inline sf::FloatRect EntityRectangle::GetCollider()
{
	return gameObject.getGlobalBounds();
}

inline sf::Vector2f EntityRectangle::GetPosition()
{
	return gameObject.getPosition();
}

inline sf::Vector2f EntityRectangle::GetSize()
{
	return gameObject.getSize();
}

EntityCircle::EntityCircle(const float& radius)
{
	InitGameObject();
	SetRadius(radius);
}

inline void EntityCircle::InitGameObject()
{
	gameObject.setRadius( 10.f );
	gameObject.setPosition(0, 0);
	gameObject.setFillColor(sf::Color::Color(0, 0, 0, 0));
	gameObject.setOutlineColor(sf::Color::Color(155, 135, 12));
	gameObject.setOutlineThickness(1.f);
}

inline void EntityCircle::SetPosition(const sf::Vector2f& position)
{
	gameObject.setPosition(position);
}

inline void EntityCircle::SetRadius(const float& radius)
{
	gameObject.setRadius(radius);
}

inline void EntityCircle::SetFillColor(const sf::Color& color)
{
	gameObject.setFillColor(color);
}

inline void EntityCircle::SetOriginCenter()
{
	gameObject.setOrigin(GetRadius() , GetRadius() );
}

inline void EntityCircle::SetOutlineThickness(const float& size)
{
	gameObject.setOutlineThickness(size);
}

inline sf::Vector2f EntityCircle::GetPosition()
{
	return gameObject.getPosition();
}

inline sf::FloatRect EntityCircle::GetCollider()
{
	return gameObject.getGlobalBounds();
}

inline float EntityCircle::GetRadius()
{
	return gameObject.getRadius();
}



inline void EntityCircle::SetOutlineColor(const sf::Color& color)
{
	gameObject.setOutlineColor(color);
}
