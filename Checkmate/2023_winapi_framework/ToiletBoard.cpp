#include "pch.h"
#include "ToiletBoard.h"
#include "WareSlot.h"
#include "Scene.h"
#include "SceneMgr.h"

ToiletBoard::ToiletBoard()
{
	slots = std::vector<std::vector<WareSlot*>>(2, std::vector<WareSlot*>(10));

	std::shared_ptr<Scene> scene = SceneMgr::GetInst()->GetCurScene();

	for (int i = 0; i < BoardRow; ++i)
	{
		slots[0][i] = new WareSlot({ 100 + i * 120, 300 }, { 90*0.75f, 140*0.75f }, L"Urinal");
		slots[1][i] = new WareSlot({ 100 + i * 120, 415 }, { 90*0.75f, 90*0.75f }, L"Slot");

		slots[0][i]->SetID(0, i);
		slots[1][i]->SetID(1, i);

		scene->AddObject(slots[0][i]);
		scene->AddObject(slots[1][i]);
	}
}

ToiletBoard::~ToiletBoard()
{
}

WareSlot* ToiletBoard::GetSlot(int line, int index)
{
	if(index < 0 || index >= BoardRow)
		return nullptr;

	if (line < 0 || line >= 2)
		return nullptr;

	return slots[line][index];
}
