#include "pch.h"
#include "GameMgr.h"
#include "Inventory.h"

void GameMgr::ToggleInventory()
{
	if (currentInven == inven1)
	{
		inven1->Hide();
		inven2->Show();
		currentInven = inven2;
	}
	else
	{
		inven1->Show();
		inven2->Hide();
		currentInven = inven1;
	}
}
