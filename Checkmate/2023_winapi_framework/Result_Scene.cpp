#include "pch.h"
#include "Result_Scene.h"
#include "Button.h"
#include "Core.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Inventory.h"
#include "GameMgr.h"
#include "TextBox.h"
#include "ResMgr.h"

void Result_Scene::Init()
{
	LoadBackground();
	LoadTopPanel();
	LoadBottomPanel();
	LoadButtons();
}

void Result_Scene::LoadSounds()
{
	ResMgr* res = ResMgr::GetInst();
	res->LoadSound(L"ResultBG", L"ResultBG", true);
	res->LoadSound(L"Button", L"Button", false);
	res->Volume(SOUND_CHANNEL::BGM, 0.3f);
	res->Volume(SOUND_CHANNEL::EFFECT, 0.3f);

	res->Stop(SOUND_CHANNEL::BGM);
	res->Play(L"ResultBG");
}

void Result_Scene::LoadBackground()
{
	Vec2 resolution = Core::GetInst()->GetResolution();

	Interface* bg = new Interface(
		{ resolution.x / 2, resolution.y / 2 },
		{ WINDOW_WIDTH, WINDOW_HEIGHT }
	);
	bg->SetTexture(L"BG");
	AddObject(bg);

	//for (int i = 0; i < 6; ++i)
	//{
	//	Interface* urinal = new Interface({ 150 + i * 195, 300 }, { 90 * 0.75f, 140 * 0.75f });
	//	urinal->SetTexture(L"Urinal");
	//	AddObject(urinal, OBJECT_GROUP::DEFAULT);
	//}
}

void Result_Scene::LoadTopPanel()
{
	GameMgr* game = GameMgr::GetInst();
	Inventory* winner = game->GetWinner();
	int player1Score = game->GetPlayerScore(1);
	int player2Score = game->GetPlayerScore(2);

	Interface* bg = new Interface({ 400, 125 }, { 700, 150 });
	bg->SetTexture(L"StatusPanel");

	HFONT font = CreateFont(90, 60, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Tenada"));
	TextBox* textBox = new TextBox({ 400, 135 }, { 700, 150 }, L"");
	textBox->SetFont(font);
	textBox->SetFormat(DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	textBox->SetTransparent(true);
	if (winner) // 위너가 있는 경우
	{
		textBox->SetText(L"PLAYER " + std::to_wstring(winner->GetOwner()) + L" 승리!");
	}
	else
	{
		int winnerID = 0;
		if (player1Score > player2Score)
			winnerID = 1;
		else if (player1Score < player2Score)
			winnerID = 2;

		if(winnerID == 0)
			textBox->SetText(L"DRAW!");
		else
			textBox->SetText(L"PLAYER " + std::to_wstring(winnerID) + L" 승리!");
	}

	AddObject(bg);
	AddObject(textBox);
}

void Result_Scene::LoadBottomPanel()
{
	Vec2 resolution = Core::GetInst()->GetResolution();

	Interface* bg = new Interface({ 350.0f, resolution.y - 150 }, { 600, 200 });
	bg->SetTexture(L"ExplanePanel");

	GameMgr* game = GameMgr::GetInst();
	int player1Score = game->GetPlayerScore(1);
	int player2Score = game->GetPlayerScore(2);
	TextBox* text = new TextBox({ 350.0f, resolution.y - 135 }, { 550, 150 },
		L"PLAYER 1의 점수(말 개수) : " + std::to_wstring(player1Score) + L"\n\n" +
		L"PLAYER 2의 점수(말 개수) : " + std::to_wstring(player2Score)
	);
	HFONT font = CreateFont(40, 16, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("배달의민족 주아"));
	text->SetFont(font);
	text->SetTransparent(true);

	AddObject(bg);
	AddObject(text);
}

void Result_Scene::LoadButtons()
{
	Vec2 resolution = Core::GetInst()->GetResolution();

	Button* lobbyButton = new Button({ resolution.x - 225, resolution.y - 90 }, { 350, 95 }, L"LobbyButton", L"LobbyButton_Focused");
	lobbyButton->RegisterClicked([]() {
		ResMgr::GetInst()->Play(L"Button");
		Sleep(300);
		SceneMgr::GetInst()->LoadScene(L"Start_Scene"); 
	});
	AddObject(lobbyButton);
}
