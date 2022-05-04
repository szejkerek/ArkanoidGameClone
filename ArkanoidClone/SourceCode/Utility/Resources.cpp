#include "Resources.h"
#include <iostream>

sf::Texture* ResourceManager::GetTexture(const std::string& name)
{
	return textures.GetResource(name);
}

sf::Font* ResourceManager::GetFont(const std::string& name)
{
	return fonts.GetResource(name);
}

sf::SoundBuffer* ResourceManager::GetAudio(const std::string& name)
{
	return soundBuffers.GetResource(name);
}


