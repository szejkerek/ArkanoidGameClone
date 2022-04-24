#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"

inline sf::Vector2f MultipyVectors(sf::Vector2f vectorA, sf::Vector2f vectorB)
{
	return  sf::Vector2f(vectorA.x * vectorB.x, vectorA.y * vectorB.y);
}

inline float DotProduct(sf::Vector2f& vectorA, sf::Vector2f& vectorB)
{
	return  (vectorA.x * vectorB.x + vectorA.y * vectorB.y);
}

inline sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
	float magnitude = std::sqrt(DotProduct(vector, vector));
	if (magnitude > 0)
		vector = vector / magnitude;
	return vector;
}

struct PositionConstrains 
{
	float maxRight = 0;
	float maxLeft = 0;
	float maxUp = 0;
	float maxDown = 0;
};

enum class ColorsEnum
{
	white,
	orange,
	turquoise,
	green,
	red,
	blue,
	pink,
	yelow
};

class PixelSizes
{
#pragma region Singleton

	PixelSizes() {}
public:
	static PixelSizes& GetInstance()
	{
		static PixelSizes INSTANCE;
		return INSTANCE;
	}
	PixelSizes(PixelSizes const&) = delete;
	PixelSizes& operator=(PixelSizes const&) = delete;

#pragma endregion
public:

	sf::Vector2f healthPosition{ 199, 887 };
	sf::Vector2f healthSize{ 52, 17 };
	int healtSpacing = 11;

	float ballRadius = 7.f;

	sf::Vector2f brickSize{55,28};

	sf::Vector2f vausSize{111,28};
	sf::Vector2f vausPosition{577,857};

	sf::Vector2f playgroundSize{ 713.f,858.f };
	sf::Vector2f playgroundPosition{ 183,62 };

	sf::Vector2i windowPosition{ 310,10 };
	sf::Vector2i windowResolution{ 1300,990 };
	
};

class UserSettings
{
#pragma region Singleton

	UserSettings() {}
public:
	static UserSettings& GetInstance()
	{
		static UserSettings INSTANCE;
		return INSTANCE;
	}
	UserSettings(UserSettings const&) = delete;
	UserSettings& operator=(UserSettings const&) = delete;

#pragma endregion
public:
	float sensitivity = 10.f;
	
};
