#include "pch.h"
#include "WareSlot.h"
#include "WareImage.h"
#include "GameMgr.h"

WareSlot::WareSlot(Vec2 pos, Vec2 scale, wstring texName) : Interface(pos, scale)
{
	SetTexture(texName);
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
