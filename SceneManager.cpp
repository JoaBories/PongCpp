#include "SceneManager.h"

SceneManager* SceneManager::mpInstance = nullptr;

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
	switch (mCurrentScene)
	{
	case Start:
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

	mCurrentScene = newScene;

	switch (newScene)
	{
	case Start:
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
