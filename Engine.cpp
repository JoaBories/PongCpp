#include "Engine.h"

using MathUtils::RandInt;

Engine::~Engine()
{
	for (auto& actorList : GameActor::mActorLogicList)
	{
		for (auto& actor : actorList.second)
		{
			delete actor;
		}
	}

	GameActor::mActorLogicList.clear();
	GameActor::mActorRenderList.clear();
	GameActor::mActorTagMap.clear();

	delete mCamera;
	delete mAssetBank;
	delete mSceneManager;
}

void Engine::Init()
{
	GlobalVariables::ScreenMiddle = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	
	mAssetBank = AssetBank::GetInstance();
	mCamera = Cam2D::GetInstance();
	mSceneManager = SceneManager::GetInstance();

	mAssetBank->Init();
	mCamera->SetPosition(GlobalVariables::ScreenMiddle);

	InitActors(); // for actors created before (if there is)

	GlobalVariables::EngineRunning = true;

	mSceneManager->ChangeScene(Start);
}

void Engine::InitActors()
{
	if (GameActor::mActorLogicList.empty())
	{
		return;
	}

	for (auto& actorList : GameActor::mActorLogicList)
	{
		for (auto& actor : actorList.second)
		{
			actor->Init();
		}
	}
}

void Engine::Update()
{
	mCamera->Update();
	mSceneManager->Update();

	UpdateActors();

	GameActor::KillPendingActors();
}

void Engine::UpdateActors()
{
	if (GameActor::mActorLogicList.empty()) 
	{
		return;
	}

	for (auto& actorList : GameActor::mActorLogicList) 
	{
		for (auto& actor : actorList.second)
		{
			actor->Update();
		}
	}
}

void Engine::Draw()
{
	DrawActors();

	mSceneManager->DrawUI();

	if (GlobalVariables::ShowFPS)
	{
		DrawFPS(100, 100);
	}
}

void Engine::DrawActors()
{
	if (GameActor::mActorRenderList.empty())
	{
		return;
	}

	for (auto& actorList : GameActor::mActorRenderList)
	{
		for (auto& actor : actorList.second)
		{
			actor->Draw();
		}
	}
}
