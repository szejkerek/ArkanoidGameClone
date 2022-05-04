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
		buttonCooldown = defalutButtonCooldown;
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

inline void Button::SetOnClickFunction(std::function<void()> function)
{
	onClickFunction = function;
}

inline void Button::LoadSceneOnClick(const Scenes& _sceneToLoad)
{
	sceneToLoad = _sceneToLoad;
}

inline void Button::PlaceOnScene(const sf::Vector2f& position, const ButtonType& type, std::string displayText, const Scenes& sceneToLoad)
{
	ChooseButton(type);
	SetOriginCenter();
	SetPosition(position);
	//SetText
	LoadSceneOnClick(sceneToLoad);
}

inline void Button::PlaceOnScene(const sf::Vector2f& position, const ButtonType& type, std::string displayText)
{
	ChooseButton(type);
	SetOriginCenter();
	SetPosition(position);
	//SetText
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
		SetFillColor(sf::Color::Color(200, 200, 200));
		gameObject.setScale(1.04f, 1.04f);
	}	
	else
	{
		SetFillColor(sf::Color::Color(255,255,255,255));
		gameObject.setScale(1.f, 1.f);
	}


	if (Clicked())
	{
		OnClick();
	}
	
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
