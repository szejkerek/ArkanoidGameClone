#pragma once
#include "SFML/Graphics.hpp"
#include "VausPart.h"
#include <vector>
class Vaus :public sf::Drawable
{
public:
	std::vector<IVausPart*> parts;

	Vaus();
	~Vaus();

	//SFML methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);

private:
	sf::Vector2f direction;
	sf::Vector2f position;
	float speed = 110.f;
	float lightsAnimTimer = 2.f;
	float lightsAnimDefaultTimer = 2.f;

	void Move(float& dt);
	void SetPosition(const sf::Vector2f& position);
	void InitParts();


};

