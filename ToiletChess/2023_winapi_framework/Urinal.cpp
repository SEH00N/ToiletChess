#include "pch.h"
#include "Urinal.h"
#include "WareBase.h"
#include "GameMgr.h"
#include "Object.h"
#include "ResMgr.h"

Urinal::Urinal(Vec2 pos, Vec2 scale) : Interface{ pos, scale }, isFocused{false}
{
	texture = ResMgr::GetInst()->TexLoad(L"Urinal", L"Texture\\Urinal.bmp");
}

Urinal::~Urinal()
{
}

void Urinal::Update()
{
	Interface::Update();
}

void Urinal::FinalUpdate()
{
	Object::FinalUpdate();

	if (isFocused == false)
		return;

	WareBase* ware = GameMgr::GetInst()->GetCurrentWare();
	if (ware == nullptr)
		return;

	ware->SetPos(GetPos());
}

void Urinal::OnMouseEnter()
{
	WareBase* ware = GameMgr::GetInst()->GetCurrentWare();
	if (ware == nullptr)
		return;

	isFocused = true;
	GameMgr::GetInst()->SetCurrentUrinal(this);
}

void Urinal::OnMouse()
{

}

void Urinal::OnMouseExit()
{
	isFocused = false;
	GameMgr::GetInst()->SetCurrentUrinal(nullptr);
}
