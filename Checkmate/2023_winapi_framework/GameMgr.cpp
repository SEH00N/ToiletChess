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

		SetNotice(L"플레이어 2 차례!");
	}
	else
	{
		inven1->Show();
		inven2->Hide();
		currentInven = inven1;

		SetNotice(L"플레이어 1 차례!");
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
			if (slot->IsEmpty() == false) // 슬롯이 비어있지 않으면 둘 수 없는 상태
				return false; // 넘어감

			if (slot->GetLine() == 0) // 소변기 라인일 경우
		 	{
				WareSlot* left = board->GetSlot(line, index - 1); // 왼쪽 찾고
				WareSlot* right = board->GetSlot(line, index + 1); // 오른쪽 찾기
				bool leftWin = true; // 왼쪽을 이기면 true 아니면 false
				bool rightWin = true; // 오른쪽을 이기면 true 아니면 false

				if (left) // 왼쪽이 존재하면
					leftWin = (confidence > left->GetConfidence()); // 내가 이겼는지 상대가 이겼는지 확인
				if (right) // 오른쪽이 존재하면
					rightWin = (confidence > right->GetConfidence()); // 내가 이겼는지 상대가 이겼는지 확인

				if (leftWin && rightWin) // 둘 다 이겼다면 둘 수 있는 상황
				{
					isEnd = false; // 끝나지 않은 상황
					return true; // 검사 끝내기
				}
			}
			else if (slot->GetLine() == 1) // 대기줄 라인일 경우
			{
				WareSlot* front = board->GetSlot(line - 1, index); // 앞 소변기 찾기
				bool win = false;
				if (front->IsEmpty() == false) // 만약 앞 소변기가 비지 않았다면
					win = height > front->GetHeight(); // 이겼는지 졌는지 확인
				else // 앞 소변기가 비어있다면
				{
					WareSlot* left = board->GetSlot(line - 1, index - 1); // 왼쪽 찾고
					WareSlot* right = board->GetSlot(line - 1, index + 1); // 오른쪽 찾고
					bool leftWin = true;
					bool rightWin = true;

					if (left) // 왼쪽이 존재하면
						leftWin = (confidence > left->GetConfidence()); // 내가 이겼는지 상대가 이겼는지 확인

					if (right) // 오른쪽이 존재하면
						rightWin = (confidence > right->GetConfidence()); // 내가 이겼는지 상대가 이겼는지 확인

					win = leftWin && rightWin; // 둘 다 이겼다면 승리로 처리
				}

				if (win) // 만약 이겼다면 둘 수 있는 상황
				{
					isEnd = false; // 끝나지 않은 상황이고
					return true; // 검사 끝내기
				}
			}
		});

		if (isEnd == false) // 검사가 끝났으면 멈추기
			break;
	}

	bool hasWinner = true;
	if (isEnd == true && currentInven->IsEmpty()) // 낼 수 있는 수가 없는데 현재 인벤이 비었기 때문에 그런 거라면
	{
		Inventory* other = ((currentInven == inven1) ? inven2 : inven1);
		isEnd &= other->IsEmpty(); // 다른 인벤도 비었는지 확인

		if (isEnd)
			hasWinner = false;
	}

	if (isEnd && hasWinner)
		winner = currentInven;

	return isEnd;
}
