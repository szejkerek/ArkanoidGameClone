#pragma once
#include "SFML/Graphics.hpp"

inline sf::Vector2f MultipyVectors(sf::Vector2f vectorA, sf::Vector2f vectorB)
{
	return  sf::Vector2f(vectorA.x * vectorB.x, vectorA.y * vectorB.y);
}