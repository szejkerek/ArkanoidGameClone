#pragma once
#include "UIElement.h"
#include "../Scenes/SceneManager.h"
class Button :public UIElement
{
private:
	Scenes sceneToLoad;
	float buttonCooldown = .1f;
	float defalutButtonCooldown = .1f;
	void DecrementTimer(float& dt);
public:
	Button(Program* _program);
	virtual inline bool Clicked();
	virtual inline void OnClick();
	virtual inline void LoadSceneOnClick(const Scenes& sceneToLoad);
	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

