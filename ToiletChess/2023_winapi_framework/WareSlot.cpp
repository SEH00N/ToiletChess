#include "pch.h"
#include "WareSlot.h"
#include "ResMgr.h"

WareSlot::WareSlot(Vec2 pos, Vec2 scale, wstring textureName) : Interface(pos, scale)
{
	texture = ResMgr::GetInst()->TexLoad(textureName, L"Texture\\" + textureName + L".bmp");
}

WareSlot::~WareSlot()
{
}
