#pragma once
#include "../Scenes/Scene.h"
#include "../UI/Button.h"
class Program;
class MenuScene : public Scene
{
public:
	MenuScene(Program* _program);
	~MenuScene();
	
	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Program* program;
	sf::RectangleShape backgroundBehind;
	sf::RectangleShape logo;
	Button* levelSelectorBtn;
	Button* tutorialSceneBtn;
	Button* exitBtn;

	void CloseWindow();
};

