#pragma once
#include "Utils.h"
using Struct::Rect2;

#include <string>
using std::string;

class Button
{
private :
	Rect2 mSpace;

	string mtext;

	Color mBackColor;
	Color mHoverColor;
	Color mTextColor;

	bool mIsHovered;

public :
	Button() = default;
	~Button() = default;

	Button(Rect2 space, string text, Color backColor, Color hoverColor, Color textColor);

	bool isClicked();
	void Draw() const;
};

