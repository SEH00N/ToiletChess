#include "pch.h"
#include "BG.h"
#include "Texture.h"
#include "ResMgr.h"
#include "Core.h"


BG::BG(wstring bgKey, wstring bgName) : texture{nullptr}
{
	texture = ResMgr::GetInst()->TexLoad(bgKey, L"Texture\\" + bgName + L".bmp");
}

BG::~BG()
{
}

void BG::Update()
{
}

void BG::Render(HDC hDC)
{
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
		, 0, 0, width, height, RGB(255, 0, 255));

	Component_Render(hDC);
}
