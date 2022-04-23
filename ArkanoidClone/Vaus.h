#pragma once
#include "SFML/Graphics.hpp"
#include "VausPart.h"
#include <vector>
class Vaus: public sf::Drawable
{
	//GameObjects
	std::vector<IVausPart*> parts;    //Central,grey R, grey L, red R, red L, blue R, blue L 

	//Variables
	sf::Vector2f direction;
	sf::Vector2f position;
	float speed = 110.f;
	void Move(float& dt);
	void SetPosition(const sf::Vector2f& position);
	void InitParts();

public:
	Vaus();
	~Vaus();

	//SFML methods
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float& dt);
};

