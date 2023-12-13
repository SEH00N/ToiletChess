#include "pch.h"
#include "TextBox.h"

TextBox::TextBox(Vec2 pos, Vec2 scale, wstring text) : text{ text }, renderable{true}
{
	SetPos(pos);
	SetScale(scale);
}

TextBox::~TextBox()
{
}

void TextBox::Render(HDC hDC)
{
	if (renderable == false)
		return;

	//SetBkMode(hDC, TRANSPARENT);

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	//RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	RECT rt = { pos.x, pos.y, pos.x + scale.x, pos.y + scale.y };

	DrawText(hDC, text.c_str(), -1, &rt, DT_LEFT);
	//TextOut(hDC, pos.x, pos.y, text.c_str(), text.length());
}
