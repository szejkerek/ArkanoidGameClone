#pragma once
#include "SFML/Graphics.hpp"
#include "../ArkanoidClone/SourceCode/UI/Button.h"
#include "../ArkanoidClone/SourceCode/UI/TextElement.h"

class Program;
class EndScreen : public sf::Drawable
{
public:
	EndScreen(Program* program);
	~EndScreen();
	void SetWinning();
	void Update(float& dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	
	Program* program;
	sf::RectangleShape endscreen;
	sf::RectangleShape background;
	TextElement* text;
	Button* continueBtn;
};

