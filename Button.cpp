#include "Button.h"

using RaylibUtils::DrawTextCentered;

Button::Button(Rect2 space, string text, Color backColor, Color hoverColor, Color textColor):
	mSpace{ space },
	mtext{ text },
	mBackColor{ backColor },
	mHoverColor{ hoverColor },
	mTextColor{ textColor },
	mIsHovered{ false }
{
}

bool Button::isClicked()
{
	mIsHovered = false;

	Vector2 mousePos = GetMousePosition();

	mIsHovered = mSpace.ContainPoint({ mousePos.x, mousePos.y });

	if (mIsHovered)
	{
		if (IsMouseButtonPressed(0)) 
		{
			return true;
		}
	}

	return false;
}

void Button::Draw() const
{
	DrawRectangleRec(mSpace.toRaylib(), (mIsHovered) ? mHoverColor : mBackColor);
	DrawTextCentered(mtext, mSpace.center, 20, mTextColor);
}
