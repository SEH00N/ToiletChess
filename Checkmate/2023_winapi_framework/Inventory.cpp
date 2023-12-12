#include "pch.h"
#include "Inventory.h"
#include "WareImage.h"
#include "SceneMgr.h"
#include "Scene.h"

Inventory::Inventory()
{
	slots = std::vector<WareInventorySlot*>(5);

	slots[0] = CreateSlot(L"Anchovy");
	slots[1] = CreateSlot(L"Employee");
	slots[2] = CreateSlot(L"Employee");
	slots[3] = CreateSlot(L"Pig");
	slots[4] = CreateSlot(L"Athlete");

	for (int i = -2; i <= 2; ++i)
	{
		slots[i + 2]->SetPos({ 640 + i * 175, 6000 });
		slots[i + 2]->GetWare()->SetPos({ 640 + i * 175, 6000 });
	}
}

Inventory::~Inventory()
{
}

WareInventorySlot* Inventory::CreateSlot(wstring wareName)
{
	Vec2 slotScale = { 140, 140 };
	Vec2 wareScale = { 125, 125 };
	WareInventorySlot* slot = new WareInventorySlot({ 0, 0 }, slotScale, L"Slot");
	WareImage* ware = new WareImage({ 0, 0 }, wareScale, wareName, wareName);

	if (wareName == L"Anchovy")
		ware->SetStat(1, 3);
	else if(wareName == L"Employee")
		ware->SetStat(2, 2);
	else if(wareName == L"Pig")
		ware->SetStat(4, 1);
	else if(wareName == L"Athlete")
		ware->SetStat(3, 3);

	slot->SetWare(ware);
	ware->SetSlot(slot);

	std::shared_ptr<Scene> scene = SceneMgr::GetInst()->GetCurScene();
	scene->AddObject(slot, OBJECT_GROUP::DEFAULT);
	scene->AddObject(ware, OBJECT_GROUP::DEFAULT);
	
	return slot;
}

void Inventory::Show()
{
	for (int i = 0; i < slots.size(); ++i)
	{
		WareInventorySlot* ware = slots[i];
		ware->SetRender(true);
		ware->SetPos({ ware->GetPos().x, 600.0f });
		ware->GetWare()->SetPos(ware->GetPos());
	}
}

void Inventory::Hide()
{
	for (int i = 0; i < slots.size(); ++i)
	{
		WareInventorySlot* ware = slots[i];
		ware->SetRender(true);
		ware->SetPos({ ware->GetPos().x, 6000.0f });
		ware->GetWare()->SetPos(ware->GetPos());
	}
}
