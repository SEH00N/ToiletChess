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
	HFONT font = CreateFont(15, 6, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("배달의민족 주아"));
	textBox = new TextBox(pos, scale - Vec2(30, 30), L"");
	textBox->SetRender(false);
	textBox->SetFont(font);
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
	textBox->SetPos(pos + Vec2(0.0f, GetScale().y / 2));
}

void WareInventorySlot::InitTextBox()
{
	if(textBox)
		SceneMgr::GetInst()->GetCurScene()->AddObject(textBox);
}
