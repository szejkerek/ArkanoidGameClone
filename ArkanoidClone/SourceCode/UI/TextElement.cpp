#include "TextElement.h"
#include <iostream>

TextElement::TextElement(Program* program) : UIElement(program)
{
	text = new sf::Text;
	text->setFont(*ResourceManager::Get().GetFont("arcade2"));
	text->setString("");
}

TextElement::~TextElement()
{
	delete text;
}

inline void TextElement::SetTextPosition(const sf::Vector2f& position)
{
	text->setPosition(position);
}

inline void TextElement::SetText(const std::string& _text, const int& fontSize, const sf::Color& color)
{
	text->setString(_text);
	text->setCharacterSize(fontSize);
	text->setFillColor(color);

	sf::FloatRect collider = text->getGlobalBounds();
	text->setOrigin(collider.width / 2, collider.height / 2);
}

void TextElement::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*text);
}
