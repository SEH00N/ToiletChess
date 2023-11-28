#include "pch.h"
#include "Button.h"
#include "ResMgr.h"
#include "KeyMgr.h"

Button::Button(Vec2 pos, Vec2 scale, wstring buttonName, wstring defaultTexName, wstring eventTexName)
	: Interface(pos, scale), defaultTex{ nullptr }, eventTex{ nullptr }, onButtonClicked{ nullptr }, onButtonReleased{nullptr}, clicked{ false }
{
	defaultTex = ResMgr::GetInst()->TexLoad(buttonName + defaultTexName, L"Texture\\" + defaultTexName + L".bmp");
	eventTex = ResMgr::GetInst()->TexLoad(buttonName + eventTexName, L"Texture\\" + eventTexName + L".bmp");

	texture = defaultTex;
}

Button::~Button()
{
	onButtonClicked = nullptr;
	onButtonReleased = nullptr;
}

void Button::Update()
{
	Interface::Update();

	if (onMouse && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		if(onButtonClicked)
			onButtonClicked();
		clicked = true;
	}

	if (clicked && KEY_UP(KEY_TYPE::LBUTTON))
	{
		if (onMouse)
		{
			if(onButtonReleased)
				onButtonReleased();
		}
		
		clicked = false;
	}
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
