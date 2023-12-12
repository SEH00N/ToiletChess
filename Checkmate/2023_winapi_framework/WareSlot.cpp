#include "pch.h"
#include "WareSlot.h"
#include "WareImage.h"
#include "GameMgr.h"
#include "ToiletBoard.h"
#include "Texture.h"

WareSlot::WareSlot(Vec2 pos, Vec2 scale, wstring texName) : Interface(pos, scale), wareTex{nullptr}
{
	SetTexture(texName);
}

void WareSlot::Render(HDC hDC)
{
	Interface::Render(hDC);

	if (wareTex == nullptr)
		return;

	Vec2 pos = GetPos();
	Vec2 scale = { 125, 125 };

	int width = wareTex->GetWidth();
	int height = wareTex->GetHeight();

	//StretchBlt(hDC
	//	, (int)(pos.x - scale.x / 2)
	//	, (int)(pos.y - scale.y / 2)
	//	, scale.x, scale.y, texture->GetDC()
	//	, 0, 0, width, height,
	//	SRCCOPY);

	TransparentBlt(hDC
		, (int)(pos.x - scale.x / 2)
		, (int)(pos.y - scale.y / 2)
		, scale.x, scale.y, wareTex->GetDC()
		, 0, 0, width, height,
		RGB(255, 0, 255));
}

void WareSlot::OnMouseEnter()
{
	GameMgr::GetInst()->SetCurrentSlot(this);

	WareImage* ware = GameMgr::GetInst()->GetCurrentWare();
	if (ware == nullptr)
		return;


}

void WareSlot::OnMouseExit()
{
	if(GameMgr::GetInst()->GetCurrentSlot() == this)
		GameMgr::GetInst()->SetCurrentSlot(nullptr);
}

void WareSlot::SetWare(WareImage* ware)
{
	SetWare(ware->GetTexture(), ware->GetConfidence(), ware->GetHeight());
}

void WareSlot::SetWare(Texture* tex, int confidence, int height)
{
	this->wareTex = tex;
	this->confidence = confidence;
	this->height = height;

	if (line == 0)
		CheckSide();
	else if (line == 1)
		CheckFront();

	GameMgr::GetInst()->ToggleInventory();
}

void WareSlot::CheckSide()
{
	if (wareTex == nullptr)
		return;

	ToiletBoard* board = GameMgr::GetInst()->GetBoard();
	WareSlot* left = board->GetSlot(line, index - 1);
	WareSlot* right = board->GetSlot(line, index + 1);

	if (left && left->wareTex)
	{
		bool isWin = CheckSide(left);
		if (isWin)
			left->ResetSlot();
	}

	if (right && right->wareTex)
	{
		bool isWin = CheckSide(right);
		if (isWin)
			right->ResetSlot();
	}
}

void WareSlot::CheckFront()
{
	if (wareTex == nullptr)
		return;

	ToiletBoard* board = GameMgr::GetInst()->GetBoard();
	WareSlot* front = board->GetSlot(line - 1, index);

	if (front && front->wareTex)
	{
		bool isWin = CheckFront(front);
		if (isWin)
		{
			Texture* tempTex = wareTex;
			int tempConfidence = confidence;
			int tempHeight = height;
			ResetSlot();

			front->SetWare(tempTex, tempConfidence, tempHeight);
		}
	}
}

void WareSlot::ResetSlot()
{
	// 여기에 에니미이션을 넣든 뭐든 해야할 듯
	wareTex = nullptr;
	confidence = 0;
	height = 0;
}
