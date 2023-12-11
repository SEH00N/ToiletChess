#include "pch.h"
#include "Game_Scene.h"
#include "Core.h"
#include "Interface.h"
#include "Inventory.h"

void Game_Scene::Init()
{
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
