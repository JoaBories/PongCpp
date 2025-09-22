#include "SceneManager.h"

using RaylibUtils::DrawTextCentered;
using std::to_string;

SceneManager* SceneManager::mpInstance = nullptr;

void SceneManager::InitButtons()
{
	float buttonY = (float)GetScreenHeight() / 3 * 2;
	Rect2 buttonRect;

	buttonRect = Rect2(Vect2F{ (float)GetScreenWidth() / 5 * 2, buttonY }, Vect2F{ 75, 40 });
	mButton1 = new Button(buttonRect, "PVP", DARKGREEN, GREEN, RAYWHITE);
	buttonRect = Rect2(Vect2F{ (float)GetScreenWidth() / 5 * 3, buttonY }, Vect2F{ 75, 40 });
	mButton2 = new Button(buttonRect, "PVE", DARKGREEN, GREEN, RAYWHITE);
}

void SceneManager::InitPvp()
{
	new ImageActor(GlobalVariables::ScreenMiddle, { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, "core");
	new ImageActor(GlobalVariables::ScreenMiddle, { 20, (float)GetScreenHeight() / 2 }, "net");
	GlobalVariables::LeftScore = 0, GlobalVariables::RightScore = 0;
	new Ball(GlobalVariables::ScreenMiddle, GlobalVariables::BallStartVel, 15, RAYWHITE);
	new Paddle({ (float)GetScreenWidth() / 10, (float)GetScreenHeight() / 2 }, { 20.0f, 100.0f }, KEY_W, KEY_S, RED);
	new Paddle({ (float)GetScreenWidth() / 10 * 9, (float)GetScreenHeight() / 2 }, { 20.0f, 100.0f }, KEY_UP, KEY_DOWN, BLUE);
}

void SceneManager::InitPve()
{
	new ImageActor(GlobalVariables::ScreenMiddle, { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, "core");
	new ImageActor(GlobalVariables::ScreenMiddle, { 20, (float)GetScreenHeight() / 2 }, "net");
	GlobalVariables::LeftScore = 0, GlobalVariables::RightScore = 0;
	new Ball(GlobalVariables::ScreenMiddle, GlobalVariables::BallStartVel, 15, RAYWHITE);
	new Paddle({ (float)GetScreenWidth() / 10, (float)GetScreenHeight() / 2 }, { 20.0f, 100.0f }, KEY_UP, KEY_DOWN, RED);
	new PaddleBot({ (float)GetScreenWidth() / 10 * 9, (float)GetScreenHeight() / 2 }, { 20.0f, 100.0f }, BLUE);

}

void SceneManager::DrawScore() const
{
	string score;
	score = to_string(GlobalVariables::LeftScore);
	DrawTextCentered(score, { (float)GetScreenWidth() / 10 * 4, 60 }, 50, RED);
	score = to_string(GlobalVariables::RightScore);
	DrawTextCentered(score, { (float)GetScreenWidth() / 10 * 6, 60 }, 50, BLUE);
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

	if (mButton1 != nullptr)
	{
		delete mButton1;
		mButton1 = nullptr;
	}

	if (mButton2 != nullptr)
	{
		delete mButton2;
		mButton2 = nullptr;
	}

	mCurrentScene = newScene;

	switch (newScene)
	{
	case Start:
		InitButtons();
		new ImageActor(GlobalVariables::ScreenMiddle, { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, "summit_begin");

		break;

	case Pvp:
		InitPvp();

		break;

	case Pve:
		InitPve();

		break;

	case MatchEnd:
		new ImageActor(GlobalVariables::ScreenMiddle, { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, "summit_end");
		InitButtons();

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
		if (IsKeyPressed(KEY_F))
		{
			ChangeScene(MatchEnd); //debug
		}

		if (GlobalVariables::LeftScore >= GlobalVariables::WinScore || GlobalVariables::RightScore >= GlobalVariables::WinScore)
		{
			ChangeScene(MatchEnd);
		}

		break;
	case Pve:
		if (IsKeyPressed(KEY_F))
		{
			ChangeScene(MatchEnd); //debug
		}

		if (GlobalVariables::LeftScore >= GlobalVariables::WinScore || GlobalVariables::RightScore >= GlobalVariables::WinScore)
		{
			ChangeScene(MatchEnd);
		}

		break;
	case MatchEnd:

		if (mButton1->isClicked())
		{
			ChangeScene(Pvp);
		}
		else if (mButton2->isClicked())
		{
			ChangeScene(Pve);
		}

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

		DrawScore();
		
		break;
	case Pve:

		DrawScore();

		break;
	case MatchEnd:

		mButton1->Draw();
		mButton2->Draw();

		break;
	default:
		break;
	}
}
