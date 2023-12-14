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

		noticeTextBox->SetText(L"�÷��̾� 2 ����!");
	}
	else
	{
		inven1->Show();
		inven2->Hide();
		currentInven = inven1;

		noticeTextBox->SetText(L"�÷��̾� 1 ����!");
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

			if (slot->GetLine() == 0) // �Һ���
			{
				bool leftWin = slot->CheckSide(board->GetSlot(line, index - 1));
				bool rightWin = slot->CheckSide(board->GetSlot(line, index + 1));
				if (leftWin && rightWin) // �ϳ��� �� �� �ִ� ���� ������ ������
				{
					isEnd = false;
					return true;
				}
			}
			else if (slot->GetLine() == 1) // �����
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
