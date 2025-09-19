#include "Paddle.h"

void Paddle::MoveUp()
{
	if (mTransform.position.y - mBoundingBox.halfSize.y > 0)
	{
		mTransform.position.y -= GlobalVariables::PaddleMoveSpeed * GetFrameTime();
	}
}

void Paddle::MoveDown()
{
	if (mTransform.position.y + mBoundingBox.halfSize.y < GetScreenHeight())
	{
		mTransform.position.y += GlobalVariables::PaddleMoveSpeed * GetFrameTime();
	}
}

Paddle::Paddle(Vect2F position, Vect2F halfSize, KeyboardKey upKey, KeyboardKey downKey, Color color) :
	GameActor(0, 1, { position, Vect2F::one, 0 }, Tag::TagPaddle),
	mBoundingBox{ Vect2F::zero, halfSize },
	mUpKey{ upKey },
	mDownKey{ downKey },
	mColor{ color }
{
	if (GlobalVariables::EngineRunning)
	{
		Init();
	}
}

void Paddle::Init()
{
}

void Paddle::Update()
{

	if (IsKeyDown(mUpKey))
	{
		MoveUp();
	}
	else if (IsKeyDown(mDownKey))
	{
		MoveDown();
	}

}

void Paddle::Draw()
{
	DrawRectangleRec(mBoundingBox.toObjectSpace(mTransform).toRaylib(), mColor);
}
