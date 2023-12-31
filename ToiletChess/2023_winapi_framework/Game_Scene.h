#pragma once
#include "Scene.h"

class WareBase;

class Game_Scene :
    public Scene
{
public:
    virtual void Init() override;

private:
    std::vector<WareBase*> inven1;
    std::vector<WareBase*> inven2;
    std::vector<WareBase*>* currentInven;

private:
    void CreateWare(std::vector<WareBase*>& inven, Vec2 scale);
    void SetInven(std::vector<WareBase*>& inven);

private:
    void CreateUrinal(Vec2 startPos, Vec2 scale, float factor, int count);
};

