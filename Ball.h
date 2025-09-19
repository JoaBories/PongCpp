#pragma once
#include "GameActor.h"
#include "Paddle.h"
using Struct::Rect2;


class Ball : public GameActor
{

private :
	Vect2F mVelocity;
	float mRadius;
	Color mColor;

public :

	Ball() = default;
	~Ball() = default;

	Ball(Vect2F startPos, Vect2F startVel, float radius, Color color);

	// Inherited via GameActor
	void Init() override;
	void Update() override;
	void Draw() override;

	void Reset(Vect2F way);
};

