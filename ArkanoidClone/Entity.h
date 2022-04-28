#pragma once
#include "SFML/Graphics.hpp"

class EntityRectangle :public sf::Drawable
{
protected:
	//Gameobject
	sf::RectangleShape gameObject;
public:
	//Constructors&Destructors
	EntityRectangle(const sf::Vector2f& size);
	virtual ~EntityRectangle() = default;
	
	//Methods
	virtual inline void InitGameObject();

	///Getters&Setters
	virtual inline void SetTexture(sf::Texture* texture) {};
	virtual inline void SetPosition(const sf::Vector2f& position);
	virtual inline void SetSize(const sf::Vector2f& size);
	virtual inline void SetFillColor(const sf::Color& color);
	virtual inline void SetOriginCenter();
	virtual inline void SetOutlineThickness(const float& size);
	virtual inline void SetOutlineColor(const sf::Color& color);
	virtual inline sf::FloatRect GetCollider();
	virtual inline sf::Vector2f GetSize();
	virtual inline sf::Vector2f GetPosition();

	//SFML methods
	virtual void Update(float& dt) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

class EntityCircle :public sf::Drawable
{
protected:
	//Gameobject
	sf::CircleShape gameObject;
public:
	//Constructors&Destructors
	EntityCircle(const float& radius);
	virtual ~EntityCircle() = default;

	//Methods
	virtual void InitGameObject();

	///Getters&Setters
	virtual inline void SetTexture(sf::Texture* texture) {};
	virtual inline void SetPosition(const sf::Vector2f& position);
	virtual inline void SetRadius(const float& radius);
	virtual inline void SetFillColor(const sf::Color& color);
	virtual inline void SetOriginCenter();
	virtual inline void SetOutlineThickness(const float& size);
	virtual inline void SetOutlineColor(const sf::Color& color);
	virtual inline float GetRadius();
	virtual inline sf::Vector2f GetPosition();
	virtual inline sf::FloatRect GetCollider();

	//SFML methods
	virtual void Update(float& dt) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};