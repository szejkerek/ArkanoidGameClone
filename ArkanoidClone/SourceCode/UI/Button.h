#pragma once
#include <functional>
#include "UIElement.h"
#include "../Scenes/SceneManager.h"
class Button :public UIElement
{
protected:
	Scenes sceneToLoad;
	std::function<void()> onClickFunction = nullptr;

	float buttonCooldown = .1f;
	float defalutButtonCooldown = .1f;
	void DecrementTimer(float& dt);
	virtual inline bool Clicked();
	virtual inline void OnClick();
public:
	Button(Program* _program);
	virtual inline void SetOnClickFunction(std::function<void()> function);
	virtual inline void LoadSceneOnClick(const Scenes& sceneToLoad);

	virtual inline void PlaceOnScene(const sf::Vector2f& position, const sf::Vector2f& size, std::string displayText, const Scenes& sceneToLoad);
	virtual inline void PlaceOnScene(const sf::Vector2f& position, const sf::Vector2f& size, std::string displayText);
	virtual inline void PlaceOnScene(const sf::Vector2f& position, const sf::Vector2f& size);

	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

