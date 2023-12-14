#include "pch.h"
#include "Result_Scene.h"
#include "Button.h"
#include "Core.h"
#include "SceneMgr.h"
#include "Scene.h"

void Result_Scene::Init()
{
	LoadPanels();
	LoadButtons();
}

void Result_Scene::LoadPanels()
{

}

void Result_Scene::LoadButtons()
{
	Vec2 resolution = Core::GetInst()->GetResolution();

	Button* lobbyButton = new Button({ resolution.x - 225, resolution.y - 90 }, { 350, 95 }, L"LobbyButton", L"LobbyButton_Focused");
	lobbyButton->RegisterClicked([]() {SceneMgr::GetInst()->LoadScene(L"Start_Scene"); });
	AddObject(lobbyButton);
}
