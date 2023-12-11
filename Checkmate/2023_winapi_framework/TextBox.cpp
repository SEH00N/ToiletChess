#include "pch.h"
#include "TextBox.h"

TextBox::TextBox(Vec2 pos, Vec2 scale, wstring text) : text{text}
{
	SetPos(pos);
	SetScale(scale);
}

TextBox::~TextBox()
{
}

void TextBox::Render(HDC hDC)
{
	SetBkMode(hDC, TRANSPARENT);
	Vec2 pos = GetPos();
	TextOut(hDC, pos.x, pos.y, text.c_str(), text.length());
}
