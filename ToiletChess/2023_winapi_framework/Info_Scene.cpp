#include "pch.h"
#include "Info_Scene.h"
#include "Button.h"
#include "SceneMgr.h"

void Info_Scene::Init()
{
	Button* returnButton = new Button({ 640, 625 }, { 400, 85 }, L"ReturnButton", L"planem", L"plane");
	returnButton->RegisterReleased([]() {SceneMgr::GetInst()->LoadScene(L"Start_Scene"); });
	AddObject(returnButton, OBJECT_GROUP::DEFAULT);
}

void Info_Scene::Update()
{
	Scene::Update();
}

void Info_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Info_Scene::Release()
{
	Scene::Release();
}
