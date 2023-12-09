#include "pch.h"
#include "WareImage.h"
#include "Core.h"
#include "KeyMgr.h"

WareImage::WareImage(Vec2 pos, Vec2 scale, wstring defaultTexName, wstring focusedTexName) 
	: Button(pos, scale, defaultTexName, focusedTexName), slot{ nullptr }, offset{Vec2(0, 0)}
{
	RegisterPressed([this](Vec2 pos) {OnPressed(pos); });
	RegisterClicked([this](Vec2 pos) {OnClicked(pos); });
}

WareImage::~WareImage()
{
}

void WareImage::Update()
{
	Button::Update();

	if(pressed)
	{
		Vec2 mousePos = KeyMgr::GetInst()->GetMousePos();
		Vec2 resolution = Core::GetInst()->GetResolution();
		if (mousePos.x >= resolution.x || mousePos.x <= 0 || mousePos.y >= resolution.y || mousePos.y <= 0)
			return;

		SetPos(mousePos + offset);
	}
}

Vec2 WareImage::CalculateOffset(Vec2 mousePos)
{
	Vec2 pos = GetPos();
	return (pos - mousePos);
}

void WareImage::OnPressed(Vec2 pos)
{
	offset = CalculateOffset(pos);
}

void WareImage::OnClicked(Vec2 pos)
{
}