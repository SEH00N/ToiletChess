#include "pch.h"
#include <functional>
#include "Button.h"
#include "ResMgr.h"
#include "KeyMgr.h"

Button::Button(Vec2 pos, Vec2 scale, wstring defaultTexName, wstring focusedTexName)
	: Interface(pos, scale), defaultTex{ nullptr }, focusedTex{ nullptr }, OnPressedEvent{ nullptr }, OnClickedEvent{nullptr}, pressed{false}
{
	defaultTex = ResMgr::GetInst()->TexLoad(defaultTexName, L"Texture\\" + defaultTexName + L".bmp");
	focusedTex = ResMgr::GetInst()->TexLoad(focusedTexName, L"Texture\\" + focusedTexName + L".bmp");

	SetTexture(defaultTex);
}

Button::~Button()
{
}

void Button::Update()
{
	Interface::Update();

	if (onFocused && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		if(OnPressedEvent)
			OnPressedEvent();
		pressed = true;
	}

	if (pressed && KEY_UP(KEY_TYPE::LBUTTON))
	{
		if (onFocused)
			if (OnClickedEvent)
				OnClickedEvent();

		pressed = false;
	}
}

void Button::OnMouseEnter()
{
	SetTexture(focusedTex);
}

void Button::OnMouseExit()
{
	SetTexture(defaultTex);
}
