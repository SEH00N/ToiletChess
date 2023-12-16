#pragma once
#include "Scene.h"

class Inventory;
class ToiletBoard;

class Game_Scene : public Scene
{
public:
    virtual void Init() override;

public:
    void LoadSounds();
    void LoadBackground();
    void LoadButtons();
    void LoadTopPanel();
    void InitInventory();

private:
    Inventory* inven1;
    Inventory* inven2;
    ToiletBoard* board;
};

