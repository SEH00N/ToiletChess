#include "pch.h"
#include "Button.h"
#include "ResMgr.h"
#include "KeyMgr.h"

Button::Button(Vec2 pos, Vec2 scale, wstring defaultTexName, wstring focusedTexName)
	: Interface(pos, scale), defaultTex{ nullptr }, focusedTex{ nullptr }, OnClickedEvent{Action<Vec2>()}, pressed{false}
{
	defaultTex = ResMgr::GetInst()->TexLoad(defaultTexName, L"Texture\\" + defaultTexName + L".bmp");
	focusedTex = ResMgr::GetInst()->TexLoad(focusedTexName, L"Texture\\" + focusedTexName + L".bmp");

	texture = defaultTex;
}

Button::~Button()
{
}

void Button::Update()
{
	Interface::Update();

	if (onFocused && KEY_DOWN(KEY_TYPE::LBUTTON))
		pressed = true;

	if (pressed && KEY_UP(KEY_TYPE::LBUTTON))
	{
		if (onFocused)
			OnClickedEvent.Invoke(KeyMgr::GetInst()->GetMousePos());

		pressed = false;
	}
}

void Button::OnMouseEnter()
{
	texture = focusedTex;
}

void Button::OnMouseExit()
{
	texture = defaultTex;
}
