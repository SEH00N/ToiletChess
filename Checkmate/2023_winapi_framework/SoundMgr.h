#pragma once
#pragma comment(lib, "Winmm.lib")
#include "pch.h"
#include <unordered_map>

class SoundMgr
{
public:
	SoundMgr();
	~SoundMgr();

	bool Initialize(HWND hWnd);

	void LoadSound(const wchar_t* key, const wchar_t* filePath);

    void PlayBackgroundMusic(const wchar_t* key);

    // ��ư ȿ���� ��� �Լ�
    void PlayButtonEffect(const wchar_t* key);

    // �Ҹ� ���� �Լ�
    void StopSound();

private:
    HWND hwnd;  // ������ �ڵ�
    std::unordered_map<std::wstring, std::wstring> soundMap;  // Ű�� ���� ��θ� �����ϴ� ��
    std::wstring currentBackgroundMusic;  // ���� ��� ���� ������� Ű
};