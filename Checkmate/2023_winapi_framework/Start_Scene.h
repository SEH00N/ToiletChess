#pragma once
#include "Scene.h"

template<typename T>
class Action;

class Inventory;

class Start_Scene : public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;

private:
    void LoadSounds();
    void LoadBackground();
    void LoadButtons();
};

