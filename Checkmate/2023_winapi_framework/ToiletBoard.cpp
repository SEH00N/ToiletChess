#include "pch.h"
#include "ToiletBoard.h"
#include "WareSlot.h"
#include "Scene.h"
#include "SceneMgr.h"

ToiletBoard::ToiletBoard()
{
	int boardRow = 10;
	slots = std::vector<std::vector<WareSlot*>>(2, std::vector<WareSlot*>(10));

	std::shared_ptr<Scene> scene = SceneMgr::GetInst()->GetCurScene();

	for (int i = 0; i < boardRow; ++i)
	{
		slots[0][i] = new WareSlot({ 100 + i * 120, 300 }, { 90, 140 }, L"Urinal");
		slots[1][i] = new WareSlot({ 100 + i * 120, 415 }, { 90, 90 }, L"Urinal");

		slots[0][i]->SetID(0, i);
		slots[1][i]->SetID(1, i);

		scene->AddObject(slots[0][i]);
		scene->AddObject(slots[1][i]);
	}
}

ToiletBoard::~ToiletBoard()
{
}
