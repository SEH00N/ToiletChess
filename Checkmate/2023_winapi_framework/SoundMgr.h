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

    // 버튼 효과음 재생 함수
    void PlayButtonEffect(const wchar_t* key);

    // 소리 중지 함수
    void StopSound();

private:
    HWND hwnd;  // 윈도우 핸들
    std::unordered_map<std::wstring, std::wstring> soundMap;  // 키와 파일 경로를 저장하는 맵
    std::wstring currentBackgroundMusic;  // 현재 재생 중인 배경음악 키
};