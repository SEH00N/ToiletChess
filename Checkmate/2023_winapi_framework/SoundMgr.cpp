#include "pch.h"
#include "SoundMgr.h"

SoundMgr::SoundMgr() : hwnd(NULL), currentBackgroundMusic(L"")
{
}

SoundMgr::~SoundMgr()
{
	StopSound();
}

bool SoundMgr::Initialize(HWND hWnd)
{
	this->hwnd = hwnd;
	return false;
}

void SoundMgr::LoadSound(const wchar_t* key, const wchar_t* filePath)
{
	soundMap[key] = filePath;
}

void SoundMgr::PlayBackgroundMusic(const wchar_t* key)
{
    if (currentBackgroundMusic == key)
        return;

    // �ٸ� ��������� ��� ���̸� ����
    StopSound();

    // ������ Ű�� �ش��ϴ� ������� ���
    auto soundFilePath = soundMap.find(key);

    if (soundFilePath != soundMap.end())
    {
        currentBackgroundMusic = key;
        PlaySound(soundFilePath->second.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
}

void SoundMgr::PlayButtonEffect(const wchar_t* key)
{
    auto soundFilePath = soundMap.find(key);

    if (soundFilePath != soundMap.end())
    {
        PlaySound(soundFilePath->second.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void SoundMgr::StopSound()
{
    if (!currentBackgroundMusic.empty())
    {
        PlaySound(NULL, NULL, 0);
        currentBackgroundMusic.clear();
    }
}
