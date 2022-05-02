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

inline void Button::SetOnClickFunction(std::function<void()> function)
{
	onClickFunction = function;
}

inline void Button::LoadSceneOnClick(const Scenes& _sceneToLoad)
{
	sceneToLoad = _sceneToLoad;
}

inline void Button::PlaceOnScene(const sf::Vector2f& position, const sf::Vector2f& size, std::string displayText, const Scenes& sceneToLoad)
{
	SetPosition(position);
	SetSize(size);
	//SetText
	LoadSceneOnClick(sceneToLoad);
}

inline void Button::PlaceOnScene(const sf::Vector2f& position, const sf::Vector2f& size, std::string displayText)
{
	SetPosition(position);
	SetSize(size);
	//SetText
}

inline void Button::PlaceOnScene(const sf::Vector2f& position, const sf::Vector2f& size)
{
	SetPosition(position);
	SetSize(size);
}

void Button::Update(float& dt)
{
	DecrementTimer(dt);
	if (MouseHovers())
	{
		SetFillColor(sf::Color::Red);
	}
	else if (isDisabled)
	{
		SetFillColor(sf::Color::Magenta);
	}
	else
	{
		SetFillColor(sf::Color::White);
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
