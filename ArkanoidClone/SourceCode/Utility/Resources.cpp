#include "Resources.h"
#include <iostream>

sf::Texture* ResourceManager::GetTexture(const std::string& name)
{
	return textures.GetResource(name);
}


