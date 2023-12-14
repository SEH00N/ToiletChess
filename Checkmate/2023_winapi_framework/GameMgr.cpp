#include "pch.h"
#include "GameMgr.h"
#include "Inventory.h"
#include "TextBox.h"
#include "ToiletBoard.h"
#include "WareSlot.h"

void GameMgr::ToggleInventory()
{
	if (currentInven == inven1)
	{
		inven1->Hide();
		inven2->Show();
		currentInven = inven2;

		noticeTextBox->SetText(L"플레이어 2 차례!");
	}
	else
	{
		inven1->Show();
		inven2->Hide();
		currentInven = inven1;

		noticeTextBox->SetText(L"플레이어 1 차례!");
	}
}

bool GameMgr::CheckEnd()
{
	std::vector<WareInventorySlot*>& wares = currentInven->GetWares();
	bool isEnd = true;

	for (int i = 0; i < wares.size(); ++i)
	{
		if (wares[i] == nullptr)
			continue;

		board->ForeachSlot([&, this](WareSlot* slot, int line, int index) {
			if (slot->IsEmpty() == false)
				return false;

			if (slot->GetLine() == 0) // 소변기
			{
				bool leftWin = slot->CheckSide(board->GetSlot(line, index - 1));
				bool rightWin = slot->CheckSide(board->GetSlot(line, index + 1));
				if (leftWin && rightWin) // 하나라도 둘 수 있는 수가 있으면 끝내기
				{
					isEnd = false;
					return true;
				}
			}
			else if (slot->GetLine() == 1) // 대기줄
			{
				bool win = slot->CheckFront(board->GetSlot(line - 1, index));
				if (win)
				{
					isEnd = false;
					return true;
				}
			}
		});
	}

	return isEnd;
}
