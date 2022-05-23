#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <filesystem>
#include <unordered_map>
#include <memory>
#include <iostream>

template <class ResourceType>
class Resource
{
private:
	std::string resourcePath;
	std::string resourceExtension;
	std::unordered_map<std::string, std::shared_ptr<ResourceType>> resources;
public:

	Resource(const std::string& path, const std::string& extension) : resourcePath(path), resourceExtension(extension){}
	~Resource()
	{
		for (auto i = resources.begin(); i != resources.end();)
			i = resources.erase(i);
	}

	ResourceType* GetResource(const std::string& name)
	{
		std::filesystem::path current = std::filesystem::current_path().append(resourcePath);

		const auto i = resources.find(name);
		if (i != resources.end())
		{
			return i->second.get();
		}
		else
		{
			std::shared_ptr<ResourceType> tempResource = std::make_shared<ResourceType>();
			for (std::filesystem::directory_entry entry : std::filesystem::recursive_directory_iterator(current))
			{
				if (entry.path().stem() == name)
				{
					tempResource->loadFromFile(entry.path().string());
					resources.insert({ name , tempResource });
					return tempResource.get();
				}
					
			}
			return nullptr;
			
		}
	}
};

class ResourceManager
{
#pragma region Singleton

	ResourceManager()
		:textures("Resources/Textures", ".png"),
		fonts("Resources/Fonts", ".ttf"),
		soundBuffers("Resources/Audio", ".wav")
	{}
public:
	static ResourceManager& Get()
	{
		static ResourceManager INSTANCE;
		return INSTANCE;
	}
	ResourceManager(ResourceManager const&) = delete;
	ResourceManager& operator=(ResourceManager const&) = delete;

#pragma endregion
private:
	Resource<sf::Font>			fonts;
	Resource<sf::Texture>		textures;
	Resource<sf::SoundBuffer>	soundBuffers;
		
public:
	sf::Font*			GetFont(const std::string& name);
	sf::Texture*		GetTexture(const std::string& name);
	sf::SoundBuffer*	GetAudio(const std::string& name);

};
