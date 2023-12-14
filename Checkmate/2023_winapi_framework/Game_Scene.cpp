#include "pch.h"
#include "Game_Scene.h"
#include "Core.h"
#include "Interface.h"
#include "GameMgr.h"
#include "Inventory.h"
#include "WareSlot.h"
#include "ToiletBoard.h"

void Game_Scene::Init()
{
	LoadBackground();
	LoadText();

	board = new ToiletBoard();
	GameMgr::GetInst()->SetBoard(board);

	InitInventory();
}

void Game_Scene::LoadBackground()
{
	Vec2 resolution = Core::GetInst()->GetResolution();
	Interface* bg = new Interface(
		{ resolution.x / 2, resolution.y / 2 },
		{ WINDOW_WIDTH, WINDOW_HEIGHT }
	);
	bg->SetTexture(L"BG");
	AddObject(bg, OBJECT_GROUP::DEFAULT);
}

void Game_Scene::LoadText()
{
	Vec2 resolution = Core::GetInst()->GetResolution();

	TextBox* noticeText = new TextBox({ resolution.x / 2 - 500, 75.0f }, { 1000, 100 }, L"");
	HFONT font = CreateFont(80, 40, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, L"");
	noticeText->SetFont(font);
	noticeText->SetFormat(DT_CENTER);
	noticeText->SetTransparent(true);
	GameMgr::GetInst()->SetNoticeText(noticeText);
	AddObject(noticeText);
}

void Game_Scene::InitInventory()
{
	inven1 = new Inventory(1);
	inven2 = new Inventory(2);

	GameMgr::GetInst()->SetInventory(inven1, inven2, inven2);
	GameMgr::GetInst()->ToggleInventory();
	//inven1->Show();
	//inven2->Hide();
}
