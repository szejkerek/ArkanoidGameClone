#pragma once
#include "SFML/Graphics.hpp"

class Program;

class Scene : public sf::Drawable
{
protected:
	Program* program;
public:
	Scene(Program* _program) :program(_program) {}
	~Scene() = default;

	//SFML
	virtual void Update(float& dt) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

