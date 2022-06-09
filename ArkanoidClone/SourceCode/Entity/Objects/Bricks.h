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

	//SFML Methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class GoldBrick : public IBrick
{
public:
	GoldBrick();
	bool OnCollisionEnter(); //Can never be destroyed

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