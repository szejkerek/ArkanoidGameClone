#include "TutorialScene.h"
#include "../ArkanoidClone/SourceCode/Utility/Resources.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"

TutorialScene::TutorialScene(Program* _program) : Scene(_program)
{
	sf::Vector2f window = static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution);
	float screenMargin = 0;
	float buttonPadding = 150;

	backToMenuBtn = new Button(program);
	

	backToMenuBtn->PlaceOnScene({ screenMargin + backToMenuBtn->GetSize().x, window.y - backToMenuBtn->GetSize().y - screenMargin }, ButtonType::RectangleMedium, "Back", 30, Scenes::Menu);
	backgroundBehind.setSize(static_cast<sf::Vector2f>(PixelSizes::GetInstance().windowResolution));
	backgroundBehind.setTexture(ResourceManager::Get().GetTexture("backgroundMenu"));
}

TutorialScene::~TutorialScene()
{
	delete backToMenuBtn;
}

void TutorialScene::Update(float& dt)
{
	backToMenuBtn->Update(dt);
}

void TutorialScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(backgroundBehind);
	target.draw(*backToMenuBtn);
}
