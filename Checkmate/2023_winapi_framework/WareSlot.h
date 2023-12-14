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
    bool SetWare(WareImage* ware);
    bool SetWare(Texture* tex, int confidence, int height, int owner);
    bool CheckSide();
    bool CheckFront();

public:
    bool CheckSide(WareSlot* other);// { return confidence > other->confidence; }
    bool CheckFront(WareSlot* other);// { return height > other->height; }
    bool CheckSide(int confidence) { return this->confidence > confidence; }
    bool CheckFront(int height) { return this->height > height; }
    bool IsEmpty() { return (wareTex == nullptr); }

public:
    void ResetSlot();

public:
    void SetID(int line, int index) { this->line = line; this->index = index; }
    int GetLine() { return line; }
    int GetIndex() { return index; }
    int GetOwner() { return owner; }
    int GetConfidence() { return confidence; }
    int GetHeight() { return height; }

private:
    int index;
    int line;
    int confidence;
    int height;
    int owner;

private:
    Texture* wareTex;
};

