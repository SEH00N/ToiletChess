#pragma once
#include "Interface.h"

class WareImage;

class WareSlot :
    public Interface
{
public:
    WareSlot(Vec2 pos, Vec2 scale, wstring texName);

public:
    void Render(HDC hDC) override;

public:
    void OnMouseEnter() override;
    void OnMouseExit() override;

public:
    void SetWare(WareImage* ware);

public:
    void SetID(int line, int index) { this->line = line; this->index = index; }
    int GetLine() { return line; }
    int GetIndex() { return index; }

private:
    int index;
    int line;

private:
    Texture* wareTex;
};

