#pragma once
#include "WareInventorySlot.h"
class Inventory
{
public:
	Inventory();
	~Inventory();

private:
	std::vector<WareInventorySlot*> slots;

private:
	WareInventorySlot* CreateSlot(wstring wareName);

public:
	void Show();
	void Hide();
};

