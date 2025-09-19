#include "PaddleBot.h"

using MathUtils::Abs;

PaddleBot::PaddleBot(Vect2F position, Vect2F halfSize, Color color):
	Paddle{ position, halfSize, KEY_A, KEY_A, color}
{
}

void PaddleBot::Update()
{
	vector<GameActor*> actors = GameActor::GetActorsByTag(TagBall);

	float yTarget = 0;

	if (!actors.empty())
	{
		yTarget = actors[0]->GetTransform().position.y;
	}

	float diff = mTransform.position.y - yTarget;

	if ( Abs(diff) > mBoundingBox.halfSize.y / 2 )
	{
		if (diff > 0)
		{
			MoveUp();
		}
		else
		{
			MoveDown();
		}
	}

}
