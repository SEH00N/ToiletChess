#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Action.h"

void Start_Scene::Init()
{
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
	RECT_RENDER(10, 10, 10, 10, _dc);
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}