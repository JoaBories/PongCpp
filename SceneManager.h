#pragma once

#include "GameActor.h"

enum Scenes
{
	Start,
	Pvp,
	Pve,
	MatchEnd
};


class SceneManager
{
private:
	Scenes mCurrentScene;
	static SceneManager* mpInstance;

public:
	SceneManager() = default;
	~SceneManager() = default;

	static SceneManager* GetInstance();

	void ChangeScene(Scenes newScene);
	inline Scenes GetCurrentScene() const { return mCurrentScene; };
};

