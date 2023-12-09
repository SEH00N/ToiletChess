#include "pch.h"
#include "WareInventorySlot.h"
#include "ResMgr.h"

WareInventorySlot::WareInventorySlot(Vec2 pos, Vec2 scale, wstring texName) : Interface(pos, scale), ware{nullptr}
{
	SetTexture(texName);
}