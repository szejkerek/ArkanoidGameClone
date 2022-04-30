#include "Button.h"
#include <iostream>
#include "../Program.h"
void Button::DecrementTimer(float& dt)
{
	if (buttonCooldown <= 0)
	{
		buttonCooldown = 0;
		return;
	}
	buttonCooldown -= dt;
}

Button::Button(Program* _program) : UIElement(_program), sceneToLoad(Scenes::none)
{
}

inline bool Button::Clicked()
{
	if (buttonCooldown == 0 && (MouseHovers() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
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
}

inline void Button::LoadSceneOnClick(const Scenes& _sceneToLoad)
{
	sceneToLoad = _sceneToLoad;
}

void Button::Update(float& dt)
{
	DecrementTimer(dt);
	if (MouseHovers())
	{
		SetFillColor(sf::Color::Red);
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
