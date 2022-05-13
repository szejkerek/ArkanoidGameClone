#include "Button.h"
#include <iostream>
#include "../Program.h"


Button::Button(Program* _program) : UIElement(_program), sceneToLoad(Scenes::none)
{
	
}

void Button::DecrementTimer(float& dt)
{
	if (buttonCooldown <= 0)
	{
		buttonCooldown = 0;
		return;
	}
	buttonCooldown -= dt;
}

inline bool Button::Clicked()
{
	if (buttonCooldown == 0 && !isDisabled && (MouseHovers() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
	{
		buttonCooldown = defaultButtonCooldown;
		return true;
	}
	else
	{
		return false;
	}
}



inline void Button::OnClick()
{
	program->sceneManager->LoadScene(sceneToLoad);

	if(onClickFunction != nullptr)
		onClickFunction();
}


inline void Button::ChooseButton(const ButtonType& buttonType)
{
	switch (buttonType)
	{
	case ButtonType::RectangleBig:
		SetSize({ 250,100 });
		SetTexture(ResourceManager::Get().GetTexture("buttonRectangle"));
		break;
	case ButtonType::RectangleMedium:
		SetSize({ 250 * 0.75,100 * 0.75 });
		SetTexture(ResourceManager::Get().GetTexture("buttonRectangle"));
		break;
	case ButtonType::RectangleSmall:
		SetSize({ 250 * 0.40,100 * 0.40 });
		SetTexture(ResourceManager::Get().GetTexture("buttonRectangle"));
		break;
	case ButtonType::squareBig:
		SetSize({ 100,100 });
		SetTexture(ResourceManager::Get().GetTexture("buttonSquare"));
		break;
	case ButtonType::squareMedium:
		SetSize({ 100 * 0.75,100 * 0.75 });
		SetTexture(ResourceManager::Get().GetTexture("buttonSquare"));
		break;
	case ButtonType::squareSmall:
		SetSize({ 100 * 0.40,100 * 0.40 });
		SetTexture(ResourceManager::Get().GetTexture("buttonSquare"));
		break;
	}

	buttonSize = GetSize();
}

void Button::SetText(const std::string& _text, const int& fontSize)
{
	sf::Font* tempFont = ResourceManager::Get().GetFont("arcade2");
	text.setString(_text);
	text.setFont(*tempFont);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontSize);
	
	sf::FloatRect collider = text.getGlobalBounds();
	text.setOrigin(collider.left + collider.width / 2, collider.top + collider.height / 2);

	text.setPosition(GetPosition());

	

}

inline void Button::SetOnClickFunction(std::function<void()> function)
{
	onClickFunction = function;
}

inline void Button::LoadSceneOnClick(const Scenes& _sceneToLoad)
{
	sceneToLoad = _sceneToLoad;
}



inline void Button::PlaceOnScene(const sf::Vector2f& position, const ButtonType& type, std::string displayText,const int& fontsize , const Scenes& sceneToLoad)
{
	ChooseButton(type);
	SetOriginCenter();
	SetPosition(position);
	SetText(displayText, fontsize);
	LoadSceneOnClick(sceneToLoad);
}

inline void Button::PlaceOnScene(const sf::Vector2f& position, const ButtonType& type, std::string displayText, const int& fontsize)
{
	ChooseButton(type);
	SetOriginCenter();
	SetPosition(position);
	SetText(displayText, fontsize);

}

inline void Button::PlaceOnScene(const sf::Vector2f& position, const ButtonType& type)
{
	ChooseButton(type);
	SetOriginCenter();
	SetPosition(position);
}

void Button::Update(float& dt)
{
	DecrementTimer(dt);
	if (isDisabled)
	{
		SetFillColor(sf::Color::Color(90, 90, 90));
	}
	else if (MouseHovers())
	{
		SetFillColor(sf::Color::Color(255, 255, 255, 255));
		gameObject.setScale(1.04f, 1.04f);

		text.setFillColor(sf::Color::Color(0, 0, 0, 255));
		text.setScale(1.08f, 1.08f);
	}	
	else
	{
		SetFillColor(sf::Color::Color(220, 220, 220));
		gameObject.setScale(1.f, 1.f);

		text.setFillColor(sf::Color::Color(20, 20, 20));
		text.setScale(1.f, 1.f);
	}

	if (Clicked())
	{
		OnClick();
	}
	
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
	target.draw(text);
}
