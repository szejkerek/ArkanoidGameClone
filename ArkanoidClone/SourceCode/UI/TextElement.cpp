#include "TextElement.h"

TextElement::TextElement(Program* program) : UIElement(program)
{
	InitGameObject();
}

TextElement::~TextElement()
{
	delete text;
}

inline void TextElement::InitGameObject()
{
	text = new sf::Text;
	text->setFont(*ResourceManager::Get().GetFont("arcade2"));
	text->setString("PLACEHOLDER");
	text->setCharacterSize(20);
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
	sf::FloatRect collider = GetCollider();
	text->setOrigin(collider.left + collider.width / 2, collider.top + collider.height / 2);
}

void TextElement::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*text);
}
