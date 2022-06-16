#pragma once
#include "../Utility/Resources.h"
#include "UIElement.h"

class TextElement : public UIElement
{
public:
	sf::Text* text;

	TextElement(Program* program);
	~TextElement();

	virtual inline void SetText(const std::string& text, const int& fontSize, const sf::Color& color);
	virtual inline void SetTextPosition(const sf::Vector2f& position);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

