#pragma once
#include "Entity.h"
#include "../Utility/Utility.h"


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
public:
	SilverBrick(int stageNumber);
	bool OnCollisionEnter();

};

class ColorBrick : public IBrick
{
public:
	ColorBrick(ColorsEnum color);
	bool OnCollisionEnter();

};