#pragma once
#include "Scene.h"

class Info_Scene : public Scene
{
public:
    virtual void Init() override;

private:
    void LoadLeftPanel();
    void LoadRightPanel();

private:
    void LoadExplane(Vec2 pos, wstring title, wstring content);
    void LoadWare(Vec2 pos, wstring name, wstring displayName, int confidence, int height);
};

