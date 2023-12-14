#pragma once
#include "WareInventorySlot.h"
class Inventory
{
public:
	Inventory(int owner);
	~Inventory();

private:
	std::vector<WareInventorySlot*> slots;

private:
	WareInventorySlot* CreateSlot(wstring wareName);

public:
	std::vector<WareInventorySlot*>& GetWares() { return slots; }
	bool IsEmpty();

public:
	void Show();
	void Hide();

private:
	int owner;
};

