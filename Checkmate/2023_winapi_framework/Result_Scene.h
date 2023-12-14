#pragma once
#include "Scene.h"
class Result_Scene : public Scene
{
public:
    virtual void Init() override;

private:
    void LoadPanels();
    void LoadButtons();
};

