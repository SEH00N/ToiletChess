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
    void SetWare(Texture* tex, int confidence, int height);
    void CheckSide();
    void CheckFront();

public:
    bool CheckSide(WareSlot* other) { return confidence > other->confidence; }
    bool CheckFront(WareSlot* other) { return height > other->height; }
    

public:
    void ResetSlot();

public:
    void SetID(int line, int index) { this->line = line; this->index = index; }
    int GetLine() { return line; }
    int GetIndex() { return index; }

private:
    int index;
    int line;
    int confidence;
    int height;

private:
    Texture* wareTex;
};

