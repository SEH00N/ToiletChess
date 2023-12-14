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
	if(IsEmpty())
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

bool WareSlot::SetWare(WareImage* ware)
{
	return SetWare(ware->GetTexture(), ware->GetConfidence(), ware->GetHeight(), ware->GetOwner());
}

bool WareSlot::SetWare(Texture* tex, int confidence, int height, int owner)
{
	this->wareTex = tex;
	this->confidence = confidence;
	this->height = height;
	this->owner = owner;

	if (line == 0)
	{
		if (CheckSide() == false)
			return false;
	}
	else if (line == 1)
	{
		if (CheckFront() == false)
			return false;
	}

	Sleep(100);
	return true;
}

bool WareSlot::CheckSide()
{
	ToiletBoard* board = GameMgr::GetInst()->GetBoard();
	WareSlot* left = board->GetSlot(line, index - 1);
	WareSlot* right = board->GetSlot(line, index + 1);

	bool leftWin = CheckSide(left);
	bool rightWin = CheckSide(right);

	if ((leftWin && rightWin) == false)
	{
		ResetSlot();
		return false;
	}
	
	if (leftWin && left)
		left->ResetSlot();
	if (rightWin && right)
		right->ResetSlot();

	return true;
}

bool WareSlot::CheckFront()
{
	ToiletBoard* board = GameMgr::GetInst()->GetBoard();
	WareSlot* front = board->GetSlot(line - 1, index);

	bool isWin = CheckFront(front);
	if (isWin)
	{
		Texture* tempTex = wareTex;
		int tempConfidence = confidence;
		int tempHeight = height;
		int tempOwner = owner;
		ResetSlot();

		front->SetWare(tempTex, tempConfidence, tempHeight, tempOwner);
	}
	else
		ResetSlot();

	return isWin;
}

bool WareSlot::CheckSide(WareSlot* other)
{
	if (other == nullptr || other->wareTex == nullptr)
		return true;

	return confidence > other->confidence;
}

bool WareSlot::CheckFront(WareSlot* other)
{
	if (other == nullptr || other->wareTex == nullptr)
		return true;

	return height > other->height;
}

void WareSlot::ResetSlot()
{
	// 여기에 에니미이션을 넣든 뭐든 해야할 듯
	wareTex = nullptr;
	confidence = 0;
	height = 0;
	owner = 0;
}
