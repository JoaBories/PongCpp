#include "Ball.h"

Ball::Ball(Vect2F startPos, Vect2F startVel, float radius, Color color):
	GameActor(0,1, {startPos, Vect2F::one, 0}, TagBall),
	mVelocity{ startVel },
	mRadius{ radius },
	mColor{ color }
{
	if (GlobalVariables::EngineRunning)
	{
		Init();
	}
}

void Ball::Init()
{
}

void Ball::Update()
{
	if (mTransform.position.y - mRadius <= 0)
	{
		mVelocity *= {1, -1};
		mTransform.position.y = mRadius;
	}
	else if (mTransform.position.y + mRadius > GetScreenHeight())
	{
		mVelocity *= {1, -1};
		mTransform.position.y = GetScreenHeight() - mRadius;
	}

	if (mTransform.position.x - mRadius <= 0)
	{
		GlobalVariables::RightScore++;
		Reset({ -1, -1 });
	}
	else if (mTransform.position.x + mRadius > GetScreenWidth())
	{
		GlobalVariables::LeftScore++;
		Reset({ 1, 1 });
	}

	vector<GameActor*> actors = GameActor::GetActorsByTag(TagPaddle);
	vector<Paddle*> paddles = {};

	for (GameActor* actor : actors) 
	{
		Paddle* paddle = nullptr;

		if (paddle = dynamic_cast<Paddle*>(actor))
		{
			paddles.push_back(paddle);
		}
	}

	if (!paddles.empty())
	{
		Rect2 ballBoundingBox = { mTransform.position, {mRadius, mRadius} };

		for (Paddle* paddle : paddles)
		{
			Rect2 paddleBoundingBox = paddle->GetBoundingBox().toObjectSpace(paddle->GetTransform());

			Collision coll = ballBoundingBox.CheckAABB(paddleBoundingBox);

			if (coll)
			{
				mTransform.position += coll.getForce();

				if (coll.axis.x == 0)
				{
					mVelocity *= {1, -1};
				}
				else
				{
					mVelocity *= {-1, 1};
				}

				mVelocity += mVelocity.normalized() * 20;
			}
		}
	}

	mTransform.position += mVelocity * GetFrameTime();

}

void Ball::Draw()
{
	DrawCircleV(mTransform.position.toRaylib(), mRadius, mColor);
}

void Ball::Reset(Vect2F way)
{
	mTransform.position = GlobalVariables::ScreenMiddle;

	mVelocity = GlobalVariables::BallStartVel * way;
}
