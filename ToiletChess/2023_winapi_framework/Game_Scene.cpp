#include "pch.h"
#include "Game_Scene.h"
#include "Button.h"
#include "WareBase.h"

void Game_Scene::Init()
{
	WareBase* ware = new WareBase({ 640, 625 }, { 50, 100 }, L"Test", L"planem", L"plane");
	AddObject(ware, OBJECT_GROUP::DEFAULT);
}
