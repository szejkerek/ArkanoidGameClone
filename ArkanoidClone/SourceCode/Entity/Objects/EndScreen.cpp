#include "EndScreen.h"
#include "../ArkanoidClone/SourceCode/Program.h"
#include "../ArkanoidClone/SourceCode/Utility/Resources.h"

EndScreen::EndScreen(Program* _program): program(_program)
{
	sf::Vector2f windowCenter = { static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution).x / 2,
								  static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution).y / 2 };
	endscreen.setSize({ 800,300 });
	endscreen.setTexture(ResourceManager::Get().GetTexture("endgame"));
	endscreen.setOrigin({ endscreen.getSize().x/2, endscreen.getSize().y/2 });
	endscreen.setPosition(windowCenter);

	background.setSize(static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution));
	background.setFillColor(sf::Color(0,0,0,185));
	background.setPosition({ 0,0 });

	continueBtn = new Button(_program);
	continueBtn->PlaceOnScene({ windowCenter.x, windowCenter.y + 75 }, ButtonType::RectangleMedium, "Continue", 18, Scenes::Menu);

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
	target.draw(endscreen);
	target.draw(*continueBtn);
	target.draw(*text);
}
