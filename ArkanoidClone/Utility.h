#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"

inline sf::Vector2f MultipyVectors(sf::Vector2f vectorA, sf::Vector2f vectorB)
{
	return  sf::Vector2f(vectorA.x * vectorB.x, vectorA.y * vectorB.y);
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
	float ballRadius = 7.f;
	sf::Vector2f brickSize{55,28};
	sf::Vector2f playgroundSize{ 713.f,858.f };
	sf::Vector2f playgroundPosition{ 183,62 };
	sf::Vector2i windowPosition{ 310,10 };
	sf::Vector2i windowResolution{ 1300,990 };
	
};
