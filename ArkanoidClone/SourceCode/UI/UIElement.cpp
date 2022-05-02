#include "UIElement.h"
#include "../Utility/Utility.h"
#include "../Program.h"

UIElement::UIElement(Program* _program) : program(_program)
{
	InitGameObject();
}

inline void UIElement::InitGameObject()
{
	sf::Vector2f screenSize = static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution);
	SetSize({ 150,80 });
	SetOriginCenter();
	SetPosition({ screenSize.x/2,screenSize.y/2 });
	SetFillColor(sf::Color::White);
	SetOutlineColor(sf::Color::Color(155, 135, 12));
	SetOutlineThickness(1.f);
}

inline void UIElement::SetPosition(const sf::Vector2f& position)
{
	gameObject.setPosition(position);
}

inline void UIElement::SetSize(const sf::Vector2f& size)
{
	gameObject.setSize(size);
}

inline void UIElement::SetFillColor(const sf::Color& color)
{
	gameObject.setFillColor(color);
}

inline void UIElement::SetOriginCenter()
{
	gameObject.setOrigin(GetSize().x / 2, GetSize().y / 2);
}

inline void UIElement::SetOutlineThickness(const float& size)
{
	gameObject.setOutlineThickness(size);
}

inline void UIElement::SetOutlineColor(const sf::Color& color)
{
	gameObject.setOutlineColor(color);
}

inline sf::FloatRect UIElement::GetCollider()
{
	return gameObject.getGlobalBounds();
}

inline sf::Vector2f UIElement::GetSize()
{
	return gameObject.getSize();
}

inline sf::Vector2f UIElement::GetPosition()
{
	return gameObject.getPosition();
}

inline bool UIElement::MouseHovers()
{
	return GetCollider().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*program->window)));
}

inline void UIElement::Disable()
{
	isDisabled = true;
}

inline void UIElement::Enable()
{
	isDisabled = false;
}


void UIElement::Update(float& dt)
{
	
}

