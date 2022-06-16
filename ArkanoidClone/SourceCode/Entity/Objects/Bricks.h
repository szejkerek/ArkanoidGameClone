#pragma once
#include "Entity.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"
#include "SFML/Audio.hpp"

class IBrick : public EntityRectangle
{
public:
	IBrick(bool destructible, GameScene* gameScene);
	~IBrick() {}

	sf::Vector2f GetCenterPoint();
	virtual inline void SetRelativePosition(int row, int collumn);
	virtual bool OnCollisionEnter() = 0;
	virtual void SetPoints(const int& points);
	virtual int GetPoints();
	virtual int GetHp();
	inline virtual bool IsDestructible();
	virtual void Update(float& dt) {};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	int points;
	bool destructible;
};

class GoldBrick : public IBrick
{
public:
	GoldBrick();

	void Animate();
	void PickNextTexture();
	bool OnCollisionEnter(); //Can never be destroyed
	void Update(float& dt);

private:
	sf::Texture* goldTexture;
	sf::IntRect textureRect;
	float timer = 0.02f;
	float defaultTimer = 0.02f;
	bool doAnimate = false;
};

class SilverBrick : public IBrick
{
public:
	SilverBrick(int stageNumber);

	int GetHp() { return hp; }
	void PickBrokenTexutre();
	void ApplyTexture(int textureIndex);
	bool OnCollisionEnter();
private:
	int hp;
	int maxHp;
	sf::IntRect textureRect;
};

class ColorBrick : public IBrick
{
public:
	ColorBrick(ColorsEnum color);

	bool OnCollisionEnter();
};

class BossBrick : public IBrick
{
public:
	BossBrick();

	int GetHp() { return hp; }
	bool OnCollisionEnter();
private:
	int hp;
};