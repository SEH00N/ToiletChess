#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Button.h"
#include "WareImage.h"
#include "Inventory.h"

void Start_Scene::Init()
{
	LoadBackground();
	LoadButtons();
}

void Start_Scene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// ¾À º¯°æ
}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
	//RECT_RENDER(10, 10, 10, 10, _dc);
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}

void Start_Scene::LoadBackground()
{
	Vec2 resolution = Core::GetInst()->GetResolution();
	Interface* bg = new Interface(
		{ resolution.x / 2, resolution.y / 2 },
		{ WINDOW_WIDTH, WINDOW_HEIGHT }
	);
	bg->SetTexture(L"BG");
	AddObject(bg, OBJECT_GROUP::DEFAULT);

	Interface* title = new Interface({ 640, 130 }, { 900, 250 });
	title->SetTexture(L"Title");
	AddObject(title, OBJECT_GROUP::DEFAULT);

	for (int i = 0; i < 10; ++i)
	{
		Interface* urinal = new Interface({ 100 + i * 120, 335 }, { 90, 140 });
		urinal->SetTexture(L"Urinal");
		AddObject(urinal, OBJECT_GROUP::DEFAULT);
	}
}

void Start_Scene::LoadButtons()
{
	Button* startButton = new Button({ 640, 525 }, { 350, 95 }, L"StartButton", L"StartButton_Focused");
	startButton->RegisterClicked([]() {SceneMgr::GetInst()->LoadScene(L"Game_Scene"); });
	AddObject(startButton, OBJECT_GROUP::DEFAULT);

	Button* infoButton = new Button({ 640, 640 }, { 350, 95 }, L"InfoButton", L"InfoButton_Focused");
	infoButton->RegisterClicked([]() {SceneMgr::GetInst()->LoadScene(L"Info_Scene"); });
	AddObject(infoButton, OBJECT_GROUP::DEFAULT);
}
