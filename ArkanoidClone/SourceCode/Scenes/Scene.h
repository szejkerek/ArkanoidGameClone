#pragma once
#include "SFML/Graphics.hpp"
class Program;

class Scene : public sf::Drawable
{
public:
	Program* program;

	Scene(Program* _program) :program(_program) {}

	virtual void Update(float& dt) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

