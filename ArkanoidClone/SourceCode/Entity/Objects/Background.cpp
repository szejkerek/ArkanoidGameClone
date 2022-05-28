#include "Background.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
#include "../ArkanoidClone/SourceCode/Utility/Resources.h"
void Background::InitGameObject()
{
	SetPosition(PixelSizes::GetInstance().backgroundPosition);
	SetSize(PixelSizes::GetInstance().backgroundSize);
	SetFillColor(sf::Color::Color(255,255,255,255));
	SetTexture(ResourceManager::Get().GetTexture("background1"));
}

Background::Background(GameScene* game):EntityRectangle(game, PixelSizes::GetInstance().backgroundPosition)
{
	InitGameObject();
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameObject);
}
