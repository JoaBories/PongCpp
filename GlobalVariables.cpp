#include "GlobalVariables.h"

bool GlobalVariables::EngineRunning = false;
bool GlobalVariables::TextureCulling = false;
float GlobalVariables::CullingSizeMultiplier = 1;
bool GlobalVariables::ShowFPS = false;
float GlobalVariables::PaddleMoveSpeed = 800;
Vect2F GlobalVariables::BallStartVel = { -500.0f, -500.0f };
Vect2F GlobalVariables::ScreenMiddle = Vect2F::zero;
int GlobalVariables::LeftScore = 0;
int GlobalVariables::RightScore = 0;
int GlobalVariables::WinScore = 4;