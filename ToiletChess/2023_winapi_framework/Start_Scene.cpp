#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "BG.h"
#include "Button.h"

void Start_Scene::Init()
{
	BG* bg = new BG(L"BG", L"BG");
	AddObject(bg, OBJECT_GROUP::DEFAULT);

	Button* startButton = new Button({ 100, 100 }, { 100, 100 }, L"StartButton", L"planem", L"plane");
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
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
