#include "pch.h"
#include "Game_Scene.h"
#include "Core.h"
#include "Interface.h"

void Game_Scene::Init()
{
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
