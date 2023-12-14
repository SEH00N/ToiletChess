#include "pch.h"
#include "WareInventorySlot.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "TextBox.h"
#include "WareImage.h"

WareInventorySlot::WareInventorySlot(Vec2 pos, Vec2 scale, wstring texName) : Interface(pos, scale), ware{nullptr}
{
	SetTexture(texName);
	textBox = new TextBox(GetPos(), GetScale(), L"");
	textBox->SetRender(false);
	textBox->SetFormat(DT_LEFT);
}

void WareInventorySlot::OnMouseEnter()
{
	textBox->SetRender(true);
}

void WareInventorySlot::OnMouseExit()
{
	textBox->SetRender(false);
}

void WareInventorySlot::SetPos(Vec2 pos)
{
	Interface::SetPos(pos);
	if(ware)
		ware->SetPos(pos);
	textBox->SetPos(pos);
}

void WareInventorySlot::InitTextBox()
{
	if(textBox)
		SceneMgr::GetInst()->GetCurScene()->AddObject(textBox);
}
