#pragma once

#include "GameActor.h"
#include "Button.h"

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

	Button* mButton1;
	Button* mButton2;

	void testFunc();


public:
	SceneManager() = default;
	~SceneManager() = default;

	static SceneManager* GetInstance();

	void ChangeScene(Scenes newScene);
	inline Scenes GetCurrentScene() const { return mCurrentScene; };
	void Update();
	void DrawUI() const;
};

