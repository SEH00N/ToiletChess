#include "pch.h"
#include "Info_Scene.h"
#include "TextBox.h"
#include "Interface.h"
#include "Button.h"
#include "Core.h"
#include "SceneMgr.h"

void Info_Scene::Init()
{
	Vec2 resolution = Core::GetInst()->GetResolution();

	Interface* bg = new Interface(
		{ resolution.x / 2, resolution.y / 2 },
		{ WINDOW_WIDTH, WINDOW_HEIGHT }
	);
	bg->SetTexture(L"BG");
	AddObject(bg);

	LoadLeftPanel();
	LoadRightPanel();


	Button* lobbyButton = new Button({ 925.0f, resolution.y - 100 }, { 350, 95 }, L"LobbyButton", L"LobbyButton_Focused");
	lobbyButton->RegisterClicked([]() {SceneMgr::GetInst()->LoadScene(L"Start_Scene"); });
	AddObject(lobbyButton);
}

void Info_Scene::LoadLeftPanel()
{
	LoadExplane({ 75, 50 }, L"승리 조건", L"이렇게 하면 이깁니다.");
	LoadExplane({ 75, 275 }, L"키", L"키가 작으면 도망가야겠지?");
	LoadExplane({ 75, 500 }, L"자신감", L"자신감이 낮으면 도망가야겠지?");
}

void Info_Scene::LoadRightPanel()
{
	LoadWare({ 700, 50 }, L"Anchovy", 10, 10);
	LoadWare({ 700, 175 }, L"Employee", 10, 10);
	LoadWare({ 700, 300 }, L"Pig", 10, 10);
	LoadWare({ 700, 425 }, L"Athlete", 10, 10);
}

void Info_Scene::LoadExplane(Vec2 pos, wstring title, wstring content)
{
	Vec2 tPos = pos;
	Vec2 scale = { 200, 40 };
	tPos.x += scale.x / 2;
	tPos.y += scale.y / 2;
	Interface* titleBG = new Interface(tPos, scale);
	titleBG->SetTexture(L"ExplanePanel");
	TextBox* titleText = new TextBox(tPos, scale, title);
	titleText->SetTransparent(true);
	titleText->SetFormat(DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	tPos = pos;
	scale = { 500, 100 };
	tPos.x += scale.x / 2 + 20;
	tPos.y += scale.y / 2 + 70;
	Interface* contentBG = new Interface(tPos - Vec2(10, 10), scale + Vec2(20, 20));
	contentBG->SetTexture(L"ExplanePanel");
	TextBox* contentText = new TextBox(tPos, scale, content);
	contentText->SetTransparent(true);
	contentText->SetFormat(DT_LEFT);

	AddObject(titleBG);
	AddObject(contentBG);
	AddObject(titleText);
	AddObject(contentText);
}

void Info_Scene::LoadWare(Vec2 pos, wstring name, int confidence, int height)
{
	Vec2 tPos = pos;
	Vec2 scale = { 85, 85 };
	tPos.x += scale.x / 2 + 5;
	tPos.y += scale.y / 2 + 5;
	Interface* wareImageBG = new Interface(tPos, scale + Vec2(10, 10));
	wareImageBG->SetTexture(L"StatusPanel");
	Interface* wareImage = new Interface(tPos, scale);
	wareImage->SetTexture(name);

	tPos = pos;
	scale = { 300, 85 };
	tPos.x += scale.x / 2 + 150 + 10;
	tPos.y += scale.y / 2 + 10;
	TextBox* contentText = new TextBox(tPos, scale, L"안녕");
	contentText->SetTransparent(true);
	contentText->SetFormat(DT_LEFT);

	Interface* wareInfoBG = new Interface(tPos - Vec2(5, 5), scale + Vec2(10, 10));
	wareInfoBG->SetTexture(L"StatusPanel");

	AddObject(wareImageBG);
	AddObject(wareImage);
	AddObject(wareInfoBG);
	AddObject(contentText);

}
