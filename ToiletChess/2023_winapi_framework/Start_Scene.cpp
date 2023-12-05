#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "BG.h"
#include "Button.h"

void Start_Scene::Init()
{
	BG* bg = new BG(L"BG", L"BG");
	bg->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	bg->SetScale({ WINDOW_WIDTH, WINDOW_HEIGHT });
	AddObject(bg, OBJECT_GROUP::DEFAULT);

	BG* title = new BG(L"Title", L"Title");
	title->SetPos({ 640, 130 });
	title->SetScale({ 900, 250 });
	AddObject(title, OBJECT_GROUP::DEFAULT);

	for (int i = 0; i < 10; ++i)
	{
		BG* urinal = new BG(L"Urinal", L"Urinal");
		urinal->SetPos({ 100 + i * 120, 335 });
		urinal->SetScale({ 90, 140 });
		AddObject(urinal, OBJECT_GROUP::DEFAULT);
	}

	Button* startButton = new Button({ 640, 525 }, { 350, 95 }, L"ButtonStart", L"ButtonStart", L"ButtonStart_Focus");
	startButton->RegisterReleased([]() {SceneMgr::GetInst()->LoadScene(L"Game_Scene"); });
	AddObject(startButton, OBJECT_GROUP::DEFAULT);

	Button* infoButton = new Button({ 640, 640 }, { 350, 95 }, L"ButtonInfo", L"ButtonInfo", L"ButtonInfo_Focus");
	infoButton->RegisterReleased([]() {SceneMgr::GetInst()->LoadScene(L"Info_Scene"); });
	AddObject(infoButton, OBJECT_GROUP::DEFAULT);
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
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
