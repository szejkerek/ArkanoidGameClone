#include "Background.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
#include "../ArkanoidClone/SourceCode/Utility/Resources.h"
#include "../ArkanoidClone/SourceCode/Scenes/GameScene.h"
void Background::InitGameObject()
{
	SetPosition(PixelSizes::GetInstance().backgroundPosition);
	SetSize(PixelSizes::GetInstance().backgroundSize);
	//SetFillColor(sf::Color::Color(255,255,255,255));

	switch (stageNumber % 3)
	{
	case 0:
		SetTexture(ResourceManager::Get().GetTexture("background1"));
		break;
	case 1:
		SetTexture(ResourceManager::Get().GetTexture("background2"));
		break;
	case 2:
		SetTexture(ResourceManager::Get().GetTexture("background3"));
		break;
	default:
		break;
	}
}

Background::Background(GameScene* game):EntityRectangle(game, PixelSizes::GetInstance().backgroundPosition)
{
	InitGameObject();
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}

void Background::PickBackground(int _stageNumber)
{
	stageNumber = _stageNumber;
	InitGameObject();
}
