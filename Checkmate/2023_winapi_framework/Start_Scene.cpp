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
#include "TextBox.h"
#include "GameMgr.h"

void Start_Scene::Init()
{
	LoadSounds();
	LoadBackground();
	LoadButtons();

	//TextBox* text = new TextBox({100, 100}, {10, 10}, L"Hello");
	//AddObject(text);

	//Button* temp = new Button({ 640, 325 }, { 350, 95 }, L"StartButton", L"StartButton_Focused");
	//temp->RegisterClicked([text]() {text->SetText(L"DDD"); });
	//AddObject(temp, OBJECT_GROUP::DEFAULT);
}

void Start_Scene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// �� ����
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

void Start_Scene::LoadSounds()
{
	ResMgr* res = ResMgr::GetInst();
	res->LoadSound(L"IntroBG", L"IntroBG", true);
	res->LoadSound(L"Button", L"Button", false);
	res->Volume(SOUND_CHANNEL::BGM, 0.3f);
	res->Volume(SOUND_CHANNEL::EFFECT, 0.3f);

	res->Stop(SOUND_CHANNEL::BGM);
	res->Play(L"IntroBG");
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
	Vec2 resolution = Core::GetInst()->GetResolution();

	Button* startButton = new Button({ resolution.x / 2 - 225, 575.0f }, { 350, 95 }, L"StartButton", L"StartButton_Focused");
	startButton->RegisterClicked([&]() {
		ResMgr::GetInst()->Play(L"Button");
		Sleep(300);
		SceneMgr::GetInst()->LoadScene(L"Game_Scene");
	});
	AddObject(startButton);

	Button* infoButton = new Button({ resolution.x / 2 + 225, 575.0f }, { 350, 95 }, L"InfoButton", L"InfoButton_Focused");
	infoButton->RegisterClicked([&]() {
		ResMgr::GetInst()->Play(L"Button");
		Sleep(300);
		SceneMgr::GetInst()->LoadScene(L"Info_Scene"); 
	});
	AddObject(infoButton);

	Button* exitButton = new Button({ resolution.x - 65, resolution.y - 65 }, { 85, 85 }, L"ExitButton", L"ExitButton_Focused");
	exitButton->RegisterClicked([&]() {
		ResMgr::GetInst()->Play(L"Button");
		Sleep(300);
		PostQuitMessage(0); 
	});
	AddObject(exitButton);
}
