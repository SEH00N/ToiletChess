#include "pch.h"
#include "TextBox.h"

TextBox::TextBox(Vec2 pos, Vec2 scale, wstring text) : text{ text }, renderable{true}
{
	SetPos(pos);
	SetScale(scale);
}

TextBox::~TextBox()
{
	if (font)
		DeleteObject(font);
}

void TextBox::Render(HDC hDC)
{
	if (renderable == false)
		return;

	if(transparent)
		SetBkMode(hDC, TRANSPARENT);
	else
		SetBkMode(hDC, OPAQUE);

	HFONT oldFont = 0;
	if(font)
		oldFont = (HFONT)SelectObject(hDC, font);

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	//RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	RECT rt = { pos.x, pos.y, pos.x + scale.x, pos.y + scale.y };

	DrawText(hDC, text.c_str(), -1, &rt, format);

	if(oldFont)
		SelectObject(hDC, oldFont);
	//TextOut(hDC, pos.x, pos.y, text.c_str(), text.length());
}
