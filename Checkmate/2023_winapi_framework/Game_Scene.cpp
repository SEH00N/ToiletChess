#include "pch.h"
#include "Game_Scene.h"
#include "Core.h"
#include "Interface.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Inventory.h"
#include "WareSlot.h"
#include "ToiletBoard.h"
#include "ToggleImage.h"
#include "Button.h"

void Game_Scene::Init()
{
	LoadBackground();
	LoadButtons();
	LoadTopPanel();

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

void Game_Scene::LoadButtons()
{
	Vec2 resolution = Core::GetInst()->GetResolution();
	Button* exitButton = new Button({ resolution.x - 65, resolution.y - 65 }, { 85, 85 }, L"ExitButton", L"ExitButton_Focused");
	exitButton->RegisterClicked([]() {SceneMgr::GetInst()->LoadScene(L"Start_Scene"); });
	AddObject(exitButton);
}

void Game_Scene::LoadTopPanel()
{
	Vec2 resolution = Core::GetInst()->GetResolution();

	TextBox* noticeText = new TextBox({ resolution.x / 2, 125.0f }, { 1000, 100 }, L"");
	HFONT font = CreateFont(80, 40, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, L"");
	noticeText->SetFont(font);
	noticeText->SetFormat(DT_CENTER | DT_VCENTER);
	noticeText->SetTransparent(true);
	GameMgr::GetInst()->SetNoticeText(noticeText);
	AddObject(noticeText);

	ToggleImage* left = new ToggleImage({ 75, 75 }, {120, 120}, L"Player1On", L"Player1Off");
	left->SetTexture(1);
	AddObject(left);

	ToggleImage* right= new ToggleImage({ resolution.x - 75, 75.0f }, {120, 120}, L"Player2On", L"Player2Off");
	right->SetTexture(2);
	AddObject(right);

	GameMgr::GetInst()->SetPlayerImage(left, right);
	
	HFONT toggleFont = CreateFont(60, 30, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, L"");

	TextBox* p1Text = new TextBox({ 75, 75 }, { 120, 120 }, L"P1");
	p1Text->SetFont(toggleFont);
	p1Text->SetFormat(DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	p1Text->SetTransparent(true);
	AddObject(p1Text);

	TextBox* p2Text = new TextBox({ resolution.x - 75, 75.0f }, { 120, 120 }, L"P2");
	p2Text->SetFont(toggleFont);
	p2Text->SetFormat(DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	p2Text->SetTransparent(true);
	AddObject(p2Text);
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
