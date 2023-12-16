#include "pch.h"
#include "GameMgr.h"
#include "Inventory.h"
#include "TextBox.h"
#include "ToiletBoard.h"
#include "WareSlot.h"
#include "ToggleImage.h"
#include "WareImage.h"

void GameMgr::SetNotice(wstring text)
{
	this->noticeTextBox->SetText(text);
}

void GameMgr::Reset()
{
	if (inven1)
	{
		delete inven1;
		inven1 = nullptr;
	}

	if (inven2)
	{
		delete inven2;
		inven2 = nullptr;
	}

	if (board)
	{
		delete board;
		board = nullptr;
	}
}

void GameMgr::ToggleInventory()
{
	if (currentInven == inven1)
	{
		inven1->Hide();
		inven2->Show();
		currentInven = inven2;

		SetNotice(L"�÷��̾� 2 ����!");
	}
	else
	{
		inven1->Show();
		inven2->Hide();
		currentInven = inven1;

		SetNotice(L"�÷��̾� 1 ����!");
	}

	leftPlayerImage->ToggleTexture();
	rightPlayerImage->ToggleTexture();
}

void GameMgr::CalculatePlayerScore()
{
	int player1 = 0, player2 = 0;
	board->ForeachSlot([&](WareSlot* slot, int line, int index) {
		if(slot->IsEmpty())
			return false;
			
		if (slot->GetOwner() == 1)
			player1++;
		else if (slot->GetOwner() == 2)
			player2++;

		return false;
	});

	this->player1Score = player1;
	this->player2Score = player2;
}


bool GameMgr::CheckEnd()
{
	std::vector<WareInventorySlot*>& wares = ((currentInven == inven1) ? inven2->GetWares() : inven1->GetWares());
	bool isEnd = true;

	for (int i = 0; i < wares.size(); ++i)
	{
		WareImage* ware = wares[i]->GetWare();
		if (ware == nullptr)
			continue;

		int confidence = ware->GetConfidence();
		int height = ware->GetHeight();

		board->ForeachSlot([&, this](WareSlot* slot, int line, int index) {
			if (slot->IsEmpty() == false) // ������ ������� ������ �� �� ���� ����
				return false; // �Ѿ

			if (slot->GetLine() == 0) // �Һ��� ������ ���
		 	{
				WareSlot* left = board->GetSlot(line, index - 1); // ���� ã��
				WareSlot* right = board->GetSlot(line, index + 1); // ������ ã��
				bool leftWin = true; // ������ �̱�� true �ƴϸ� false
				bool rightWin = true; // �������� �̱�� true �ƴϸ� false

				if (left) // ������ �����ϸ�
					leftWin = (confidence > left->GetConfidence()); // ���� �̰���� ��밡 �̰���� Ȯ��
				if (right) // �������� �����ϸ�
					rightWin = (confidence > right->GetConfidence()); // ���� �̰���� ��밡 �̰���� Ȯ��

				if (leftWin && rightWin) // �� �� �̰�ٸ� �� �� �ִ� ��Ȳ
				{
					isEnd = false; // ������ ���� ��Ȳ
					return true; // �˻� ������
				}
			}
			else if (slot->GetLine() == 1) // ����� ������ ���
			{
				WareSlot* front = board->GetSlot(line - 1, index); // �� �Һ��� ã��
				bool win = false;
				if (front->IsEmpty() == false) // ���� �� �Һ��Ⱑ ���� �ʾҴٸ�
					win = height > front->GetHeight(); // �̰���� ������ Ȯ��
				else // �� �Һ��Ⱑ ����ִٸ�
				{
					WareSlot* left = board->GetSlot(line - 1, index - 1); // ���� ã��
					WareSlot* right = board->GetSlot(line - 1, index + 1); // ������ ã��
					bool leftWin = true;
					bool rightWin = true;

					if (left) // ������ �����ϸ�
						leftWin = (confidence > left->GetConfidence()); // ���� �̰���� ��밡 �̰���� Ȯ��

					if (right) // �������� �����ϸ�
						rightWin = (confidence > right->GetConfidence()); // ���� �̰���� ��밡 �̰���� Ȯ��

					win = leftWin && rightWin; // �� �� �̰�ٸ� �¸��� ó��
				}

				if (win) // ���� �̰�ٸ� �� �� �ִ� ��Ȳ
				{
					isEnd = false; // ������ ���� ��Ȳ�̰�
					return true; // �˻� ������
				}
			}
		});

		if (isEnd == false) // �˻簡 �������� ���߱�
			break;
	}

	bool hasWinner = true;
	if (isEnd == true && currentInven->IsEmpty()) // �� �� �ִ� ���� ���µ� ���� �κ��� ����� ������ �׷� �Ŷ��
	{
		Inventory* other = ((currentInven == inven1) ? inven2 : inven1);
		isEnd &= other->IsEmpty(); // �ٸ� �κ��� ������� Ȯ��

		if (isEnd)
			hasWinner = false;
	}

	if (isEnd && hasWinner)
		winner = currentInven;

	return isEnd;
}
