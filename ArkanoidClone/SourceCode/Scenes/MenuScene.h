#pragma once
#include "../Scenes/Scene.h"
#include "../UI/Button.h"
class Program;
class MenuScene : public Scene
{
	sf::RectangleShape backgroundBehind;
	Button* levelSelectorBtn;
	Button* tutorialSceneBtn;
	Button* exitBtn;
	Program* program;
	void CloseWindow();
public:
	MenuScene(Program* _program);
	~MenuScene();
	
	virtual void Update(float& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

