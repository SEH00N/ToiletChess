#include "pch.h"
#include "Button.h"
#include "ResMgr.h"
#include "KeyMgr.h"

Button::Button(Vec2 pos, Vec2 scale, wstring buttonName, wstring defaultTexName, wstring eventTexName)
	: Interface(pos, scale), defaultTex{ nullptr }, eventTex{nullptr}, OnButtonPressed {nullptr}
{
	defaultTex = ResMgr::GetInst()->TexLoad(buttonName + defaultTexName, L"Texture\\" + defaultTexName + L".bmp");
	eventTex = ResMgr::GetInst()->TexLoad(buttonName + eventTexName, L"Texture\\" + eventTexName + L".bmp");

	texture = defaultTex;
}

Button::~Button()
{
}

void Button::Update()
{
	Interface::Update();

	if(KEY_DOWN(KEY_TYPE::LBUTTON))
		if(OnButtonPressed)
			OnButtonPressed();
}

void Button::OnMouseEnter()
{
	texture = eventTex;
}

void Button::OnMouse()
{
}

void Button::OnMouseExit()
{
	texture = defaultTex;
}
