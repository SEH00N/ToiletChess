#pragma once
#include "Interface.h"

class WareImage;

class WareInventorySlot :
    public Interface
{
public:
    WareInventorySlot(Vec2 pos, Vec2 scale, wstring texName);

public:
    void SetWare(WareImage* ware) { this->ware = ware; }
    WareImage* GetWare() { return ware; }

private:
    WareImage* ware;
};

