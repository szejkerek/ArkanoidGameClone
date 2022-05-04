#pragma once
#include <functional>
#include "UIElement.h"
#include "../Scenes/SceneManager.h"

enum class ButtonType
{
	RectangleBig,
	RectangleMedium,
	RectangleSmall,
	squareBig,
	squareMedium,
	squareSmall
};

class Button :public UIElement
{
protected:
	Scenes sceneToLoad;
	std::function<void()> onClickFunction = nullptr;
	sf::Text text;
	float buttonCooldown = .3f;
	float defalutButtonCooldown = .3f;
	sf::Vector2f buttonSize;


	void DecrementTimer(float& dt);
	virtual inline bool Clicked();
	virtual inline void OnClick();
	virtual inline void ChooseButton(const ButtonType& buttonType);

public:
	Button(Program* _program);
	virtual inline void SetOnClickFunction(std::function<void()> function);
	virtual inline void LoadSceneOnClick(const Scenes& sceneToLoad);
	virtual void SetText(const std::string& _text, const int& fontSize);

	virtual inline void PlaceOnScene(const sf::Vector2f& position, const ButtonType& buttonType, std::string displayText, const int& fontsize, const Scenes& sceneToLoad);
	virtual inline void PlaceOnScene(const sf::Vector2f& position, const ButtonType& buttonType, std::string displayText, const int& fontsize);
	virtual inline void PlaceOnScene(const sf::Vector2f& position, const ButtonType& buttonType);

	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

