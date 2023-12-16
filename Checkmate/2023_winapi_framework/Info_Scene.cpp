#include "pch.h"
#include "Info_Scene.h"
#include "TextBox.h"
#include "Interface.h"
#include "Button.h"
#include "Core.h"
#include "SceneMgr.h"
#include "ResMgr.h"

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
	lobbyButton->RegisterClicked([&]() {
		ResMgr::GetInst()->Play(L"Button");
		Sleep(500);
		SceneMgr::GetInst()->LoadScene(L"Start_Scene"); 
	});
	AddObject(lobbyButton);
}

void Info_Scene::LoadLeftPanel()
{
	LoadExplane({ 75, 50 }, L"승리 조건", L"직전에 둔 수로 인해 상대방이 둘 수 있는 수가 없는 경우 게임에서 승리합니다.\n만약 두 플레이어 모두 모든 말을 사용했을 경우엔 더 많은 말이 배치된 쪽의\n플레이어가 승리하게 됩니다.");

	LoadExplane({ 75, 275 }, L"키", L"키는 소변기 뒤에 배치된 말이 앞쪽 소변기에 배치된 말과 겨룰 때 사용되는 스탯입니다.\n\n앞쪽에 배치된 말이 새로 배치된 말보다 키가 작다면 앞에 배치된 말은 도망가게 됩니다.");
	
	LoadExplane({ 75, 500 }, L"자신감", L"자신감은 소변기에 배치된 말이 좌우 소변기에 배치된 말과 겨룰 때 사용되는 스탯입니다.\n\n옆에 배치된 말이 새로 배치된 말보다 자신감이 낮다면 옆에 배치된 말들은 도망가게 됩니다.");
}

void Info_Scene::LoadRightPanel()
{
	LoadWare({ 700, 50 }, L"Anchovy", L"멸치", 1, 3);
	LoadWare({ 700, 175 }, L"Employee", L"회사원", 2, 2);
	LoadWare({ 700, 300 }, L"Pig", L"문돼", 4, 1);
	LoadWare({ 700, 425 }, L"Athlete", L"헬창", 3, 3);
}

void Info_Scene::LoadExplane(Vec2 pos, wstring title, wstring content)
{
	Vec2 tPos = pos;
	Vec2 scale = { 200, 40 };
	tPos.x += scale.x / 2;
	tPos.y += scale.y / 2;
	Interface* titleBG = new Interface(tPos, scale);
	titleBG->SetTexture(L"InfoTitlePanel");

	TextBox* titleText = new TextBox(tPos + Vec2(0, 3), scale, title);
	HFONT titleFont = CreateFont(24, 16, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Tenada"));
	titleText->SetFont(titleFont);
	titleText->SetTransparent(true);
	titleText->SetFormat(DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	tPos = pos;
	scale = { 500, 100 };
	tPos.x += scale.x / 2 + 20;
	tPos.y += scale.y / 2 + 70;
	Interface* contentBG = new Interface(tPos - Vec2(10, 10), scale + Vec2(20, 20));
	contentBG->SetTexture(L"ExplanePanel");

	TextBox* contentText = new TextBox(tPos, scale, content);
	HFONT contentFont = CreateFont(18, 12, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("소요단풍체 볼드 TTF"));
	contentText->SetFont(contentFont);
	contentText->SetTransparent(true);
	contentText->SetFormat(DT_LEFT | DT_WORDBREAK);

	AddObject(titleBG);
	AddObject(contentBG);
	AddObject(titleText);
	AddObject(contentText);
}

void Info_Scene::LoadWare(Vec2 pos, wstring name, wstring displayName, int confidence, int height)
{
	Vec2 tPos = pos;
	Vec2 scale = { 85, 85 };
	tPos.x += scale.x / 2 + 5;
	tPos.y += scale.y / 2 + 5;
	Interface* wareImageBG = new Interface(tPos, scale + Vec2(10, 10));
	wareImageBG->SetTexture(L"CharacterBG");
	Interface* wareImage = new Interface(tPos, scale);
	wareImage->SetTexture(name);

	tPos = pos;
	scale = { 300, 85 };
	tPos.x += scale.x / 2 + 150 + 10;
	tPos.y += scale.y / 2 + 10;
	TextBox* contentText = new TextBox(tPos + Vec2(10, -10), scale,
		L"\n[" + displayName + L"]\n자신감 : " + std::to_wstring(confidence) + L"\n키 : " + std::to_wstring(height));
	HFONT contentFont = CreateFont(20, 8, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("배달의민족 주아"));
	contentText->SetFont(contentFont);
	contentText->SetTransparent(true);
	contentText->SetFormat(DT_LEFT);

	Interface* wareInfoBG = new Interface(tPos - Vec2(5, 5), scale + Vec2(10, 10));
	wareInfoBG->SetTexture(L"StatusPanel");

	AddObject(wareImageBG);
	AddObject(wareImage);
	AddObject(wareInfoBG);
	AddObject(contentText);

}
