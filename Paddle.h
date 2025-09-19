#pragma once
#include "GameActor.h"

using Struct::Rect2;
using Struct::Collision;


class Paddle : public GameActor
{

private:

	Rect2 mBoundingBox;
	KeyboardKey mUpKey;
	KeyboardKey mDownKey;
	Color mColor;

protected:
	void MoveUp();
	void MoveDown();

public:

	Paddle() = default;
	~Paddle() = default;

	Paddle(Vect2F position, Vect2F halfSize, KeyboardKey upKey, KeyboardKey downKey, Color color);

	// Inherited via GameActor
	void Init() override;
	void Update() override;
	void Draw() override;

	inline Rect2 GetBoundingBox() const { return mBoundingBox; };
};

