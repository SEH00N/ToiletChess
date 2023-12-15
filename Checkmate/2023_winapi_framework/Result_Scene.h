#pragma once
#include "Scene.h"
class Result_Scene : public Scene
{
public:
    virtual void Init() override;

private:
    void LoadBackground();
    void LoadTopPanel();
    void LoadBottomPanel();
    void LoadButtons();
};

