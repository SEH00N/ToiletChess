#include "pch.h"
#include "Inventory.h"
#include "WareImage.h"
#include "SceneMgr.h"
#include "Scene.h"

Inventory::Inventory()
{
	slots = std::vector<WareInventorySlot*>(5);

	//slots[0] = CreateSlot(L"Anchovy");
	//slots[1] = CreateSlot(L"Employee");
	//slots[2] = CreateSlot(L"Employee");
	//slots[3] = CreateSlot(L"Pig");
	//slots[4] = CreateSlot(L"Athlete");
	slots[0] = CreateSlot(L"plane");
	slots[1] = CreateSlot(L"plane");
	slots[2] = CreateSlot(L"plane");
	slots[3] = CreateSlot(L"plane");
	slots[4] = CreateSlot(L"plane");

	for (int i = -2; i <= 2; ++i)
	{
		slots[i + 2]->SetPos({ 640 + i * 175, 5750 });
		slots[i + 2]->GetWare()->SetPos({ 640 + i * 175, 5750 });
	}
}

Inventory::~Inventory()
{
}

WareInventorySlot* Inventory::CreateSlot(wstring wareName)
{
	Vec2 slotScale = { 125, 125 };
	Vec2 wareScale = { 100, 100 };
	WareInventorySlot* slot = new WareInventorySlot({ 0, 0 }, slotScale, L"Slot");
	WareImage* ware = new WareImage({ 0, 0 }, wareScale, wareName, wareName);

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
		ware->SetPos({ ware->GetPos().x, 575.0f });
		ware->GetWare()->SetPos(ware->GetPos());
	}
}

void Inventory::Hide()
{
	for (int i = 0; i < slots.size(); ++i)
	{
		WareInventorySlot* ware = slots[i];
		ware->SetRender(true);
		ware->SetPos({ ware->GetPos().x, 5750.0f });
		ware->GetWare()->SetPos(ware->GetPos());
	}
}
