#pragma once

#include "Button.h"
#include "Ball.h"
#include "PaddleBot.h"
#include "Image.h"

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

	void InitButtons();
	void InitPvp();
	void InitPve();
	void DrawScore() const;


public:
	SceneManager() = default;
	~SceneManager() = default;

	static SceneManager* GetInstance();

	void ChangeScene(Scenes newScene);
	inline Scenes GetCurrentScene() const { return mCurrentScene; };
	void Update();
	void DrawUI() const;
};

