#include "SceneManager.h"

SceneManager* SceneManager::mpInstance = nullptr;

void SceneManager::testFunc()
{
	float buttonY = (float)GetScreenHeight() / 3 * 2;
	Rect2 buttonRect;

	buttonRect = Rect2(Vect2F{ (float)GetScreenWidth() / 5 * 2, buttonY }, Vect2F{ 75, 40 });
	mButton1 = new Button(buttonRect, "PVP", GREEN, DARKGREEN, RAYWHITE);
	buttonRect = Rect2(Vect2F{ (float)GetScreenWidth() / 5 * 3, buttonY }, Vect2F{ 75, 40 });
	mButton2 = new Button(buttonRect, "PVE", GREEN, DARKGREEN, RAYWHITE);
}

SceneManager* SceneManager::GetInstance()
{
	if (!mpInstance)
	{
		mpInstance = new SceneManager();
	}

	return mpInstance;
}

void SceneManager::ChangeScene(Scenes newScene)
{
	GameActor::Killa();
	delete mButton1;
	delete mButton2;

	mCurrentScene = newScene;

	switch (newScene)
	{
	case Start:
		
		testFunc();

		break;
	case Pvp:
		break;
	case Pve:
		break;
	case MatchEnd:
		break;
	default:
		break;
	}
}

void SceneManager::Update()
{
	switch (mCurrentScene)
	{
	case Start:

		if (mButton1->isClicked())
		{
			ChangeScene(Pvp);
		}
		else if (mButton2->isClicked())
		{
			ChangeScene(Pve);
		}

		break;
	case Pvp:
		break;
	case Pve:
		break;
	case MatchEnd:
		break;
	default:
		break;
	}
}


void SceneManager::DrawUI() const
{
	switch (mCurrentScene)
	{
	case Start:

		mButton1->Draw();
		mButton2->Draw();

		break;
	case Pvp:
		break;
	case Pve:
		break;
	case MatchEnd:
		break;
	default:
		break;
	}
}
