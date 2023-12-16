#pragma once
#include "Scene.h"
class Result_Scene : public Scene
{
public:
    virtual void Init() override;
    virtual void Release() override;

private:
    void LoadSounds();
    void LoadBackground();
    void LoadTopPanel();
    void LoadBottomPanel();
    void LoadButtons();
};

