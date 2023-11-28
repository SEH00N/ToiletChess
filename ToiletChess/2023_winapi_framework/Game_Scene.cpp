#include "pch.h"
#include "Game_Scene.h"
#include "Button.h"
#include "WareBase.h"
#include "WareSlot.h"

void Game_Scene::Init()
{
	WareBase* ware = new WareBase({ 640, 625 }, { 50, 100 }, L"Test", L"planem", L"plane");
	AddObject(ware, OBJECT_GROUP::DEFAULT);

	for (int i = 0; i < 6; ++i)
	{
		WareSlot* slot = new WareSlot({ 202.0f + i * 175, 575.0f }, {125, 125}, L"Slot");
		AddObject(slot, OBJECT_GROUP::DEFAULT);
	}
}
