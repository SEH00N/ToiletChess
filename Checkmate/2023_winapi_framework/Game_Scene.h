#pragma once
#include "Scene.h"

class Inventory;

class Game_Scene :
    public Scene
{
public:
    virtual void Init() override;

public:
    void LoadBackground();
    void InitInventory();

private:
    Inventory* inven1;
    Inventory* inven2;
};

