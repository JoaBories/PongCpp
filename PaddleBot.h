#pragma once
#include "Paddle.h"
class PaddleBot : public Paddle
{
private:

public:

	PaddleBot() = default;
	~PaddleBot() = default;

	PaddleBot(Vect2F position, Vect2F halfSize, Color color);

	void Update() override;

};

