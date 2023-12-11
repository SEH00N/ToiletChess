#include "pch.h"
#include "Game_Scene.h"
#include "Core.h"
#include "Interface.h"
#include "Inventory.h"
#include "WareSlot.h"

void Game_Scene::Init()
{
	WareSlot* slot = new WareSlot({ 100, 100 }, {100, 100}, L"Urinal");
	AddObject(slot);
	
	LoadBackground();
	InitInventory();
}

void Game_Scene::LoadBackground()
{
	Vec2 resolution = Core::GetInst()->GetResolution();
	Interface* bg = new Interface(
		{ resolution.x / 2, resolution.y / 2 },
		{ WINDOW_WIDTH, WINDOW_HEIGHT }
	);
	bg->SetTexture(L"BG");
	AddObject(bg, OBJECT_GROUP::DEFAULT);
}

void Game_Scene::InitInventory()
{
	inven1 = new Inventory();
	inven2 = new Inventory();

	inven1->Show();
	inven2->Hide();
}
