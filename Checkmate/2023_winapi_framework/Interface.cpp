#include "pch.h"
#include "Interface.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Texture.h"

Interface::Interface(Vec2 pos, Vec2 scale) : texture{ nullptr }, onFocused{ false }, renderable{ true }
{
	SetPos(pos);
	SetScale(scale);
}

Interface::~Interface()
{
}

void Interface::Update()
{
	POINT mousePos = KeyMgr::GetInst()->GetMousePos();
	Vec2 pos = GetPos();
	Vec2 scale = GetScale();

	if (pos.x - scale.x / 2 < mousePos.x && mousePos.x < pos.x + scale.x / 2
		&& pos.y - scale.y / 2 < mousePos.y && mousePos.y < pos.y + scale.y / 2)
	{
		if (onFocused == false)
		{
			onFocused = true;
			OnMouseEnter();
		}
		else
			OnMouse();
	}
	else
	{
		if (onFocused)
		{
			OnMouseExit();
			onFocused = false;
		}
	}
}

void Interface::Render(HDC hDC)
{
	if (renderable == false)
		return;

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();

	int width = texture->GetWidth();
	int height = texture->GetHeight();

	//StretchBlt(hDC
	//	, (int)(pos.x - scale.x / 2)
	//	, (int)(pos.y - scale.y / 2)
	//	, scale.x, scale.y, texture->GetDC()
	//	, 0, 0, width, height,
	//	SRCCOPY);

	TransparentBlt(hDC
		, (int)(pos.x - scale.x / 2)
		, (int)(pos.y - scale.y / 2)
		, scale.x, scale.y, texture->GetDC()
		, 0, 0, width, height,
		RGB(255, 0, 255));

	Component_Render(hDC);
}

void Interface::SetTexture(wstring texName)
{
	texture = ResMgr::GetInst()->TexLoad(texName, L"Texture\\" + texName + L".bmp");
}

void Interface::OnMouseEnter()
{
}

void Interface::OnMouse()
{
}

void Interface::OnMouseExit()
{
}
