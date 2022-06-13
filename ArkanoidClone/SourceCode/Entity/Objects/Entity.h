#pragma once
#include "SFML/Graphics.hpp"

class GameScene;

class EntityRectangle :public sf::Drawable
{
public:
	GameScene* gameScene;

	EntityRectangle(GameScene* gameScene, const sf::Vector2f& size);
	virtual ~EntityRectangle() = default;

	virtual inline void InitGameObject();
	virtual inline void SetTexture(sf::Texture* texture);
	virtual inline void SetPosition(const sf::Vector2f& position);
	virtual inline void SetSize(const sf::Vector2f& size);
	virtual inline void SetFillColor(const sf::Color& color);
	virtual inline void SetOriginCenter();
	virtual inline void SetOutlineThickness(const float& size);
	virtual inline void SetOutlineColor(const sf::Color& color);
	virtual inline sf::FloatRect GetCollider();
	virtual inline sf::Vector2f GetSize();
	virtual inline sf::Vector2f GetPosition();
	virtual void Update(float& dt) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

protected:
	sf::RectangleShape gameObject;
};

class EntityCircle :public sf::Drawable
{
public:

	GameScene* gameScene;
	EntityCircle(GameScene* _gameScene, const float& radius);
	virtual ~EntityCircle() = default;
	virtual void InitGameObject();
	virtual inline void SetTexture(sf::Texture* texture) {};
	virtual inline void SetPosition(const sf::Vector2f& position);
	virtual inline void SetRadius(const float& radius);
	virtual inline void SetOutlineColor(const sf::Color& color);
	virtual inline void SetFillColor(const sf::Color& color);
	virtual inline void SetOriginCenter();
	virtual inline void SetOutlineThickness(const float& size);
	virtual inline float GetRadius();
	virtual inline sf::Vector2f GetPosition();
	virtual inline sf::FloatRect GetCollider();
	virtual void Update(float& dt) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

protected:
	sf::CircleShape gameObject;
};