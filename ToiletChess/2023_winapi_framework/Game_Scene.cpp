#include "pch.h"
#include "Game_Scene.h"
#include "Button.h"
#include "WareBase.h"
#include "WareSlot.h"
#include "Urinal.h"

void Game_Scene::Init()
{
	for (int i = -2; i <= 2; ++i)
	{
		WareSlot* slot = new WareSlot({ 640 + i * 175, 575 }, { 125, 125 }, L"Slot");
		AddObject(slot, OBJECT_GROUP::DEFAULT);
	}

	CreateUrinal({100, 335}, { 192, 192 }, 120, 10);

	CreateWare(inven1, { 100, 100 });
	CreateWare(inven2, { 100, 100 });

	SetInven(inven1);
}

void Game_Scene::CreateWare(std::vector<WareBase*>& inven, Vec2 scale)
{
	inven.resize(5);

	//inven[0] = new WareBase({ 0, 0 }, scale, L"Anchovy", L"Anchovy", L"AnchovyFocused");
	//inven[1] = new WareBase({ 0, 0 }, scale, L"Employee", L"Employee", L"EmployeeFocused");
	//inven[2] = new WareBase({ 0, 0 }, scale, L"Employee", L"Employee", L"EmployeeFocused");
	//inven[3] = new WareBase({ 0, 0 }, scale, L"Pig", L"Pig", L"PigFocused");
	//inven[4] = new WareBase({ 0, 0 }, scale, L"Athlete", L"Athlete", L"AthleteFocused");

	inven[0] = new WareBase({ 0, 0 }, scale, L"Anchovy", L"planem", L"plane");
	inven[1] = new WareBase({ 0, 0 }, scale, L"Employee", L"planem", L"plane");
	inven[2] = new WareBase({ 0, 0 }, scale, L"Employee", L"planem", L"plane");
	inven[3] = new WareBase({ 0, 0 }, scale, L"Pig", L"planem", L"plane");
	inven[4] = new WareBase({ 0, 0 }, scale, L"Athlete", L"planem", L"plane");

	for (int i = -2; i <= 2; ++i)
	{
		inven[i + 2]->SetPos({ 640 + i * 175, 575 });
		AddObject(inven[i + 2], OBJECT_GROUP::DEFAULT);
	}
}

void Game_Scene::SetInven(std::vector<WareBase*>& inven)
{
	if (currentInven != nullptr)
		for (int i = 0; i < currentInven->size(); ++i)
			currentInven->at(i)->SetRender(false);

	currentInven = &inven;
	for (int i = 0; i < currentInven->size(); ++i)
		currentInven->at(i)->SetRender(true);
}

void Game_Scene::CreateUrinal(Vec2 startPos, Vec2 scale, float factor, int count)
{
	for (int i = 0; i < count; ++i)
	{
		Urinal* urinal = new Urinal({ 0, 0 }, scale);
		urinal->SetPos({ startPos.x + i * factor, startPos.y });
		urinal->SetScale(scale);
		AddObject(urinal, OBJECT_GROUP::DEFAULT);
	}
}
