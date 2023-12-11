#pragma once
#include "Interface.h"
class WareSlot :
    public Interface
{
public:
    WareSlot(Vec2 pos, Vec2 scale, wstring texName);

public:
    void OnMouseEnter() override;
    void OnMouseExit() override;

public:
    void SetID(int line, int index) { this->line = line; this->index = index; }
    int GetLine() { return line; }
    int GetIndex() { return index; }

private:
    int index;
    int line;
};

