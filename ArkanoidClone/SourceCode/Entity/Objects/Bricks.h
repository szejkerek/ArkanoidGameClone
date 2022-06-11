#pragma once
#include "Entity.h"
#include "../ArkanoidClone/SourceCode/Utility/Utility.h"

class IBrick : public EntityRectangle
{
protected:
	int points;
	bool destructible;

public:

	//Constructors & Destructors
	IBrick(bool destructible, GameScene* gameScene);
	~IBrick() {}

	sf::Vector2f GetCenterPoint();
	virtual inline void SetRelativePosition(int row, int collumn);
	//Getters&Setters
	virtual bool OnCollisionEnter() = 0;  //Returns true when brick is to be destroyed
	virtual void SetPoints(const int& points);
	virtual int GetPoints();
	virtual int GetHp();
	inline virtual bool IsDestructible();
	virtual void Update(float& dt) {};

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class GoldBrick : public IBrick
{
private:
	sf::Texture* goldTexture;
	sf::IntRect textureRect;

	float timer = 0.02f;
	float defaultTimer = 0.02f;
	bool doAnimate = false;
public:
	GoldBrick();
	void Animate();
	void PickNextTexture();
	bool OnCollisionEnter(); //Can never be destroyed
	void Update(float& dt);
};

class SilverBrick : public IBrick
{
private:
	int hp;
	int maxHp;
	sf::IntRect textureRect;
public:
	SilverBrick(int stageNumber);
	int GetHp() { return hp; }
	void PickBrokenTexutre();
	void ApplyTexture(int textureIndex);
	bool OnCollisionEnter();

};

class ColorBrick : public IBrick
{
public:
	ColorBrick(ColorsEnum color);
	bool OnCollisionEnter();
};

class BossBrick : public IBrick
{
private:
	int hp;
public:
	BossBrick();
	int GetHp() { return hp; }
	bool OnCollisionEnter();
};