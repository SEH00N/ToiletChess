#include "pch.h"
#include "WareSlot.h"
#include "WareImage.h"
#include "GameMgr.h"
#include "Texture.h"

WareSlot::WareSlot(Vec2 pos, Vec2 scale, wstring texName) : Interface(pos, scale), wareTex{nullptr}
{
	SetTexture(texName);
}

void WareSlot::Render(HDC hDC)
{
	Interface::Render(hDC);

	if (wareTex == nullptr)
		return;

	Vec2 pos = GetPos();
	Vec2 scale = { 100, 100 };

	int width = wareTex->GetWidth();
	int height = wareTex->GetHeight();

	//StretchBlt(hDC
	//	, (int)(pos.x - scale.x / 2)
	//	, (int)(pos.y - scale.y / 2)
	//	, scale.x, scale.y, texture->GetDC()
	//	, 0, 0, width, height,
	//	SRCCOPY);

	TransparentBlt(hDC
		, (int)(pos.x - scale.x / 2)
		, (int)(pos.y - scale.y / 2)
		, scale.x, scale.y, wareTex->GetDC()
		, 0, 0, width, height,
		RGB(255, 0, 255));
}

void WareSlot::OnMouseEnter()
{
	GameMgr::GetInst()->SetCurrentSlot(this);

	WareImage* ware = GameMgr::GetInst()->GetCurrentWare();
	if (ware == nullptr)
		return;


}

void WareSlot::OnMouseExit()
{
	if(GameMgr::GetInst()->GetCurrentSlot() == this)
		GameMgr::GetInst()->SetCurrentSlot(nullptr);
}

void WareSlot::SetWare(WareImage* ware)
{
	wareTex = ware->GetTexture();
}
