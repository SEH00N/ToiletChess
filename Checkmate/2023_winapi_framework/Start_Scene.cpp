#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Button.h"

void Start_Scene::Init()
{
	Button* startButton = new Button({ 640, 525 }, { 350, 95 }, L"StartButton", L"StartButton_Focused");
	startButton->RegisterClicked([](Vec2 pos) {SceneMgr::GetInst()->LoadScene(L"Game_Scene"); });
	AddObject(startButton, OBJECT_GROUP::DEFAULT);
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