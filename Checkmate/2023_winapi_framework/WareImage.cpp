#include "pch.h"
#include "WareImage.h"
#include "Core.h"
#include "KeyMgr.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "EventMgr.h"
#include "SoundMgr.h"
#include "Scene.h"
#include "WareInventorySlot.h"
#include "WareSlot.h"
#include "ResMgr.h"

WareImage::WareImage(Vec2 pos, Vec2 scale, wstring defaultTexName, wstring focusedTexName, int owner)
	: Button(pos, scale, defaultTexName, focusedTexName), slot{ nullptr }, offset{ Vec2(0, 0) }, owner{ owner }
{
	RegisterPressed([this]() {OnPressed(KeyMgr::GetInst()->GetMousePos()); });
	RegisterClicked([this]() {OnClicked(KeyMgr::GetInst()->GetMousePos()); });
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

		WareSlot* currentSlot = GameMgr::GetInst()->GetCurrentSlot();
		if (currentSlot)
			SetPos(currentSlot->GetPos());
		else
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
	GameMgr::GetInst()->SetCurrentWare(this);
	ResMgr::GetInst()->Play(L"Pick");
}

void WareImage::OnClicked(Vec2 pos)
{
	if (GameMgr::GetInst()->GetCurrentWare() != this)
		return;
	GameMgr::GetInst()->SetCurrentWare(nullptr);

	WareSlot* currentSlot = GameMgr::GetInst()->GetCurrentSlot();
	if (currentSlot == nullptr)
		SetPos(slot->GetPos());
	else
	{
		if (currentSlot->SetWare(this))
		{
			slot->SetWare(nullptr);
			renderable = false;
			//EventMgr::GetInst()->DeleteObject(this);
			GameMgr* game = GameMgr::GetInst();
			
			if (game->CheckEnd())
			{
				game->SetNotice(L"CHECK MATE!");
				ResMgr::GetInst()->Play(L"Whistle");
				game->CalculatePlayerScore();
				ResMgr::GetInst()->Stop(SOUND_CHANNEL::BGM);

				EventMgr::GetInst()->DelayCallback([&game]() {
					Sleep(1000);
					SceneMgr::GetInst()->LoadScene(L"Result_Scene");
				});
			}
			else
				game->ToggleInventory();
		}
		else
			SetPos(slot->GetPos());
	}

	ResMgr::GetInst()->Play(L"Lay");
}
