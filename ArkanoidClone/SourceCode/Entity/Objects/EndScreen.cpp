#include "EndScreen.h"
#include "../ArkanoidClone/SourceCode/Program.h"
#include "../ArkanoidClone/SourceCode/Utility/Resources.h"

EndScreen::EndScreen(Program* _program): program(_program)
{
	sf::Vector2f windowCenter = { static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution).x / 2,
								  static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution).y / 2 };
	background.setSize({ 800,300 });
	background.setFillColor(sf::Color::Black);
	background.setOrigin({ background.getSize().x/2, background.getSize().y/2 });
	background.setPosition(windowCenter);

	continueBtn = new Button(_program);
	continueBtn->PlaceOnScene({ windowCenter.x, windowCenter.y + 75 }, ButtonType::RectangleMedium, "Continue", 18.f, Scenes::LevelSelectorOriginal);

	text = new TextElement(_program);
	text->SetTextPosition({ windowCenter.x, windowCenter.y - 75 });
	text->SetText("GAME OVER!", 75, sf::Color::White);

}

EndScreen::~EndScreen()
{
	if (continueBtn != nullptr)
		delete continueBtn;
}

void EndScreen::SetWinning()
{
	text->SetText("YOU WIN!!!", 75, sf::Color::White);
}

void EndScreen::Update(float& dt)
{
	continueBtn->Update(dt);
}

void EndScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(*continueBtn);
	target.draw(*text);
}
