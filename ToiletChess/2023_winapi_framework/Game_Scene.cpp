#include "pch.h"
#include "Game_Scene.h"
#include "Button.h"
#include "WareBase.h"
#include "WareSlot.h"

void Game_Scene::Init()
{
	for (int i = -2; i <= 2; ++i)
	{
		WareSlot* slot = new WareSlot({ 640 + i * 175, 575 }, { 125, 125 }, L"Slot");
		AddObject(slot, OBJECT_GROUP::DEFAULT);
	}

	CreateWare(inven1);
	CreateWare(inven2);

	SetInven(inven1);
}

void Game_Scene::CreateWare(std::vector<WareBase*>& inven)
{
	inven.resize(5);

	//inven[0] = new WareBase({ 0, 0 }, {100, 100}, L"Anchovy", L"Anchovy", L"AnchovyFocused");
	//inven[1] = new WareBase({ 0, 0 }, { 100, 100 }, L"Employee", L"Employee", L"EmployeeFocused");
	//inven[2] = new WareBase({ 0, 0 }, { 100, 100 }, L"Employee", L"Employee", L"EmployeeFocused");
	//inven[3] = new WareBase({ 0, 0 }, { 100, 100 }, L"Pig", L"Pig", L"PigFocused");
	//inven[4] = new WareBase({ 0, 0 }, { 100, 100 }, L"Athlete", L"Athlete", L"AthleteFocused");

	inven[0] = new WareBase({ 0, 0 }, { 100, 100 }, L"Anchovy", L"planem", L"plane");
	inven[1] = new WareBase({ 0, 0 }, { 100, 100 }, L"Employee", L"planem", L"plane");
	inven[2] = new WareBase({ 0, 0 }, { 100, 100 }, L"Employee", L"planem", L"plane");
	inven[3] = new WareBase({ 0, 0 }, { 100, 100 }, L"Pig", L"planem", L"plane");
	inven[4] = new WareBase({ 0, 0 }, { 100, 100 }, L"Athlete", L"planem", L"plane");

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
