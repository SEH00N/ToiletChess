#include "pch.h"
#include "WareBase.h"
#include "KeyMgr.h"
#include "Core.h"
#include <functional>

WareBase::WareBase(Vec2 pos, Vec2 scale, wstring buttonName, wstring defaultTexName, wstring eventTexName) : Button(pos, scale, buttonName, defaultTexName, eventTexName), offset{ 0, 0 }, confidence{ 0 }, height{0}
{
	RegisterClicked([this]() {OnClicked(); });
}

WareBase::~WareBase()
{
}

void WareBase::Update()
{
	Button::Update();

	if (clicked)
	{
		Vec2 mousePos = KeyMgr::GetInst()->GetMousePos();
		Vec2 resolution = Core::GetInst()->GetResolution();
		if (mousePos.x >= resolution.x || mousePos.x <= 0 || mousePos.y >= resolution.y || mousePos.y <= 0)
			return;
		SetPos(mousePos + offset);
	}
}

void WareBase::OnClicked()
{
	Vec2 pos = GetPos();
	Vec2 mousePos = KeyMgr::GetInst()->GetMousePos();
	offset = pos - mousePos;
}

bool WareBase::CheckFront(WareBase& right)
{
	return (this->height > right.height);
}

bool WareBase::CheckSide(WareBase& right)
{
	return (this->confidence > right.confidence);
}
